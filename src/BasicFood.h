/*
 * BasicFood.h
 *
 *  Created on: Oct 15, 2010
 *      Author: Steven Horowitz
 */

#ifndef BASICFOOD_H_
#define BASICFOOD_H_
#include <string>
#include "FoodComponent.h"
#include "Calorie.cpp"
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
class BasicFood : public FoodComponent{

	public:
	BasicFood(string name, int calories);
	string getName();
	vector<string> getKeywords();
	int getCalories();
	vector<string> getComponents();
	void setName(string name);
	void addKeyword(string keyword);
	void addNutrient(Nutrient* nutrient);
	string getType();
};

#endif /* BASICFOOD_H_ */
