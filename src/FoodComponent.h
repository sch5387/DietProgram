/*
 * FoodComponent.h
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include <string>
#include <iostream>
#include "Nutrient.h"
#include <vector>

#ifndef FOODCOMPONENT_H_
#define FOODCOMPONENT_H_

class FoodComponent{
public:
	virtual string getName()=0;
	virtual vector<string> getKeywords()=0;
	virtual int getCalories()=0;

	virtual void setName(string name)=0;
	virtual void addKeyword(string keyword)=0;
	virtual vector<string> getComponents()=0;
	virtual bool hasKeyword(string keyword)=0;
	virtual string getType()=0;

	string myName;
	vector<string> keywords;
	vector<Nutrient*> nutrients;
};

#endif /* FOODCOMPONENT_H_ */
