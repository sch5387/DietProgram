/*
 * CompositeFood.cpp
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "FoodComponent.h"
#include <iostream>
#include <vector>

class CompositeFood : public FoodComponent{
	string myName;

	public:
	CompositeFood(string name){
		myName = name;
	}

	void add (FoodComponent *food){
		components.push_back(food);
	}

	void setName(string name){
		myName = name;
	}

	string getName(){
		return myName;
	}

	int getCalories(){
		int calories = 0;
		vector<FoodComponent*>::iterator iter;
		for(iter = components.begin();iter != components.end();iter++){
			FoodComponent* food = *iter;
			calories += food->getCalories();
			cout << food->getName() << " "<< endl;
		}
		return calories;
	}

	void addKeyword(string keyword){
		keywords.push_back(keyword);
	}

	vector<string> getComponents(){
		vector<string> ingredients;
		vector<FoodComponent*>::iterator iter;
		for(iter = components.begin();iter != components.end();iter++){
			FoodComponent* food = *iter;
			ingredients.push_back(food->getName());
		}
		return ingredients;
	}
	vector<string> getKeywords(){
		return keywords;
	}

	string getType(){
		return "c";
	}
	private:
	vector<FoodComponent*> components;
};
