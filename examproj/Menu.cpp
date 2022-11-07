#include <iostream>
#include "Menu.h"
#include "User.h"
#include <conio.h>
#include <list>
#include <algorithm>
#include "Exception.h"
#include <fstream>
#include "Admin.h"
#include <vector>
#include "Test.h"
using namespace std;

void TitleScreen(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests)
{
	setlocale(LC_ALL, "ru");
	system("cls");
	bool Exit = false;
	int Choice;
	cout << "1.Зарегистрироваться\n2.Войти\n3.Войти как администратор\n4.Выйти";
	cin >> Choice;
	switch (Choice) {
	case 1:
		SignUp(Users, Categories, Tests);
		break;
	case 2:
		SignIn(Users, Categories, Tests);
		break;
	case 3: {
		Admin* NewAdmin = new Admin();
		SignInAdmin(Users, NewAdmin, Categories, Tests);
		break;
	}
	case 4:
		Exit = true;
	}
	if (exit) {
		return;
	}
}

void SignUp(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	User* NewUser = nullptr;
	cout << "1.Вернутся в главное меню\n2.Зарегистрироваться\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
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
		if (SearchLogin(Login, Users) == false) {
			NewUser = new User(Login, Password, FirstName, LastName, Address, PhoneNumber);
			Users.push_back(NewUser);
			cout << "Новый пользователь успешно создан. Войдите в свой аккаунт, чтобы продолжить.";
			NewUser->SaveUserToFile();
			system("pause");
			TitleScreen(Users, Categories, Tests);
		}
		else {
			SignUp(Users, Categories, Tests);
		}
	}

}

void SignInAdmin(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	string Login;
	string Password;
	cout << "1.Вернутся в главное меню\n2.Пройти аутентификацию\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
		break;
	case 2:
		try {
			cout << "Введите логин: " << endl;
			cin >> Login;
			cout << "Введите пароль: " << endl;
			cin >> Password;
			if (Admin->GetLogin() == Login && Admin->GetPassword() == Password) {
				AdminMenu(Users, Admin, Categories, Tests);
			}
			else {
				throw new InvalidLoginOrPassword("Неверный логин или пароль!");
			}
		}
		catch (Base* b)
		{
			b->Print();
			SignInAdmin(Users, Admin, Categories, Tests);
		}
	}
}

void SignIn(list<User*>& Users, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	string Login;
	string Password;
	cout << "1.Вернутся в главное меню\n2.Пройти аутентификацию\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
		break;
	case 2:
		cout << "Введите логин: " << endl;
		cin >> Login;
		cout << "Введите пароль: " << endl;
		cin >> Password;
		if (SearchLogin(Login, Users) == true) {
			if (SearchUser(Login, Password, Users) == false) {
				User* NewUser = new User(Login, Password);
				UserMenu(Users, NewUser, Categories, Tests);
			}
			else {
				SignIn(Users, Categories, Tests);
			}
		}
		else {
			SignIn(Users, Categories, Tests);
		}
	}
}

bool UserCheck(string _login, string _password, list<User*>& users)
{
	try {

		if (SearchUser(_login, _password, users) == 0) {
			throw new InvalidLoginOrPassword("Неверный логин или пароль!");
		}
		else {
			return true;
		}
	}
	catch (Base* b)
	{
		b->Print();
		system("pause");
		return false;
	}
}

bool LoginCheck(string _Login, list<User*>& Users)
{
	try {
		if (SearchLogin(_Login, Users) == 1) {
			throw new InvalidLoginOrPassword("Такой логин существует!");
		}
		else {
			return true;
		}
	}
	catch (Base* b)
	{
		b->Print();
		system("pause");
		return false;
	}
}

bool SearchLogin(string _Login, list<User*>& Users)
{
	bool Result = false;
	string LoginPath = "D:\\testingsystem\\logins.txt";
	ifstream File;
	string InFileLogin;
	File.open(LoginPath);
	while (getline(File, InFileLogin))
	{
		if (InFileLogin == _Login) {
			Result = true;
			File.close();
			return true;
		}
	}
	if (!Result) {
		return false;
	}
}

bool SearchUser(string _Login, string _Password, list<User*>& Users)
{
	string PathBegin = "D:\\testingsystem\\";
	string PathEnd = ".bin";
	PathBegin += _Login;
	PathBegin += PathEnd;
	string FileLogin, FilePassword;
	ifstream File(PathBegin, ios::binary);
	File.read((char*)&FileLogin, size(FileLogin));
	File.read((char*)&FilePassword, size(FilePassword));
	File.close();
	if (_Login == FileLogin && FilePassword == _Password) {
		return true;
	}
	else {
		return false;
	}
}

void AdminMenu(list<User*>& Users, Admin* Admin, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	int Choice;
	cout << "1.Создать пользователя\n2.Удалить пользователя\n3.Изменить пользователя\n4.Посмотреть статистику по тестам\n5.Посмотреть статистику конкретного пользователя\n";
	cout << "6.Добавить категорию\n7.Добавить тест\n8.Сохранить в файл категориии\n9.Сохранить в файл тесты\n10.Выйти из аккаунта и вернуться в главное меню";

	cin >> Choice;
	switch (Choice) {
	case 1:
		Admin->AddUser(Users, Admin, Categories, Tests);
		break;
	case 2:
		Admin->DeleteUser(Users, Admin, Categories, Tests);
		break;
	case 3:
		Admin->EditUser(Users, Admin, Categories, Tests);
		break;
	case 4:
		Admin->PrintAllResults(Users, Admin, Categories, Tests);
		break;
	case 5: {
		Admin->PrintUserResults(Users, Admin, Categories, Tests);
		break;
	}
	case 6:
		Admin->AddCategory(Users, Admin, Categories, Tests);
		break;
	case 7:
		Admin->AddTest(Users, Admin, Categories, Tests);
		break;
	case 8:
		Admin->SaveCategoriesToFile(Users, Admin, Categories, Tests);
		break;
	case 9:
		Admin->SaveTestsToFile(Users, Admin, Categories, Tests);
		break;
	case 10:
		TitleScreen(Users, Categories, Tests);
		break;
	default:
		AdminMenu(Users, Admin, Categories, Tests);
		break;
	}
}

void UserMenu(list<User*>& Users, User* User, vector<string>& Categories, vector<Test>& Tests)
{
	system("cls");
	int Choice;
	cout << "1.Пройти новый тест\n2.Посмотреть всю результаты\n3.Выйти из аккаунта и вернуться в главное меню";
	cin >> Choice;
	switch (Choice) {
	case 1:
		User->PassTest(Users, Categories, Tests);
		break;
	case 2:
		User->PrintResults();
		break;
	case 3:
		TitleScreen(Users, Categories, Tests);
		break;
	default:
		UserMenu(Users, User, Categories, Tests);
		break;
	}
	system("pause");
}

