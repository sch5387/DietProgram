#ifndef _LOGWRITER_H
#define _LOGWRITER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class LogWriter {

public:
	LogWriter() {}

	void saveLogFile(vector<string> logFile);
	vector<string> loadLogFile();

};
#endif