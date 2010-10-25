/*
* LogFile.cpp
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
*/

using namespace std;
#include <vector>

class LogFile {

private:
	vector*<String> logItems;
	vector*<LogActionMemento> previousStates;

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

	vector*<String> LogFile::giveLog() {
		return logItems;
	}

	void LogFile::setLogItems() {

	}

};