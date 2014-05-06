
#include "Servo.h"
#include "Rudder.h"

Rudder R;

void setup() {
	Serial.begin(9600);
	R.Init(9);
}

void loop() {
R.position(20);
delay(500);
R.position(-20);
delay(500);

Serial.println(R.readPosition());
}



