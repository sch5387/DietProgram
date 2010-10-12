/*
 * Calorie.cpp
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "Nutrient.h"

class Calorie : public Nutrient{
public:

	Calorie(int value){
		myName = "calorie";
		myValue = value;
	}

	string getName(){
		return myName;
	}
	int getValue(){
		return myValue;
	}
	void setName(string name){
		myName = name;
	}
	void setValue(int value){
		myValue = value;
	}
};
