/*
 * BasicFood.cpp
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "BasicFood.h"

BasicFood::BasicFood(string name, int calories){
	myName = name;
	Nutrient* calorie = new Calorie(calories);
	addNutrient(calorie);
}
string BasicFood::getName(){
	return myName;
}
vector<string> BasicFood::getKeywords(){
	return keywords;
}
int BasicFood::getCalories(){
	Nutrient* ptr = nutrients.front();
	while(ptr!=0){
		if(ptr->getName()=="calorie")
			return ptr->getValue();
		ptr++;
	}
	return 0;
}

bool BasicFood::hasKeyword(string keyword){
	for(int i = 0; i< keywords.size();i++){
		if(keywords[i]==keyword){
			return true;
		}
	}
}

vector<string> BasicFood::getComponents(){
	int calories = getCalories();
	stringstream ss;
	ss << calories;
	string myCalories;
	ss >> myCalories;
	vector<string> returnable;
	returnable.push_back(myCalories);
	return returnable;
}
void BasicFood::setName(string name){
	myName = name;
}
void BasicFood::addKeyword(string keyword){
	keywords.push_back(keyword);
}
void BasicFood::addNutrient(Nutrient* nutrient){
	nutrients.push_back(nutrient);
}
string BasicFood::getType(){
	return "b";
}
