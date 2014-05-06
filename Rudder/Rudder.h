/*
	Dominic Guri
	Rudder.cpp
	C++/Arduino Class for rudder control for TRST
	=> Uses Servos 
*/
#ifndef Rudder_H
#define Rudder_H
#define RUDDER_MAX 35


class Rudder 
{
public:
	Rudder();
	void Init(int rudderArduinoPin);
	boolean position(int pos);
	int readPosition();
private:
	int currentPosition;
};

#endif

/*
Reference:
http://provideyourown.com/2011/advanced-arduino-including-multiple-libraries/

*/