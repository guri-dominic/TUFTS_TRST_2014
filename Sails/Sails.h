
#ifndef Sails_H
#define Sails_H

#define SAILS_MIN 60
#define NO_GO_ZONE 45
#define NUMBER_OF_SAIL_POS 6	// btwn NO_GO_ZONE & 180
#define SERVO_FULL_TRIM 860
#define SERVO_FULL_PULL_IN 1665


class Sails 
{
public:
	Sails();
	void Init(int sailsArduinoPin);
	void position(int pos);
	void fullTrim();
	void sailsForAngle(int windDirToTargetAngle);
	int readPosition();
	
private:
	int currentPosition;
	int workingSailPositioningAngle(int windDirToTargetAngle);
	void positionSails(int angle);
};

#endif

/*
Reference:
http://provideyourown.com/2011/advanced-arduino-including-multiple-libraries/

*/
