#pragma once
#include <iostream>
#include <array>
#include <string>
#include "User.h"
#include <vector>
using namespace std;
class Test
{
	string TestCategory;
	string TestTitle;
	array<string, 6> Questions;
	array<string, 6> Answers;
public:
	Test(string _TestCategory, string _TestTitle, array<string, 6>& _Questions, array<string, 6>& _Answers);
	void SaveTestToFile();
	void ReadTestFromFile();
};

