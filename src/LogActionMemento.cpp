#include "LogActionMemento.h"
using namespace std;

void LogActionMemento::addSnap(vector<string> oldLog) {
	snapshot = oldLog;
};

vector<string> LogActionMemento::undo(vector<string> newLog) {
	vector<string> temp = snapshot;
	snapshot = newLog;
	return temp;
};