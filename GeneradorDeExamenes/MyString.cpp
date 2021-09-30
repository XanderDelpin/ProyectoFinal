#include "MyString.h"


// Constructors and Destructor

MyString::MyString(const char* s)
{
	*this = s;
}

MyString::MyString(char ch)
{
	*this = ch;
}

MyString::MyString(const MyString& aString)
{
	*this = aString;
}

MyString::~MyString()
{

}

//---------------------------------------------------------

MyString& MyString::operator=(const MyString& aString)
{
	strcpy_s(this->s, MAX_LEN + 1, aString.s);
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	strcpy_s(this->s, MAX_LEN + 1, s);
	return *this;
}

MyString& MyString::operator=(char ch)
{
	*this = "";
	*this = *this + ch;
	return *this;
}

//---------------------------------------------------------

void MyString::setS(const char* s)
{
	strcpy_s(this->s, MAX_LEN + 1, s);
}

const char* MyString::getS() const
{
	return this->s;
}

//---------------------------------------------------------

MyString MyString::operator+(const MyString& aString) const
{
	return *this + aString.s;
}

MyString MyString::operator+(const char* s) const
{
	MyString r(*this);
	strcat_s(r.s, MAX_LEN + 1, s);
	return r;
}

MyString MyString::operator+(char ch) const
{
	MyString r(*this);
	if ((this->len() + 1) <= MAX_LEN) {
		r.s[this->len()] = ch;
		r.s[this->len() + 1] = '\0';
	}
	return r;
}

MyString operator+(const char* s, const MyString& aString)
{
	return MyString(s) + aString;
}

MyString operator+(char ch, const MyString& aString)
{
	return MyString(ch) + aString;
}

//---------------------------------------------------------

bool MyString::operator==(const MyString& aString) const
{
	return (strcmp(this->s, aString.s) == 0);
}

bool MyString::operator==(const char* s) const
{
	return (strcmp(this->s, s) == 0);
}

bool operator==(const char* s, const MyString aString)
{
	return (strcmp(s, aString.s) == 0);
}

//---------------------------------------------------------

bool MyString::operator!=(const MyString& aString) const
{
	return (strcmp(this->s, aString.s) != 0);
}

bool MyString::operator!=(const char* s) const
{
	return (strcmp(this->s, s) != 0);
}

bool operator!=(const char* s, const MyString aString)
{
	return (strcmp(s, aString.s) != 0);
}

//---------------------------------------------------------

bool MyString::operator>(const MyString& aString) const
{
	return (strcmp(this->s, aString.s) > 0);
}

bool MyString::operator>(const char* s) const
{
	return (strcmp(this->s, s) > 0);
}

bool operator>(const char* s, const MyString aString)
{
	return (strcmp(s, aString.s) > 0);
}

//---------------------------------------------------------

bool MyString::operator<(const MyString& aString) const
{
	return (strcmp(this->s, aString.s) < 0);
}

bool MyString::operator<(const char* s) const
{
	return (strcmp(this->s, s) < 0);
}

bool operator<(const char* s, const MyString aString)
{
	return (strcmp(s, aString.s) < 0);
}

//---------------------------------------------------------

const char& MyString::operator[](int index) const
{
	return this->s[index];
}

char& MyString::operator[](int index)
{
	return this->s[index];
}

ostream& operator<<(ostream& out, const MyString& aString)
{
	out << aString.s;
	return out;
}

istream& operator>>(istream& in, MyString& aString)
{
	char ch;
	aString = "";
	ch = in.get();
	while (ch == '\n') {
		ch = in.get();
	}
	while (ch != '\n') {
		aString = aString + ch;
		ch = in.get();
	}
	return in;
}

//---------------------------------------------------------

MyString MyString::trimLeadingSpaces() const
{
	MyString r;
	int i;
	for (i = 0; (this->s)[i] == '\t' || this->s[i] == ' '; i++);
	for (; i < this->len(); i++) {
		r = r + (this->s)[i];
	}
	return r;
}

MyString MyString::trimEndingSpaces() const
{
	MyString r;
	int i;
	for (i = this->len() - 1; (this->s)[i] == '\t' || this->s[i] == ' '; i--);
	for (; i > 0; i--) {
		r = (this->s)[i] + r;
	}
	return r;
}

MyString MyString::trimAllSpaces() const
{
	MyString r;
	for (int i = 0; this->len(); i++) {
		if ((this->s[i] == '\t') || (this->s[i] == ' '))
			r = r + this->s[i];
	}
	return r;
}

//---------------------------------------------------------

MyString MyString::toUpperCase() const
{
	MyString r(*this);
	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] >= 'a' && this->s[i] <= 'z') {
			r.s[i] = this->s[i] - 32;
		}
	}
	return r;
}

MyString MyString::toLowerCase() const
{
	MyString r(*this);
	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] >= 'A' && this->s[i] <= 'Z') {
			r.s[i] = this->s[i] + 32;
		}
	}
	return r;
}

MyString MyString::createSubstring(int from, int to) const
{
	MyString r;
	if (from > 0 && to < this->len()) {
		for (int i = from; i <= to; i++) {
			r = r + this->s[i];
		}
	}
	return r;
}

//---------------------------------------------------------

int MyString::len() const
{
	return strlen(this->s);
}

bool MyString::isEmpty() const
{
	return this->len() == 0;
}

MyString MyString::reverse() const
{
	MyString r(*this);
	char ch;
	for (int i = 0, j = this->len(); i < j; i++, j--) {
		ch = r.s[i];
		r.s[i] = r.s[j];
		r.s[j] = ch;
	}
	return r;
}

int MyString::indexOf(char ch) const
{
	int index = -1;
	for (int i = 0; i < this->len() && index == -1; i++) {
		if (this->s[i] == ch) {
			index = i;
		}
	}
	return index;
}

int MyString::indexOfLast(char ch) const
{
	int index = -1;
	for (int i = this->len() - 1; i > 0 && index == -1; i--) {
		if (this->s[i] == ch) {
			index = i;
		}
	}
	return index;
}

bool MyString::include(char ch) const
{
	bool found = false;
	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] == ch) {
			found = true;
		}
	}
	return found;
}

int MyString::frequency(char ch) const
{
	int counter = 0;
	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] == ch) {
			counter++;
		}
	}
	return counter;
}

//---------------------------------------------------------

bool MyString::representAnUnsignInteger() const
{
	bool represent = true;
	for (int i = 0; i < this->len() && represent; i++) {
		if (this->s[i] < '0' || this->s[i] > '9') {
			represent = false;
		}
	}
	return (represent && this->len() > 0);
}

bool MyString::representAnInteger() const
{
	MyString r(*this);
	if (this->s[0] == '+' || this->s[0] == '-') {
		r = this->createSubstring(1, this->len() - 1);
	}
	return r.representAnUnsignInteger();
}

bool MyString::representAReal() const
{
	int point = this->indexOf('.');
	MyString prefix, sufix;
	bool valid;
	if (point != -1) {
		prefix = this->createSubstring(0, point - 1);
		sufix = this->createSubstring(point + 1, this->len() - 1);
		valid = prefix.representAnInteger() && sufix.representAnUnsignInteger();
	}
	else { valid = this->representAnInteger(); }

	return valid;
}

//---------------------------------------------------------

int MyString::maxLen()
{
	return MAX_LEN;
}

//---------------------------------------------------------

MyString& MyString::operator+=(const MyString& aString)
{
	return *this = *this + aString;
}

MyString& MyString::operator+=(const char* s)
{
	return *this = *this + s;
}

MyString& MyString::operator+=(char ch)
{
	return *this = *this + ch;
}

//---------------------------------------------------------

MyString& MyString::operator++()
{
	return *this = this->toUpperCase();
}

MyString MyString::operator++(int)
{
	MyString r(*this);
	*this = this->toUpperCase();
	return *this;
}

//---------------------------------------------------------

MyString& MyString::operator--()
{
	return *this = this->toLowerCase();
}

MyString MyString::operator--(int)
{
	MyString r(*this);
	*this = this->toLowerCase();
	return *this;
}

//---------------------------------------------------------

