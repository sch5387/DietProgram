/*
 * Nutrient.h
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include <string>
#ifndef NUTRIENT_H_
#define NUTRIENT_H_

class Nutrient{

	public:
	string myName;
	int myValue;
	Nutrient(string name, int value){
		myName = name;
		myValue = value;
	}
	Nutrient(){
		myName = "undefined";
		myValue = 0;
	}
	virtual string getName()=0;
	virtual void setName(string name)=0;
	virtual int getValue()=0;
	virtual void setValue(int value)=0;
};

#endif /* NUTRIENT_H_ */
