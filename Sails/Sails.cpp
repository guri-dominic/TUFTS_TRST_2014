#include "Arduino.h"
#include "Sails.h"
#include "Servo.h"

Servo sails;

Sails::Sails()
{
	currentPosition = 0;
}


void Sails::Init(int sailsArduinoPin)
{
	sails.attach(sailsArduinoPin);
	currentPosition = 0;
	position(currentPosition);
}


// Right => Positive
// Left => Left
void Sails::position(int pos)
{
	// Center at 90deg
	// Check for Range
	
	sails.writeMicroseconds(pos);
}

void Sails::sailsForAngle(int windDirToTargetAngle)
{
	int dir = workingSailPositioningAngle(windDirToTargetAngle);
	positionSails(dir);
}

int Sails::workingSailPositioningAngle(int windDirToTargetAngle)
{
	int angle = abs(windDirToTargetAngle);

	if (angle > 180)
	{
		angle %= 360;
		angle = 360 - angle;
	}

	// Serial.print(windDirToTargetAngle);
	return angle;
}

void Sails::positionSails(int angle)
{	
	int servoAngle = 0;
	int sailPos = 0;
	int deltAngle = 0;

	if (angle < 40)
	{
		servoAngle = SERVO_FULL_PULL_IN;
		sails.writeMicroseconds(servoAngle);
	} 
	else
	{
		// position of sails with [0 @ NO_GO_ZONE]
		sailPos = map(angle, NO_GO_ZONE, 180, 0, NUMBER_OF_SAIL_POS);
		// angle between consequetive sail positions 
		deltAngle = (abs(SERVO_FULL_TRIM - SERVO_FULL_PULL_IN)) / NUMBER_OF_SAIL_POS;
		// servo angle for sails
		servoAngle = SERVO_FULL_PULL_IN - deltAngle * sailPos;
		// write angle to servo

		sails.writeMicroseconds(servoAngle);
	}

	// Serial.print(test_angle); 
	Serial.print(", ");
	Serial.print(angle); Serial.print(", ");
	Serial.println(servoAngle);
}


// Sign + => Right
// (-) => Left
int Sails::readPosition()
{
	return sails.read();
}


void Sails::fullTrim()
{
	sails.writeMicroseconds(SERVO_FULL_TRIM);
}