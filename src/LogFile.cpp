/*
* LogFile.cpp
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
*/

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

class LogFile {

private:
	vector<string> *logItems;
	// vector<LogActionMemento> *previousStates;

public:
	LogFile::LogFile() {

	}

	void LogFile::addItem() {

	}

	void LogFile::removeItem() {

	}

	void LogFile::undoChange() {

	}

	void LogFile::redoChange() {

	}

	vector<string>* LogFile::giveLog() {
		return logItems;
	}

	void LogFile::setLogItems() {

	}

};