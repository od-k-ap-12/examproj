#pragma once
#include <list>
#include "User.h"
#include <iostream>
#include "Admin.h"
#include <vector>
using namespace std;

void TitleScreen(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);
void AdminMenu(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
void UserMenu(list<User*>& Users, User* User, vector<string>& Categories, vector<Test>& Tests);
void SignUp(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);
void SignInAdmin(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
void SignIn(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);
bool UserCheck(string _Login, string _Password, list<User*>& Users);
bool LoginCheck(string _Login, list<User*>& Users);
bool SearchLogin(string _Login, list<User*>& Users);
bool SearchUser(string _Login, string _Password, list<User*>& Users);


