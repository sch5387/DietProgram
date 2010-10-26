#include "LogWriter.h"

using namespace std;

LogWriter::LogWriter() {
};

void LogWriter::saveLogFile(vector<string> logFile) {
	unsigned int i;
	ofstream file;
	file.open("LogFile.txt");
	for(i = 0; i < logFile.size; i++) {
		file << logFile.at(i) << "\n";
	}
	file.close();
};

vector<string> LogWriter::loadLogFile(string name) {
	vector<string> loadedLog;
	ifstream file;
	string line;
	file.open("LogFile.txt");
	if (file.is_open) {
		while (file.good()) {
			getline(file,line);
			loadedLog.push_back(line);
		}
	}
	return loadedLog;
};