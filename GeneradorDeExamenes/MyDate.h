#pragma once
#include<iostream>
using namespace std;

class MyDate
{
	private:

		int day, month, year;

		void askDay();
		void askMonth();
		void askYear();

	public:

		//--------------------------------------------------
		//Constrcutor and Desctructor

		MyDate(int month = 1, int day = 1, int year = 1);
		MyDate(const MyDate& aDate);
		~MyDate();

		//--------------------------------------------------
		//Setters and Getters

		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);

		int getDay() const;
		int getMonth() const;
		int getYear() const;

		//--------------------------------------------------
		//Other Services

		void showDay() const;
		void showMonth() const;
		void showYear() const;
		void showDate() const;

		void setAC();
		void setBC();

		bool isAC() const;
		bool isBC() const;
		bool isLeapYear() const;

		void askDate();

		//--------------------------------------------------
		//Operators

		MyDate& operator=(const MyDate& aDate);

		bool operator==(const MyDate& aDate) const;
		bool operator!=(const MyDate& aDate) const;
		bool operator>(const MyDate& aDate) const;
		bool operator<(const MyDate& aDate) const;

		//--------------------------------------------------
		//Friends

		friend ostream& operator<<(ostream& out, const MyDate& aDate);
		friend istream& operator>>(istream& in, MyDate& aDate);






};

