

#ifndef Sails_H
#define Sails_H
#define SAILS_MAX 120
#define SAILS_MIN 60


class Sails 
{
public:
	Sails();
	void Init(int sailsArduinoPin);
	boolean position(int pos);
	int readPosition();
	void fullTrim();
	
private:
	int currentPosition;
};

#endif

/*
Reference:
http://provideyourown.com/2011/advanced-arduino-including-multiple-libraries/

*/
