#ifndef _ADDTOLOG_H
#define _ADDTOLOG_H
#include <vector>
#include <string>
#include "LogCommand.h"

class AddToLog : public LogCommand {

public:
	AddToLog() : LogCommand() { }

	vector<string> virtual execute(vector<string> logItems,string item) = 0;

private:
	vector<string> addItem(vector<string> logItems, string item) = 0;

};
#endif