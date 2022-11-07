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
	
	//Добавить пользователя
	void AddUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Удалить пользователя
	void DeleteUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Редактировать пользователя
	void EditUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Добавить категорию
	void AddCategory(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Добавить тест
	void AddTest(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Сохранить категории в файл
	void SaveCategoriesToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Достать категории из файла
	void ReadCategoriesFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Сохранить тесты в файл
	void SaveTestsToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Достать тесты из файла
	void ReadTestsFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Проверка на наличие нужной категории (при создании теста)
	bool CategoryCheck(string _TestCategory);
	
	//Достать логин
	string GetLogin();
	
	//Достать пароль
	string GetPassword();
	
	//Сохраняет данные админа в бинарный файл
	void SaveLoginPasswordToFile();
	
	//Достать из файла результаты конкретного пользователя
	void PrintUserResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
	
	//Достать из файла результаты всех пользователей
	void PrintAllResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests);
};

