/*
 * DefaultBuilder.cpp
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "FoodDBBuilder.h"
#include "BasicFood.h"
#include "CompositeFood.h"
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

				// the first token in the line will be the name of the food item.
				char* name = ptr;

				// the second token in the line will be the type of food item (basic or composite)
				ptr = strtok(NULL,",");

				// the item being read is a BasicFood item, and is easy to build.
				if (*ptr=='b'){
					int calories = atoi(strtok(NULL,","));
					myFoods.push_back(new BasicFood(name,calories));

				// the item being read is a CompositeFood item, and must be built.
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
		input.close();
		return myFoods;
	}

	void saveDB(vector<FoodComponent*> outgoingVector){
		ofstream output(myFile.c_str(), ios::out);
		vector<FoodComponent*>::iterator iter;
		for(iter=outgoingVector.begin();iter!=outgoingVector.end();iter++){
			output << (*iter)->getName() << "," << (*iter)->getType();
			vector<string> components = (*iter)->getComponents();
			vector<string>::iterator componentIterator;
			for(componentIterator=components.begin();componentIterator!=components.end();componentIterator++){
				output << ","<< (*componentIterator);
			}
			output << "," <<endl;
			output.flush();
		}
		output.close();
	}
	void setFile(string file){
		myFile = file;
	}
};
