#include "Admin.h"
#include "Menu.h"
#include <list>
#include "User.h"
#include "Exception.h"
#include <fstream>
#include "Test.h"
#include <vector>
#include <conio.h>

Admin::Admin()
{
	Login = "login";
	Password = "password";
	SaveLoginPasswordToFile();
}

void Admin::AddUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	User* NewUser = nullptr;
	cout << "1.Вернутся в меню\n2.Добавить нового пользователя\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	case 2:
		string Login, Password, FirstName, LastName, Address, PhoneNumber;
		cout << "Введите имя: " << endl;
		cin >> FirstName;
		cout << "Введите фамилию: " << endl;
		cin >> LastName;
		cout << "Введите адрес: " << endl;
		cin >> Address;
		cout << "Введите номер телефона: " << endl;
		cin >> PhoneNumber;
		cout << "Введите логин: " << endl;
		cin >> Login;
		cout << "Введите пароль: " << endl;
		cin >> Password;
		if (LoginCheck(Login, Users) == true) {
			NewUser = new User(Login, Password, FirstName, LastName, Address, PhoneNumber);
			Users.push_back(NewUser);
			cout << "Новый пользователь успешно создан.";
			system("pause");
			AdminMenu(Users, Admin, Categories, Tests);
		}
		else {
			AddUser(Users, Admin, Categories, Tests);
		}
	}
}

void Admin::DeleteUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{

	system("cls");
	string Login;
	string Password;
	cout << "1.Вернутся в меню\n2.Удалить пользователя\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	case 2:
		try {
			cout << "Введите логин: " << endl;
			cin >> Login;
			if (SearchLogin(Login, Users) == true) {
				vector<string> Logins;
				string LoginPath = "D:\\testingsystem\\logins.txt";
				ifstream File;
				string InFileLogin;
				File.open(LoginPath);
				int i = 0;
				while (getline(File, InFileLogin))
				{
					Logins[i] = InFileLogin;
					i++;
				}
				for (auto it = Logins.begin(); it != Logins.end(); it++) {
					if ((*it) == Login) {
						Logins.erase(it);
					}
				}
				ofstream File1;
				File1.open(LoginPath);
				for (auto it = Logins.begin(); it != Logins.end(); it++) {
					File1 << (*it);
				}
				File.close();
				cout << "Пользователь успешно удалён." << endl;
				system("pause");
				AdminMenu(Users, Admin, Categories, Tests);

			}
			else {
				throw new InvalidLoginOrPassword("Такого пользователя не существует!");

			}
		}
		catch (Base* b)
		{
			b->Print();
			system("pause");
			DeleteUser(Users, Admin, Categories, Tests);
		}
	}
}

void Admin::EditUser(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	string Login;
	string Password;
	cout << "1.Вернутся в меню\n2.Редактировать пользователя\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	case 2:
		try {
			cout << "Введите логин: " << endl;
			cin >> Login;
			if (SearchLogin(Login, Users) == true) {
				string Login, Password, FirstName, LastName, Address, PhoneNumber;
				cout << "Введите имя: " << endl;
				cin >> FirstName;
				cout << "Введите фамилию: " << endl;
				cin >> LastName;
				cout << "Введите адрес: " << endl;
				cin >> Address;
				cout << "Введите номер телефона: " << endl;
				cin >> PhoneNumber;
				cout << "Введите логин: " << endl;
				cin >> Login;
				cout << "Введите пароль: " << endl;
				cin >> Password;
				User* NewUser = new User(Login, Password, FirstName, LastName, Address, PhoneNumber);
				NewUser->SaveUserToFile();
				cout << "Сохранено" << endl;
				system("pause");
			}
			else {
				throw new InvalidLoginOrPassword("Такого пользователя не существует!");

			}
		}
		catch (Base* b)
		{
			b->Print();
			DeleteUser(Users, Admin, Categories, Tests);
		}
	}
}

void Admin::AddCategory(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	cout << "1.Вернутся в меню\n2.Создать категорию\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	case 2: {
		string NewCategory;
		cout << "Введите категорию теста: " << endl;
		cin >> NewCategory;
		Categories.push_back(NewCategory);
		cout << "Новая категория успешно создана";
		ofstream File;
		File.open("D:\\testingsystem\\tests\\categories.txt", ios::app);
		File << endl;
		File << NewCategory;
		File.close();
		system("pause");
		AdminMenu(Users, Admin, Categories, Tests);
	}
	default:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	}
}

void Admin::AddTest(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	cout << "1.Вернутся в меню\n2.Создать тест\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	case 2: {
		string TestCategory;
		string TestTitle;
		array<string, 6> Questions;
		array<string, 6> Answers;
		try {
			cout << "Введите категорию теста: ";
			cin >> TestCategory;
			if (CategoryCheck(TestCategory) == 0) {
				throw new InvalidCategory("Такой категории не существует!");
			}
		}
		catch (Base* b)
		{
			b->Print();
			system("pause");
			AddTest(Users, Admin, Categories, Tests);
		}
		cout << "Введите название теста: ";
		cin >> TestTitle;
		for (int i = 0; i < 6; i++) {
			cout << "Введите вопрос " << i + 1;
			cin >> Questions[i];
			cout << "Введите ответ: ";
			cin >> Answers[i];
		}
		cout << endl;
		Test NewTest(TestCategory, TestTitle, Questions, Answers);
		NewTest.SaveTestToFile();
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	}
	default:
		AdminMenu(Users, Admin, Categories, Tests);
		break;

	}
}

void Admin::SaveCategoriesToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	ofstream File;
	File.open("D:\\testingsystem\\tests\\categories.txt", ios::trunc);
	int i = 1;
	for (auto it = Categories.begin(); it != Categories.end(); it++)
	{
		File << *it;
		File << endl;
	}
	File.close();
	cout << "Сохранено";
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}

void Admin::ReadCategoriesFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	string Category;
	ifstream File;
	File.open("D:\\testingsystem\\tests\\categories.txt");
	while (getline(File, Category))
	{
		cout << Category;
	}
	File.close();
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}

void Admin::SaveTestsToFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	for (auto it = Tests.begin(); it < Tests.end(); it++) {
		(*it).SaveTestToFile();
	}
	cout << "Сохранено";
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}

void Admin::ReadTestsFromFile(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	for (auto it = Tests.begin(); it < Tests.end(); it++) {
		(*it).ReadTestFromFile();
	}
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}

bool Admin::CategoryCheck(string _TestCategory)
{
	bool result = false;
	string Category;
	ifstream File;
	File.open("D:\\testingsystem\\tests\\categories.txt");
	while (getline(File, Category))
	{
		if (Category == _TestCategory)
			File.close();
		result = true;
		return true;
	}
	if (!result) {
		File.close();
		return false;
	}
}

string Admin::GetLogin()
{
	return Login;
}

string Admin::GetPassword()
{
	return Password;
}

void Admin::SaveLoginPasswordToFile()
{
	ofstream File("D:\\testingsystem\\admin.bin", ios::binary);
	File.write((char*)&Login, size(Login));
	File.write((char*)&Password, size(Password));
	File.close();
}

void Admin::PrintUserResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	string Login;
	cout << "Введите логин: ";
	cin >> Login;
	User User(Login, "0");
	User.PrintResults();
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}

void Admin::PrintAllResults(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	string Results;
	ifstream File;
	File.open("D:\\testingsystem\\results\\allresults.txt");
	while (getline(File, Results))
	{
		cout << Results;
	}
	File.close();
	system("pause");
	AdminMenu(Users, Admin, Categories, Tests);
}