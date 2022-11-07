#pragma once
#include<iostream>
using namespace std;

class Base
{
protected:
	char str[100];
public:
	Base() = default;
	Base(const char* s)
	{
		strcpy_s(str, strlen(s) + 1, s);
	}
	virtual void Print()
	{
		cout << str << endl;
	}

};
class InvalidLoginOrPassword : public Base
{
public:
	InvalidLoginOrPassword() {}
	InvalidLoginOrPassword(const char* s) :Base(s)
	{}
	void Print()
	{
		cout << str << endl;
	}
};
class InvalidCategory : public Base
{
public:
	InvalidCategory() {}
	InvalidCategory(const char* s) :Base(s)
	{}
	void Print()
	{
		cout << str << endl;
	}
};



