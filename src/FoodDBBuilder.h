/*
 * FoodDBBuilder.h
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */
using namespace std;
#include <vector>
#include "FoodComponent.h"
#include "BasicFood.h"
#include "CompositeFood.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef FOODDBBUILDER_H_
#define FOODDBBUILDER_H_

class FoodDBBuilder{
	private:
	vector<FoodComponent*> myFoods;

	public:
	virtual vector<FoodComponent*> loadDB()=0;
	virtual void saveDB(vector<FoodComponent*> database)=0;
	virtual void setFile(string filename)=0;
	string myFile;
	FoodComponent* buildComponent(char* foodname, char* foodtype, char* components, char* keys){
		char* ptr;
		ptr = NULL;
		// the item being read is a BasicFood item, and is easy to build.
		if (*foodtype=='b'){
			int calories = atoi(components);
			BasicFood* basic = new BasicFood(foodname,calories);
			addKeywords(keys,basic);
			myFoods.push_back(basic);
			return basic;

		// the item being read is a CompositeFood item, and must be built.
		} else if (*foodtype=='c'){
			if (components){
			CompositeFood* comp = new CompositeFood(foodname);
			ptr = strtok(components,",");
			while(ptr!=NULL){
				// find the appropriate ingredient and add it to the product.
				vector<FoodComponent*>::iterator iter;
				for(iter = myFoods.begin();iter!=myFoods.end();iter++){
					if(ptr!=NULL){
						string tempname = (*iter)->getName();
						string pointername = ptr;
						if (pointername==tempname){
							comp->add(*iter);
						}
					}
				}
				ptr = strtok(NULL,",");
			}
			addKeywords(keys,comp);
			myFoods.push_back(comp);
			return comp;
			}
		}
		return NULL;
	}

	void addKeywords(char* keywords, FoodComponent* component){
		char* ptr;
		vector<string>::iterator iter;
		ptr = strtok(keywords,",");
		while(ptr!=NULL){
			component->addKeyword(*(new string(ptr)));
			ptr = strtok(NULL,",");
		}
	}
};

#endif /* FOODDBBUILDER_H_ */
