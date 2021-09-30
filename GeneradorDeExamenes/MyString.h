#pragma once
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 80;

class MyString
{

private:

	char s[MAX_LEN + 1];

public:

	MyString(const char* s = "");
	MyString(char ch);
	MyString(const MyString& aString);

	~MyString();

	//--------------------------------------------------------
	//OPERATOR=

	MyString& operator=(const MyString& aString);
	MyString& operator=(const char* s);
	MyString& operator=(char ch);

	//--------------------------------------------------------
	//Setters and Getters

	void setS(const char* s);
	const char* getS() const;

	//--------------------------------------------------------
	//OPERATOR+ (Concatenate)

	MyString operator+(const MyString& aString) const;
	MyString operator+(const char* s) const;
	MyString operator+ (char ch) const;
	friend MyString operator+(const char* s, const MyString& aString);
	friend MyString operator+(char ch, const MyString& aString);

	//--------------------------------------------------------
	//BOOL OPERATORS

	bool operator==(const MyString& aString) const;
	bool operator==(const char* s) const;
	friend bool operator==(const char* s, const MyString aString);

	bool operator!=(const MyString& aString) const;
	bool operator!=(const char* s) const;
	friend bool operator!=(const char* s, const MyString aString);

	bool operator>(const MyString& aString) const;
	bool operator>(const char* s) const;
	friend bool operator>(const char* s, const MyString aString);

	bool operator<(const MyString& aString) const;
	bool operator<(const char* s) const;
	friend bool operator<(const char* s, const MyString aString);

	//--------------------------------------------------------
	//[]OPERATOR and COUT / CIN

	const char& operator[](int index) const; //Get a char
	char& operator[](int index); //Set a char

	friend ostream& operator<<(ostream& out, const MyString& aString);
	friend istream& operator>>(istream& in, MyString& aString);

	//--------------------------------------------------------
	//Other Services

	MyString trimLeadingSpaces() const;
	MyString trimEndingSpaces() const;
	MyString trimAllSpaces() const;

	MyString toUpperCase() const;
	MyString toLowerCase() const;

	MyString createSubstring(int from, int to) const;

	int len() const;
	bool isEmpty() const;

	MyString reverse() const;

	int indexOf(char ch) const;
	int indexOfLast(char ch) const;
	bool include(char ch) const;
	int frequency(char ch) const;

	bool representAnUnsignInteger() const;
	bool representAnInteger() const;
	bool representAReal() const;

	static int maxLen();

	MyString& operator+=(const MyString& aString);
	MyString& operator+=(const char* s);
	MyString& operator+=(char ch);

	MyString& operator++();
	MyString operator++(int);

	MyString& operator--();
	MyString operator--(int);


};
