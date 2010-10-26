#include "AddToLog.h"
using namespace std;

vector<string> AddToLog::execute(vector<string> logItems, string item) {
	vector<string> newLogItems = addItem(logItems, item);
	return newLogItems;
};

vector<string> AddToLog::addItem(vector<string> logItems, string item) {
	logItems.push_back(item);
	return logItems;
};