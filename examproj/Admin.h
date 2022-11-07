#pragma once
#include <string>
#include <iostream>
#include <list>
#include "User.h"
#include <vector>
#include "Test.h"
using namespace std;
class Admin
{
	string Login;
	string Password;
public:
	Admin();
	void AddUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void DeleteUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void EditUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void AddCategory(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void AddTest(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void SaveCategoriesToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void ReadCategoriesFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void SaveTestsToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void ReadTestsFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	bool CategoryCheck(string _TestCategory);
	string GetLogin();
	string GetPassword();
	void SaveLoginPasswordToFile();
	void PrintUserResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	void PrintAllResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
};

