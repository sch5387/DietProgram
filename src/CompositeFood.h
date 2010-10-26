/*
 * CompositeFood.h
 *
 *  Created on: Oct 15, 2010
 *      Author: Steven Horowitz
 */

#ifndef COMPOSITEFOOD_H_
#define COMPOSITEFOOD_H_
using namespace std;
#include "FoodComponent.h"
#include <iostream>
#include <vector>

class CompositeFood : public FoodComponent{
	string myName;

	public:
	CompositeFood(string name);
	void add (FoodComponent *food);
	void setName(string name);
	string getName();
	int getCalories();
	void addKeyword(string keyword);
	vector<string> getComponents();
	bool keyInComponents(string keyword);
	bool hasKeyword(string keyword);
	vector<string> getKeywords();
	string getType();

	private:
	vector<FoodComponent*> components;
};

#endif /* COMPOSITEFOOD_H_ */
