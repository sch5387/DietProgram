/*
* LogWriter.cpp
* <<IOStream>>
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class LogWriter {

private:
	LogFile Log;

public:
	LogWriter::LogWriter(LogFile newLog) {
		Log = newLog;
	} //LogWriter

	LogWriter::LogWriter() {
	} //LogWriter

	void LogWriter::saveLog() {
		ofstream newFile;
		vector*<String> logItems = Log.giveLog();
		newFile.open("FoodLog.txt");
		vector*<FoodComponent>::iterator iter;
		for (iter = components.begin(); iter != components.end(); iter++) {
			newFile << (&iter + "\n");
		}
		newFile.close();
	} //saveLog

	LogFile LogWriter::loadLog() {
		ofstream newFile;
		vector*<String> logItems;
		newFile.open("FoodLog.txt");
		int i = 0;
		while(!newFile.eof) {
			String string;
			getline(newFile,string);
			logItems->insert(i,string);
			i++;
		}
		newFile.close();
		return logItems;
	} //loadLog

}; //LogWriter