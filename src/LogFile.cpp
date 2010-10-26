#include "LogFile.h"

using namespace std;

LogFile::LogFile() {
	writer = new LogWriter::LogWriter();
	loadLog;
	logAdder = new AddToLog::AddToLog();
	logDeleter = new DeleteFromLog::DeleteFromLog();
	memento = new LogActionMemento();
	memento.addSnap(logItems);
};

void LogFile::addToLog(string name) {
	logItems = logAdder.execute(logItems,name);
};

void LogFile::deleteFromLog(string name) {
	logItems = logDeleter.execute(logItems,name);
};

void LogFile::undoEdit() {
	logItems = memento.undo(logItems);
};

void LogFile::saveLog() {
	writer.saveLogFile();
};

void LogFile::loadLog() {
	logItems = writer.loadLogFile();
};