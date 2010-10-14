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
using namespace std;

int main() {
	FoodDB* database = new FoodDB();
	DefaultBuilder* builder = new DefaultBuilder();
	database->setBuilder(builder);
	database->loadDB("/cygdrive/c/Users/sxhwcs/DietProgram/src/testfile.txt");
	return 0;
};
