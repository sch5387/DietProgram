#include "DeleteFromLog.h"
using namespace std;

vector<string> DeleteFromLog::execute(vector<string> logItems, string item) {
	vector<string> newLogItems = deleteItem(logItems, item);
	return newLogItems;
};

vector<string> DeleteFromLog::deleteItem(vector<string> logItems, string item) {
	unsigned int i;
	for(i = 0; i < logItems.size; i++) {
		if(logItems.at(i).compare(item) == 0) {
			logItems.erase(i);
			i = logItems.size + 1;
		}
	}
};