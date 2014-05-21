
#include "Servo.h"
#include "Rudder.h"

const int rudderServoPin = 5;

Rudder R;

void setup() {
	Serial.begin(9600);
	R.Init(rudderServoPin);
}

void loop() 
{
	R.position(-45);
	// R.center();
	// delay(2000);
	// R.position(20);
	// delay(500);

	Serial.println(R.readPosition());
}



