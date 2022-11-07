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
	
	//Посмотреть все свои результаты
	void PrintResults();
	
	//Пройти тест
	void PassTest(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);
	
	//Достать логин
	string GetLogin();
	
	//Достать пароль
	string GetPassword();
	
	//Изменить пользователя
	void SetUser(string _Login, string _Password, string _FirstName, string _LastName, string _Address, string _PhoneNumber);
	
	//Сохранить пользователя в файл
	void SaveUserToFile();
	
	//Сохранить результат (вызывается после каждого проходжения теста)
	void SaveResult(string TestTitle, int Result);
	
	
};

