#pragma once
#include<iostream>
#include<cstring>
	using namespace std;
	const int MAX_LEN = 80;
	class MyString
	{
	private:
		char s[MAX_LEN + 1];//Atribute
	public:
		//Constructor
		MyString(const char* s = "");
		MyString(char ch);
		//Copy constructor
		MyString(const MyString& aMyString);

		~MyString();

		MyString& operator=(const char* s);
		MyString& operator=(char ch);
		MyString& operator=(const MyString& aMyString);

		void setS(const char* s);
		const char* getS()const;

		MyString operator+(const char* s)const;
		MyString operator+(char ch)const;
		MyString operator+(const MyString& aMyString)const;
		friend MyString operator+(const char* s, const MyString& aMyString);

		friend MyString operator+(char ch, const MyString& aMyString);

		bool operator==(const char* s)const;
		bool operator==(const MyString& aMyString)const;
		friend bool operator==(const char* s, const MyString& aMyString);

		bool operator!=(const char* s)const;
		bool operator!=(const MyString& aMyString)const;
		friend bool operator!=(const char* s, const MyString& aMyString);

		bool operator>(const char* s)const;
		bool operator>(const MyString& aMyString)const;
		friend bool operator>(const char* s, const MyString& aMyString);

		bool operator<(const char* s)const;
		bool operator<(const MyString& aMyString)const;
		friend bool operator<(const char* s, const MyString& aMyString);

		//get a character
		const char& operator[](int index)const;

		//set a character
		char& operator[](int index);

		friend istream& operator>>(istream& in, MyString& aMyString);
		friend ostream& operator<<(ostream& out, const MyString& aMyString);

		MyString trimLeadingSpaces()const;
		MyString trimEndingSpaces()const;
		MyString trimAllSpaces()const;

		MyString toUppercase()const;
		MyString toLowercase()const;

		MyString createSubstring(int from, int to)const;

		int len()const;
		bool isEmpty()const;

		MyString reverse()const;

		int indexOf(char ch)const;
		int indexOfLast(char ch)const;
		bool include(char ch)const;
		int frequency(char ch)const;

		bool representAnUnisignInteger()const;
		bool representAnInterger()const;
		bool representAReal()const;

		static int MaxLen();

		MyString& operator+=(const MyString& aMyString);
		MyString& operator+=(const char* s);
		MyString& operator+=(char ch);

		//++objeto->to uppercase
		MyString& operator++();
		//objeto++-> to uppercase
		MyString operator++(int);

		//--objeto ->to uppercase
		MyString& operator--();
		//objeto-- -> to uppercase
		MyString operator--(int);




	};

