/*
 * LogItem.h
 *
 *  Created on: Oct 27, 2010
 *      Author: Steven Horowitz
 */

#ifndef LOGITEM_H_
#define LOGITEM_H_

#include <vector>
#include <string>
#include "FoodComponent.h"
#include "BasicFood.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
class LogItem{
public:

	LogItem(char* foods, char* date);
	vector<FoodComponent*> myFoods;
	string myDate;
	void print();
};

#endif /* LOGITEM_H_ */
