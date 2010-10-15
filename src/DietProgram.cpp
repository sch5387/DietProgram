//============================================================================
// Name        : DietProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "FoodDB.cpp"
#include "DefaultBuilder.cpp"
using namespace std;

int main() {
	FoodDB* database = new FoodDB();
	DefaultBuilder* builder = new DefaultBuilder();
	database->setBuilder(builder);
	database->loadDB("C:/Users/Steven Horowitz/DietProgram/src/testfile.txt");
	database->changeFile("C:/Users/Steven Horowitz/DietProgram/src/testoutput.txt");
	database->saveDB(database->DB);
	return 0;
};
