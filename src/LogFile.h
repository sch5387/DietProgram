#ifndef _LOGFILE_H
#define _LOGFILE_H
#include <string>
#include <vector>
#include "LogWriter.h"
#include "LogCommand.h"
#include "AddToLog.h"
#include "DeleteFromLog.h"

class LogFile {

private:
	vector<string> logItems;
	LogWriter writer;
	AddToLog logAdder;
	DeleteFromLog logDeleter;
	LogActionMemento memento;

public:
	LogFile() {}

	void addToLog(string name) = 0;
	void deleteFromLog(string name) = 0;
	void undoEdit() = 0;
	void saveLog() = 0;
	void loadLog() = 0;

};
#endif