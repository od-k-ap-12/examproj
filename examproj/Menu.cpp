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
	cout << "1.������������������\n2.�����\n3.����� ��� �������������\n4.�����";
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
	cout << "1.�������� � ������� ����\n2.������������������\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
		break;
	case 2:
		string Login, Password, FirstName, LastName, Address, PhoneNumber;
		cout << "������� ���: " << endl;
		cin >> FirstName;
		cout << "������� �������: " << endl;
		cin >> LastName;
		cout << "������� �����: " << endl;
		cin >> Address;
		cout << "������� ����� ��������: " << endl;
		cin >> PhoneNumber;
		cout << "������� �����: " << endl;
		cin >> Login;
		cout << "������� ������: " << endl;
		cin >> Password;
		if (SearchLogin(Login, Users) == false) {
			NewUser = new User(Login, Password, FirstName, LastName, Address, PhoneNumber);
			Users.push_back(NewUser);
			cout << "����� ������������ ������� ������. ������� � ���� �������, ����� ����������.";
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
	cout << "1.�������� � ������� ����\n2.������ ��������������\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
		break;
	case 2:
		try {
			cout << "������� �����: " << endl;
			cin >> Login;
			cout << "������� ������: " << endl;
			cin >> Password;
			if (Admin->GetLogin() == Login && Admin->GetPassword() == Password) {
				AdminMenu(Users, Admin, Categories, Tests);
			}
			else {
				throw new InvalidLoginOrPassword("�������� ����� ��� ������!");
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
	cout << "1.�������� � ������� ����\n2.������ ��������������\n";
	int Choice;
	cin >> Choice;
	switch (Choice) {
	case 1:
		TitleScreen(Users, Categories, Tests);
		break;
	case 2:
		cout << "������� �����: " << endl;
		cin >> Login;
		cout << "������� ������: " << endl;
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
			throw new InvalidLoginOrPassword("�������� ����� ��� ������!");
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
			throw new InvalidLoginOrPassword("����� ����� ����������!");
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
	cout << "1.������� ������������\n2.������� ������������\n3.�������� ������������\n4.���������� ���������� �� ������\n5.���������� ���������� ����������� ������������\n";
	cout << "6.�������� ���������\n7.�������� ����\n8.��������� � ���� ����������\n9.��������� � ���� �����\n10.����� �� �������� � ��������� � ������� ����";

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
	cout << "1.������ ����� ����\n2.���������� ��� ����������\n3.����� �� �������� � ��������� � ������� ����";
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

