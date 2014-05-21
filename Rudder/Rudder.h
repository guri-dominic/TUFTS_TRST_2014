/*
	Dominic Guri
	Rudder.cpp
	C++/Arduino Class for rudder control for TRST
	=> Uses Servos 
*/
#ifndef Rudder_H
#define Rudder_H

#define RUDDER_MAX 45
#define CENTER 90
#define MS_CENTER 1500
#define MS_RUDDER_MAX 1025


class Rudder 
{
public:
	Rudder();
	void Init(int rudderArduinoPin);
	void position(int pos);
	void center();
	int readPosition();
private:
	int currentPosition;
};

#endif

/*
Reference:
http://provideyourown.com/2011/advanced-arduino-including-multiple-libraries/

*/