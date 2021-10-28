#include "MyTime.h"

MyTime::MyTime(int hour, int minutes, int seconds)
{	
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
}

MyTime::MyTime(const MyTime& aTime)
{
	this->seconds = aTime.seconds;
	this->minutes = aTime.minutes;
	this->hour = aTime.hour;
}

MyTime::~MyTime()
{

}

//--------------------------------------------------------------


void MyTime::setSeconds(int seconds)
{
	this->seconds = seconds;
}

void MyTime::setMinutes(int minutes)
{
	this->minutes = minutes;
}

void MyTime::setHour(int hour)
{
	this->hour = hour;
}

int MyTime::getSeconds() const
{
	return this->seconds;
}

int MyTime::getMinutes() const
{
	return this->minutes;
}

int MyTime::getHour() const
{
	return this->hour;
}

//--------------------------------------------------------------


void MyTime::showSeconds() const
{
	cout << this->seconds << " seconds";
}

void MyTime::showMinutes() const
{
	cout << this->minutes << " minutes";
}

void MyTime::showHour() const
{
	cout << ((this->isAM())? this->hour:-(this->hour)) 
		 << ((this->isAM())? " AM":" PM");
}

void MyTime::showTime() const
{
	cout << ((this->isAM()) ? this->hour : -(this->hour))
		<< " : ";
	if (this->minutes < 10) {
		cout << 0;
	}
	cout << this->minutes << " minutes: ";
	if (this->seconds < 10) {
		cout << 0;
	}
	cout << this->seconds << " seconds: " << ((this->isAM()) ? "AM" : "PM");

}

void MyTime::setAM()
{
	if (this->hour < 0)
		this->hour *= -1;
}

void MyTime::setPM()
{
	if (this->hour > 0)
		this->hour *= -1;
}

bool MyTime::isAM() const
{
	return this->hour > 0;
}

bool MyTime::isPM() const
{
	return this->hour < 0;
}

void MyTime::askSeconds()
{
	cout << "Enter the seconds: ";
	cin >> this->seconds;
	while (this->seconds < 0 || this->seconds > 59) {
		cout << "Invalid Value!" << endl << endl;
		cout << "Enter the seconds: ";
		cin >> this->seconds;
	}
}

void MyTime::askMinutes()
{

	cout << "Enter the minutes: ";
	cin >> this->minutes;
	while (this->minutes < 0 || this->minutes > 59) {
		cout << "Invalid Value!" << endl << endl;
		cout << "Enter the minutes: ";
		cin >> this->minutes;
	}
}

void MyTime::askHour()
{
	char d;
	cout << "Enter the hour: ";
	cin >> this->hour;
	while (this->hour < 1 || this->hour > 12) {
		cout << "Invalid Value!" << endl << endl;
		cout << "Enter the hour: ";
		cin >> this->hour;
	}
	cout << endl;
	cout << "Press '1' if AM, anything if otherwise: ";
	cin >> d;
	if (d != '1') {
		this->setPM();
	}
	
}

void MyTime::askTime()
{
	this->askHour();
	this->askMinutes();
	this->askSeconds();
}

//--------------------------------------------------------------


MyTime& MyTime::operator=(const MyTime& aTime)
{
	this->seconds = aTime.seconds;
	this->minutes = aTime.minutes;
	this->hour = aTime.hour;
	return *this;
}

bool MyTime::operator==(const MyTime& aTime) const
{
	return ((this->hour == aTime.hour) 
		&& (this->minutes == aTime.minutes) 
		&& (this->seconds == aTime.seconds));
}

bool MyTime::operator!=(const MyTime& aTime) const
{
	return (!(*this == aTime));
}

bool MyTime::operator>(const MyTime& aTime) const
{
	return (((this->isAM() && aTime.isAM()) ?
		this->hour > aTime.hour:
	-this->hour > -aTime.hour) ||
		(this->hour == aTime.hour &&
			this->minutes > aTime.minutes) ||
		(this->hour == aTime.hour &&
			this->minutes == aTime.minutes &&
			this->seconds > aTime.seconds));
}

bool MyTime::operator<(const MyTime& aTime) const
{
	return (!(*this > aTime || *this == aTime));
}

ostream& operator<<(ostream& out, const MyTime& aTime)
{
	aTime.showTime();
	return out;
}

istream& operator>>(istream& in, MyTime& aTime)
{
	aTime.askTime();
	return in;
}
