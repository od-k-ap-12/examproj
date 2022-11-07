#include "User.h"
#include <fstream>
#include "Test.h"
#include "Menu.h"
User::User(string _Login, string _Password, string _FirstName, string _LastName, string _Address, string _PhoneNumber)
{
	Login = _Login;
	Password = _Password;
	FirstName = _FirstName;
	LastName = _LastName;
	Address = _Address;
	PhoneNumber = _PhoneNumber;
}

User::User(string _Login, string _Password)
{
	Login = _Login;
	Password = _Password;
	FirstName = "0";
	LastName = "0";
	Address = "0";
	PhoneNumber = "0";
}

void User::PrintResults()
{
	string Results;
	ifstream File;
	string PathBegin = "D:\\examproject\\testingsystem\\results\\";
	string PathEnd = ".txt";
	PathBegin += Login;
	PathBegin += PathEnd;
	File.open(PathBegin);
	while (getline(File, Results))
	{
		cout << Results;
	}
	File.close();
	system("pause");
}

//Система прохождения теста строится на вытягивании всех его элементов из файла, чтобы при закрытии консоли данные сохранялись

void User::PassTest(list<User*>& Users, vector <string>& Categories, vector<Test>& Tests)
{
	system("cls");
	int RightAnswersCount = 0;
	array<string, 6> Answers;
	string Category;
	ifstream File;
	string TestTitlePath = "D:\\examproject\\testingsystem\\testtitles.txt";
	string TestTitle;
	File.open(TestTitlePath);
	while (getline(File, TestTitle))
	{
		cout << TestTitle;
		cout << endl;
	}
	File.close();
	cout << endl << "Ïåðâîå ñëîâî - êàòåãîðèÿ. Âòîðîå - òåìà òåñòà. Âûáåðèòå òåñò (íàïèøèòå òåìó òåñòà): ";
	cin >> TestTitle;

	string TestPath = "D:\\examproject\\testingsystem\\tests\\";
	string TestPathEnd = ".txt";
	TestPath += TestTitle;
	TestPath += TestPathEnd;
	string Question;
	File.open(TestPath);
	while (getline(File, Question))
	{
		cout << Question;
		cout << endl;
	}
	File.close();
	for (int i = 0; i < 6; i++) {
		cout << "Ââåäèòå îòâåò íà âîïðîñ " << i + 1;
		cin >> Answers[i];
	}
	string TestAnswersPath = "D:\\examproject\\testingsystem\\tests\\";
	string TestAnswersPathEnd = "answers.txt";
	TestAnswersPath += TestTitle;
	TestAnswersPath += TestAnswersPathEnd;
	string Answer;
	File.open(TestAnswersPath);
	int i = 0;
	while (getline(File, Answer))
	{
		if (Answer == Answers[i]) {
			RightAnswersCount++;
		}
		i++;
	}
	cout << endl << "Ïðàâèëüíûõ îòâåòîâ: " << RightAnswersCount << endl;
	cout << endl << "Îöåíêà: " << RightAnswersCount * 2 << " Â ïðîöåíòàõ: " << 100 / 6 * 6 << endl;
	SaveResult(TestTitle, RightAnswersCount * 2);
	system("pause");
	UserMenu(Users, this, Categories, Tests);
}

string User::GetLogin()
{
	return Login;
}

string User::GetPassword()
{
	return Password;
}

void User::SetUser(string _Login, string _Password, string _FirstName, string _LastName, string _Address, string _PhoneNumber)
{
	Login = _Login;
	Password = _Password;
	FirstName = _FirstName;
	LastName = _LastName;
	Address = _Address;
	PhoneNumber = _PhoneNumber;
}

void User::SaveUserToFile()
{
	string PathBegin = "D:\\examproject\\testingsystem\\";
	string PathEnd = ".bin";
	PathBegin += Login;
	PathBegin += PathEnd;
	ofstream File(PathBegin, ios::binary);
	File.write((char*)&Login, size(Login));
	File.write((char*)&Password, size(Password));
	File.close();

	string LoginPath = "D:\\examproject\\testingsystem\\logins.txt";
	File.open(LoginPath);
	File << Login;
	File << endl;
	File.close();
}

void User::SaveResult(string TestTitle, int Result)
{
	ofstream File;
	string UserResultPath = "D:\\examproject\\testingsystem\\results\\";
	string UserResultPathEnd = ".txt";
	UserResultPath += Login;
	UserResultPath += UserResultPathEnd;
	File.open(UserResultPath);
	File << TestTitle << " " << Result;
	File.close();

	string AllResultsPath = "D:\\examproject\\testingsystem\\results\\allresults.txt";
	File.open(AllResultsPath);
	File << TestTitle << " " << Login << " " << Result;
	File.close();

}
