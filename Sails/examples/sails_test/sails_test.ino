
#include "Servo.h"
#include "Sails.h"

const int sailServoPin = 9;

Sails  S;


void setup() {
	Serial.begin(9600);
	S.Init(sailServoPin);
}

void loop() {
S.position(SAILS_MAX);
delay(1000);
S.position(SAILS_MIN);
delay(500);

Serial.println(S.readPosition());
}

