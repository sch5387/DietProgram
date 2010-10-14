/*
 * DefaultBuilder.cpp
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "FoodDBBuilder.h"
#include "BasicFood.cpp"
#include "CompositeFood.cpp"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class DefaultBuilder : public FoodDBBuilder{
	public:
	vector<FoodComponent*> myFoods;

	DefaultBuilder(){
		myFile = "undefined";
	}

	vector<FoodComponent*> loadDB(){
		ifstream input;
		input.open(myFile.c_str());
		if(input.is_open()){
			while(!input.eof()){
				char line[256];
				input.getline(line,256);
				char* ptr;
				ptr = strtok(line,",");
				char* name = ptr;
				ptr = strtok(NULL,",");
				if (*ptr=='b'){
					int calories = atoi(strtok(NULL,","));
					myFoods.push_back(new BasicFood(name,calories));
				} else{

					CompositeFood* comp = new CompositeFood(name);
					while(ptr!=NULL){
						// this is the name of the component to add to this composite food.
						ptr = strtok(NULL,",");
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
					}
					myFoods.push_back(comp);
				}
			}
		}else{
			cerr << "not open";
		}
		return myFoods;
	}

	void saveDB(vector<FoodComponent*>){

	}
	void setFile(string file){
		myFile = file;
	}
};
