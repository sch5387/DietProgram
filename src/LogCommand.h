#ifndef _LOGCOMMAND_H
#define _LOGCOMMAND_H
#include <vector>
#include <string>

class LogCommand {

public:
	LogCommand() { }

	vector<string> virtual execute(vector<string>,string item) = 0;

};
#endif