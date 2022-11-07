#pragma once
#include <list>
#include "User.h"
#include <iostream>
#include "Admin.h"
#include <vector>
using namespace std;

//Главное меню
void TitleScreen(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);

//Меню админа
void AdminMenu(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);

//Меню пользователя
void UserMenu(list<User*>& Users, User* User, vector<string>& Categories, vector<Test>& Tests);

//Регистрация
void SignUp(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);

//Вход в аккаунт админа
void SignInAdmin(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);

//Вход в аккаунт пользователя
void SignIn(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests);

//Проверка пользователя
bool UserCheck(string _Login, string _Password, list<User*>& Users);

//Проверка на дубликат логина
bool LoginCheck(string _Login, list<User*>& Users);

//Искать логин
bool SearchLogin(string _Login, list<User*>& Users);

//Искать пользователя
bool SearchUser(string _Login, string _Password, list<User*>& Users);


