/*
 * LogIO.cpp
 *
 *  Created on: Oct 27, 2010
 *      Author: Steven Horowitz
 */

#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LogItem.h"
using namespace std;

class LogIO{
public:
	string myFile;
	vector<LogItem*> log;
	LogIO(string file){
		myFile = file;
	}

	void readLog(){
		ifstream input;
		input.open(myFile.c_str());
		if(input.is_open()){
			while(!input.eof()){
				char date[256];
				char data[256];
				input.getline(date,256);
				input.getline(data,256);
				log.push_back(new LogItem(data,date));
			}
		}
	}

	void printLog(){
		vector<LogItem*>::iterator iter;
		for(iter = log.begin();iter!=log.end();iter++){
			(*iter)->print();
		}
	}
};
