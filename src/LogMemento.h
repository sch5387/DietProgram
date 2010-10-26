#ifndef _LOGMEMENTO_H
#define _LOGMEMENTO_H
#include <vector>
#include <string>

class LogMemento {

private:
	vector<string> snapshot;

public:
	LogMemento() { }

	void virtual addSnap(vector<string> oldLog) = 0;
	vector<string> virtual undo(vector<string> newLog) = 0;

};
#endif