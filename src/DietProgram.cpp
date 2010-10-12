//============================================================================
// Name        : DietProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "BasicFood.cpp"
#include "CompositeFood.cpp"
using namespace std;

int main() {

	BasicFood *myFood = new BasicFood("squirrel",1000);
	cout << myFood->getName() << endl;
	cout << myFood->getCalories() << endl;
	BasicFood *secondFood = new BasicFood("child",500);
	cout << secondFood->getName() << endl;
	cout << myFood->getCalories() << endl;

	CompositeFood *comp = new CompositeFood("composite");
	comp->add(myFood);
	comp->add(secondFood);
	cout << comp->getName() << endl;
	cout << comp->getCalories() << endl;
	return 0;
};
