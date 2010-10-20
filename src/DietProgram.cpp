//============================================================================
// Name        : DietProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "FoodDB.cpp"
#include "DefaultBuilder.cpp"
#include "CompositeFood.h"
using namespace std;

int main() {
	char input[256];
	FoodDB* database = new FoodDB();
	database->setBuilder(new DefaultBuilder());
	database->loadDB("/cygdrive/c/Users/sxhwcs/DietProgram/src/testfile.txt");
	cout << "**********************************************************" << endl;
	cout << "** Welcome to the SE20101 Diet Program. Please select an**"<< endl;
	cout << "**            option from the menu below.               **"<< endl;
	cout << "**********************************************************"<< endl;

	cout << "enter the name of the food";
	char name[256];
	//cin.getline(name,256);
	cout << "is it basic or composite?";
	char type[256];
	//cin.getline(type,256);
	cout << "how many calories does it have, or what ingredients does it have?";
	//cin.getline(input,256);
	//cout << name << type << input << endl;
	cout << endl;
	cout << database->DB[3]->getCalories() << endl;
	//database->saveDB(database->DB);
	return 0;
};
