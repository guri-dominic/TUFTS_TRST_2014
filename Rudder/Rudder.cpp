#include "Arduino.h"
#include "Rudder.h"
#include "Servo.h"
#include "RudderGlobals.h"

Servo rudder;

Rudder::Rudder()
{
	currentPosition = 0;
}


void Rudder::Init(int rudderArduinoPin)
{
	rudder.attach(rudderArduinoPin);
	currentPosition = 0;
	position(currentPosition);
}


// Right => Positive
// Left => Left
boolean Rudder::position(int pos)
{
	// Center at 90deg
	// Check for Range
	// Position abs() < 35
	if(abs(pos) >= RUDDER_MAX)
	{
		;
	}
	// if pos > 0 go right
	boolean goRight = (pos > 0);
	if (goRight)
	{
		rudder.write(90 - pos);
	}
	// if pos < 0 go left
	else
	{
		rudder.write(90 + abs(pos));
	}
}


// Sign + => Right
// (-) => Left
int Rudder::readPosition()
{
	return rudder.read();
}