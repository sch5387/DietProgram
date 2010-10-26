/*
 * DefaultBuilder.cpp
 *
 *  Created on: Oct 13, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include "FoodDBBuilder.h"

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
				if(*line!=0){
					char* ptr;
					ptr = strtok(line,",");
					char* name = ptr;
					char* type = strtok(NULL,",");
					char* components = strtok(NULL,";");
					char* keywords = strtok(NULL,";");
					FoodComponent* foodItem = buildComponent(name,type,components,keywords);
					myFoods.push_back(foodItem);
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
			output << ";";
			vector<string> keywords = (*iter)->getKeywords();
			vector<string>::iterator keyIterator;
			for(keyIterator=keywords.begin();keyIterator!=keywords.end();keyIterator++){
				string type = (*iter)->getType();
				if(type=="c" && !((CompositeFood*)(*iter))->keyInComponents(*keyIterator))
					output << "," << (*keyIterator);
				else if(type=="b")
					output << "," << (*keyIterator);
			}
			output << ";" << endl;
		}
		output.close();
	}
	void setFile(string file){
		myFile = file;
	}
};
