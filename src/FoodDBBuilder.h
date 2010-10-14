/*
 * FoodDBBuilder.h
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */
using namespace std;
#include <vector>
#include "FoodComponent.h"
#include <string>

#ifndef FOODDBBUILDER_H_
#define FOODDBBUILDER_H_

class FoodDBBuilder{
	public:
	vector<FoodComponent*> myFoods;
	virtual vector<FoodComponent*> loadDB()=0;
	virtual void saveDB(vector<FoodComponent*>)=0;
	virtual void setFile(string filename)=0;
	FoodComponent* buildComponent();
	string myFile;

};

#endif /* FOODDBBUILDER_H_ */
