#ifndef _LOGACTIONMEMENTO_H
#define _LOGACTIONMEMENTO_H
#include <vector>
#include <string>
#include "LogMemento.h"

class LogActionMemento : public LogMemento {

private:
	vector<string> snapshot;

public:
	LogActionMemento() { }

	void virtual addSnap(vector<string> oldLog) = 0;
	vector<string> virtual undo(vector<string> newLog) = 0;

};
#endif