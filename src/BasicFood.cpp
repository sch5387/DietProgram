/*
 * BasicFood.cpp
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;

#include <string>
#include "FoodComponent.h"
#include "Calorie.cpp"

class BasicFood : public FoodComponent{

	public:
	BasicFood(string name, int calories){
		myName = name;
		Nutrient* calorie = new Calorie(calories);
		addNutrient(calorie);
	}

	string getName(){
		return myName;
	}

	vector<string> getKeywords(){
		return keywords;
	}
	int getCalories(){
		Nutrient* ptr = nutrients.front();
		while(ptr!=0){
			if(ptr->getName()=="calorie")
				return ptr->getValue();
			ptr++;
		}
		return 0;
	}

	void setName(string name){
		myName = name;
	}
	void addKeyword(string keyword){
		keywords.push_back(keyword);
	}
	void addNutrient(Nutrient* nutrient){
		nutrients.push_back(nutrient);
	}
};
