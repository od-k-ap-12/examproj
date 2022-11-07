#include "Test.h"
#include <fstream>

Test::Test(string _TestCategory, string _TestTitle, array<string, 6>& _Questions, array<string, 6>& _Answers)
{
	TestCategory = _TestCategory;
	TestTitle = _TestTitle;
	Questions = _Questions;
	Answers = _Answers;
}
void Test::SaveTestToFile()
{
	ofstream File;
	string TestPath = "D:\\testingsystem\\tests\\";
	string TestPathEnd = ".txt";
	TestPath += TestTitle;
	TestPath += TestPathEnd;
	File.open(TestPath);
	for (auto it = Questions.begin(); it != Questions.end(); it++)
	{
		File << *it;
		File << endl;
	}
	File.close();

	string TestTitlePath = "D:\\testingsystem\\testtitles.txt";
	File.open(TestTitlePath);
	File << TestCategory << " " << TestTitle;
	File.close();

	string TestAnswersPath = "D:\\testingsystem\\tests\\";
	string TestAnswersPathEnd = "answers.txt";
	TestAnswersPath += TestTitle;
	TestAnswersPath += TestAnswersPathEnd;
	File.open(TestAnswersPath);
	for (auto it = Answers.begin(); it != Answers.end(); it++)
	{
		File << *it;
		File << endl;
	}
	File.close();

	cout << "Сохранено";
	system("pause");
}

void Test::ReadTestFromFile()
{
	string Question;
	ifstream File;
	string PathBegin = "D:\\testingsystem\\tests\\";
	string PathEnd = ".txt";
	PathBegin += TestTitle;
	PathBegin += PathEnd;
	File.open(PathBegin);
	while (getline(File, Question))
	{
		cout << Question;
		cout << endl;
	}
	File.close();
	system("pause");
}

