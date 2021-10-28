#include "MyDate.h"

MyDate::MyDate(int month, int day, int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

MyDate::MyDate(const MyDate& aDate)
{
	this->month = aDate.month;
	this->day = aDate.day;
	this->year = aDate.year;
}

MyDate::~MyDate()
{

}

void MyDate::setDay(int day)
{
	this->day = day;
}

void MyDate::setMonth(int month)
{
	this->month = month;
}

void MyDate::setYear(int year)
{
	this->year = year;
}

int MyDate::getDay() const
{
	return this->day;
}

int MyDate::getMonth() const
{
	return this->month;
}

int MyDate::getYear() const
{
	return this->year;
}
void MyDate::askDay()
{
	bool validFeb, valid30, valid31;
	cout << "Enter a day: ";
	cin >> this->day;
	validFeb = ((this->month == 2) && 
		((this->isLeapYear() && this->day <= 29) 
		|| (!(this->isLeapYear()) && this->day <= 28)) 
		&& (this->day > 0));
	valid30 = ((this->month != 2) 
		&& ((this->month % 2 == 0 && this->month >= 6) 
		|| (this->month % 2 != 0 && this->month <= 9))
		&& (this->day > 0 && this->day <= 30));
	valid31 = ((this->month != 2)
		&& ((this->month % 2 == 0 && this->month >= 8)
		|| (this->month % 2 != 0 && this->month <= 7))
		&& (this->day > 0 && this->day <= 31));

	while (!validFeb && !valid30 && !valid31) {
		cout << "Error: Invalid Value" << endl << endl;
		cout << "Enter a day: ";
		cin >> this->day;

		validFeb = ((this->month == 2) &&
			((this->isLeapYear() && this->day <= 29)
				|| (!(this->isLeapYear()) && this->day <= 28))
			&& (this->day > 0));
		valid30 = ((this->month != 2)
			&& ((this->month % 2 == 0 && this->month >= 6)
				|| (this->month % 2 != 0 && this->month <= 9))
			&& (this->day > 0 && this->day <= 30));
		valid31 = ((this->month != 2)
			&& ((this->month % 2 == 0 && this->month >= 8)
				|| (this->month % 2 != 0 && this->month <= 7))
			&& (this->day > 0 && this->day <= 31));
	}

}

void MyDate::askMonth()
{
	cout << "Enter month: ";
	cin >> this->month;
	while (this->month < 1 || this->month > 12) {
		cout << "Error: Invalid Value" << endl << endl;
		cout << "Enter a month: ";
		cin >> this->month;
	}
}

void MyDate::askYear()
{
	char d;
	cout << "Enter the year: ";
	cin >> this->year;

	while (this->year <= 0) {
		cout << "Error: Invalid Value" << endl << endl;
		cout << "Enter a year: ";
		cin >> this->year;
	}
	cout << "Press '1' if it's AC, otherwise press any number for BC: ";
	cin >> d;
	if (d != '1')
		this->setBC();

}

void MyDate::showDay() const
{
	cout << this->day;
}

void MyDate::showMonth() const
{
	cout << this->month;
}

void MyDate::showYear() const
{
	cout << ((this->isAC()) ? this->year : -(this->year))
		<< ((this->isAC()) ? " " : "BC");
}

void MyDate::showDate() const
{
	cout << this->month << '/' << this->day << '/' 
		<< ((this->isAC()) ? this->year : -(this->year))
		<< ((this->isAC()) ? " " : " BC");
}

void MyDate::setAC()
{
	if (this->year < 0)
		this->year *= -1;
}

void MyDate::setBC()
{
	if (this->year > 0)
		this->year *= -1;
}

bool MyDate::isAC() const
{
	return this->year > 0;
}

bool MyDate::isBC() const
{
	return this->year < 0;
}

bool MyDate::isLeapYear() const
{
	return ((this->year % 400 == 0) || (this->year %100 != 0 && this->year % 4 == 0));

}

void MyDate::askDate()
{
	this->askYear();
	this->askMonth();
	this->askDay();
}

MyDate& MyDate::operator=(const MyDate& aDate)
{
	this->month = aDate.month;
	this->day = aDate.day;
	this->year = aDate.year;
	return *this;
}

bool MyDate::operator==(const MyDate& aDate) const
{
	return (this->day == aDate.day && this->month == aDate.month && this->year == aDate.year);
}

bool MyDate::operator!=(const MyDate& aDate) const
{
	return (!(*this == aDate));
}

bool MyDate::operator>(const MyDate& aDate) const
{
	return ((this->year > aDate.year) 
		|| (this->year == aDate.year && this->month > aDate.month) 
		|| (this->year == aDate.year && this->month == aDate.month && this->day > aDate.day));
}

bool MyDate::operator<(const MyDate& aDate) const
{
	return (!(*this > aDate)) && (!(*this == aDate));
}

ostream& operator<<(ostream& out, const MyDate& aDate)
{
	aDate.showDate();
	return out;
}

istream& operator>>(istream& in, MyDate& aDate)
{
	aDate.askDate();
	return in;
}
