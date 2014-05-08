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
boolean Sails::position(int pos)
{
	// Center at 90deg
	// Check for Range
	
	sails.write(pos);
}


// Sign + => Right
// (-) => Left
int Sails::readPosition()
{
	return sails.read();
}


void Sails::fullTrim()
{
	sails.write(SAILS_MAX);
}