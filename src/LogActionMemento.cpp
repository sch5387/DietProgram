/*
 * LogActionMemento.cpp
 *
 * Created October 24th, 2010
 *
 * Author: jaw6891@rit.edu "Jordan Wayman"
 * Author: rxj9246@g.rit.edu  Richard Jester
 */

#include "LogMemento.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class LogActionMemento: public LogMemento {
	private:
	 	vector<string>* state;

	public: 
		LogActionMemento(vector<string> *s) 

		{
			state = s;
		};

		vector<string>* LogMemento::revertTo() {
			return state;
		};
};
