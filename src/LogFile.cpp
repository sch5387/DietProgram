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
	vector<string> logItems;

public:
	LogFile::LogFile(vector<string> logFileItems) {
		logItems = logFileItems;
	}

	void LogFile::addItem() {

	}

	void LogFile::removeItem() {

	}

	void LogFile::undoChange() {

	}

	void LogFile::redoChange() {

	}

};