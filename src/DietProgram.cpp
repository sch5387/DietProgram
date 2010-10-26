//============================================================================
// Name        : DietProgram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "FoodDB.cpp"
#include "DefaultBuilder.cpp"
#include "CompositeFood.h"
#include <unistd.h>
using namespace std;

char* prune(char* edit){
	char* returnable = edit;
	while(*edit!=0){
		if(!isalpha(*edit) && !isdigit(*edit) && *edit!=',' && *edit!=' '){
			*edit=0;
		}
		*edit++;
	}
	return returnable;
}

void add(FoodDB* database){
	char name[256];
	char type[256];
	char components[256];
	char keywords[256];
	cout << "Please enter the name of the Food Item." << endl;
	cin.getline(name,256);
	cout << "Please enter if it is a composite food or basic food (c or b)." << endl;
	cin.getline(type,256);
	if(type[0]=='b'){
		cout << "Please enter the total calories of the food item." <<endl;
	} else if(type[0]=='c'){
		cout << "Please enter a list of ingredients, seperated by commas."<<endl;
	}
	cin.getline(components,256);
	cout << "Please enter a list of keywords to describe the object, seperated by commas."<<endl;
	cin.getline(keywords,256);
	database->addFood(prune(name),type,prune(components),prune(keywords));
}

void print(FoodDB* database){
	vector<FoodComponent*> myDB = database->DB;
	vector<FoodComponent*>::iterator iter;
	for(iter=myDB.begin();iter!=myDB.end();iter++){
		FoodComponent* food = (*iter);
		cout << food->getName() << ", "<< food->getCalories() << " Calories." << endl;
	}
}

void search(FoodDB* database){
	string keyword;
	cout << "what keyword would you like to search for?";
	cin >> keyword;
	cin.ignore(100,'\n');
	vector<FoodComponent*> foods = database->searchDB(keyword);
	vector<FoodComponent*>::iterator iter;
	for(iter=foods.begin();iter!=foods.end();iter++){
		FoodComponent* item = *iter;
		cout << "Found food item: " <<item->getName()<< endl;
	}
}

int main() {

	char* path = NULL;
	path = _getcwd(path,256);
	string pathstring(path);
	pathstring.append("\\src\\testfile.txt");
	cout << pathstring << endl;
	bool run = true;
	char line[256];
	FoodDB* database = new FoodDB();
	database->setBuilder(new DefaultBuilder());
	database->loadDB(pathstring);
	cout << "**********************************************************" << endl;
	cout << "** Welcome to the SE20101 Diet Program. Please select an**"<< endl;
	cout << "**            option from the menu below.               **"<< endl;
	cout << "**********************************************************"<< endl;

	while (run){
		cout << "1) Enter a new food item" << endl;
		cout << "2) View all food items" << endl;
		cout << "3) Save the food Database" << endl;
		cout << "4) Search the food Database" << endl;
		cout << "5) Save and Quit" << endl;
		cin.getline(line,256);
		if (line[0]=='1'){
			add(database);
		} else if (line[0]=='2'){
			print(database);
		} else if (line[0]=='3'){
			cout << "saving..." << endl;
			database->saveDB(database->DB);
			cout << "saved." << endl;
		} else if (line[0]=='4'){
			search(database);
		} else if (line[0]=='5'){
			run = false;
		}
	}

	database->saveDB(database->DB);
	cout << "Database saved... program exiting..." << endl;
	return 0;
};
