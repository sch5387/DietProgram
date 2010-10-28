/*
 * LogItem.cpp
 *
 *  Created on: Oct 27, 2010
 *      Author: Steven Horowitz
 */

#include "LogItem.h"

LogItem::LogItem(char* foodline, char* date){
	vector<FoodComponent*> food;
	vector<FoodComponent*>::iterator iter;
	char* ptr;
	ptr = strtok(foodline,",");
	while(ptr!=NULL){
		char* name = ptr;
		ptr = strtok(NULL,",");
		char* component = ptr;
		ptr = strtok(NULL,",");
		string stringname = name;
		int calories = atoi(component);
		FoodComponent* newfood = new BasicFood(name,calories);
		myFoods.push_back(newfood);
	}
	myDate = date;
}

void LogItem::print(){
	cout << "Date of entry " << myDate << endl;
	vector<FoodComponent*>::iterator iter;
	for(iter = myFoods.begin();iter!=myFoods.end();iter++){
		cout << "Food Item: " << (*iter)->getName() << ", Calories: " << (*iter)->getCalories() << endl;
	}
}
