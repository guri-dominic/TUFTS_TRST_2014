
#include "Servo.h"
#include "Sails.h"

const int sailServoPin = 5;

Sails  S;


void setup() 
{
	Serial.begin(9600);
	S.Init(sailServoPin);
	S.position(SERVO_FULL_TRIM);
	delay(500);
}

void loop() 
{
	delay(5000);
	S.position(SERVO_FULL_PULL_IN);
	Serial.println(S.readPosition());
}

