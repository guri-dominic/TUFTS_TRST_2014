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

void Rudder::center()
{
	// rudder.write(CENTER);
	rudder.writeMicroseconds(MS_CENTER);
}


// Right => Positive
// Left => Left
void Rudder::position(int pos)
{
	// Center at 90deg
	// Check for Range
	// Position abs() < 35
	pos = constrain(pos, (-1 * RUDDER_MAX), RUDDER_MAX);
	int ms_pos = map(abs(pos), 0, RUDDER_MAX, 0, abs(MS_CENTER - MS_RUDDER_MAX));
	// if pos > 0 go right
	boolean goRight = (pos >= 0);
	// convert to microseconds
	if (goRight)
	{
		// rudder.write(CENTER + abs(pos));
		rudder.writeMicroseconds(MS_CENTER + ms_pos);
	}
	// if pos < 0 go left
	else
	{
		// rudder.write(CENTER - abs(pos));
		rudder.writeMicroseconds(MS_CENTER - ms_pos);
	}
}




// Sign + => Right
// (-) => Left
int Rudder::readPosition()
{
	return rudder.read();
}