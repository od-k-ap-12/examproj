#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Test.h"
using namespace std;

class Test;

class User
{
	string Login;
	string Password;
	string FirstName;
	string LastName;
	string Address;
	string PhoneNumber;
public:
	User(string _Login, string _Password, string _FirstName, string _LastName, string _Address, string _PhoneNumber);
	User(string _Login, string _Password);
	void PrintResults();
	void PassTest(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);
	string GetLogin();
	string GetPassword();
	void SetUser(string _Login, string _Password, string _FirstName, string _LastName, string _Address, string _PhoneNumber);
	void SaveUserToFile();
	void SaveResult(string TestTitle, int Result);
};

