/*
 * CompositeFood.cpp
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

#include "CompositeFood.h"

string myName;

CompositeFood::CompositeFood(string name) {
	myName = name;
}

void CompositeFood::add(FoodComponent *food) {
	components.push_back(food);
}

void CompositeFood::setName(string name) {
	myName = name;
}

string CompositeFood::getName() {
	return myName;
}

int CompositeFood::getCalories() {
	int calories = 0;
	vector<FoodComponent*>::iterator iter;
	for (iter = components.begin(); iter != components.end(); iter++) {
		FoodComponent* food = *iter;
		calories += food->getCalories();
		cout << food->getName() << " " << endl;
	}
	return calories;
}

void CompositeFood::addKeyword(string keyword) {
	keywords.push_back(keyword);
}

vector<string> CompositeFood::getComponents() {
	vector<string> ingredients;
	vector<FoodComponent*>::iterator iter;
	for (iter = components.begin(); iter != components.end(); iter++) {
		FoodComponent* food = *iter;
		ingredients.push_back(food->getName());
	}
	return ingredients;
}
vector<string> CompositeFood::getKeywords() {
	return keywords;
}

string CompositeFood::getType() {
	return "c";
}
vector<FoodComponent*> components;
