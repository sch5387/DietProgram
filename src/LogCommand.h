/*
 * LogCommand.h
 *
 *  Created on: Oct 8, 2010
 *      Author: sxhwcs
 */

using namespace std;
#include <string>
#ifndef LOGCOMMAND_H_
#define LOGCOMMAND_H_

class LogCommand{

	LogCommand(){
	}
	virtual void execute();
};

#endif /* LOGCOMMAND_H_ */