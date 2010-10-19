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

	void addFood(char* name, char* type,char* components){
		FoodComponent* item = foodBuilder->buildComponent(name,type,components);
		DB.push_back(item);
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
