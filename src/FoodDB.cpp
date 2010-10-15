/*
 * FoodDB.cpp
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */

#include "FoodComponent.h"
#include "FoodDBBuilder.h"
#include <vector>

using namespace std;

class FoodDB{
	public:
	vector<FoodComponent*> DB;

	void setBuilder(FoodDBBuilder* builder){
		foodBuilder = builder;
	}

	void loadDB(string filename){
		foodBuilder->setFile(filename);
		DB = foodBuilder->loadDB();
	}
	void saveDB(vector<FoodComponent*> database){
		foodBuilder->saveDB(database);
	}
	void changeFile(string target){
		foodBuilder->setFile(target);
	}
	private:
	FoodDBBuilder* foodBuilder;
};
