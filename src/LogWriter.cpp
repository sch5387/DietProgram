/*
* LogWriter.cpp
* <<IOStream>>
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
#include "LogFile.cpp"

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
		unsigned int i;
		vector<string> *logItems = Log.giveLog();
		newFile.open("FoodLog.txt");
		for (i=0; i < logItems->size;i++) {
			newFile << (logItems->at(i) + "\n");
		}
		newFile.close();
	} //saveLog

	LogFile LogWriter::loadLog() {
		ofstream newFile;
		vector<string> *logItems;
		newFile.open("FoodLog.txt");
		int i = 0;
		while(!newFile.eof) {
			string line;
			getline(newFile,line);
			logItems->insert(i,line);
			i++;
		}
		newFile.close();
		return logItems;
	} //loadLog

}; //LogWriter