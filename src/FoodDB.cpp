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

	void addFood(char* name, char* type,char* components,char* keywords){
		FoodComponent* item = foodBuilder->buildComponent(name,type,components,keywords);
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

	vector<FoodComponent*> searchDB(string keyword){
		vector<FoodComponent*> returnable;
		vector<FoodComponent*>::iterator iter;
		for(iter = DB.begin();iter!=DB.end();iter++){
			vector<string> keywords = (*iter)->getKeywords();
			vector<string>::iterator keyIter;
			for(keyIter = keywords.begin();keyIter!=keywords.end();keyIter++){
				string key = (*keyIter);
				if(key == keyword)
					returnable.push_back(*iter);
			}
		}
		return returnable;
	}
	private:
	FoodDBBuilder* foodBuilder;
};
