#include <iostream>
#include <conio.h>
#include "Admin.h"
#include "Menu.h"
#include "User.h"
#include "Test.h"
#include <list>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	list<User*> Users;
	vector<string> Categories;
	vector<Test> Tests;
	TitleScreen(Users, Categories, Tests);
}
