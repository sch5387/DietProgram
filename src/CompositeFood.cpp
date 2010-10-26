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
	vector<string> keys = food->keywords;
	vector<string>::iterator iter;
	for(iter = keys.begin();iter<keys.end();iter++){
		addKeyword(*iter);
	}
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
	}
	return calories;
}

void CompositeFood::addKeyword(string keyword) {
	if(hasKeyword(keyword)==false)
		keywords.push_back(keyword);
}

bool CompositeFood::hasKeyword(string keyword){
	for(unsigned int i = 0; i< keywords.size();i++){
		if(keywords[i]==keyword){
			return true;
		}
	}
	return false;
}

bool CompositeFood::keyInComponents(string keyword){
	vector<FoodComponent*>::iterator iter;
	for(iter = components.begin();iter !=components.end();iter++){
		FoodComponent* food = *iter;
		if(food->hasKeyword(keyword))
			return true;
	}
	return false;
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
