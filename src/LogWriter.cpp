/*
* LogWriter.cpp
* <<IOStream>>
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
*/

#include <iostream>
#include <fstream>
using namespace std;

class LogWriter {

private:
	LogFile Log;

public:
	LogWriter::LogWriter(LogFile newLog) {
		Log = newLog;
	}

	void LogWriter::saveLog() {
		ofstream newFile;
		vector*<String> logItems = Log.giveLog();
		newFile.open("FoodLog.txt");
		vector*<FoodComponent>::iterator iter;
		for (iter = components.begin(); iter != components.end(); iter++) {
			newFile << (&iter + "\n");
		}
	}

	LogFile LogWriter::loadLog() {

	}



};