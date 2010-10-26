#ifndef _DELETEFROMLOG_H
#define _DELETEFROMLOG_H
#include <vector>
#include <string>
#include "LogCommand.h"

class DeleteFromLog : public LogCommand {

public:
	DeleteFromLog() : LogCommand() { }

	vector<string> virtual execute(vector<string>, string item) = 0;

private:
	vector<string> deleteItem(vector<string>, string item) = 0;

};
#endif