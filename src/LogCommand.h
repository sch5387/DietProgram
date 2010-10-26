/*
 * LogCommand.h
 *
 *  Created on: Oct 8, 2010
 *      Author: jaw6891@rit.edu
 */

using namespace std;
#ifndef LOGCOMMAND_H_
#define LOGCOMMAND_H_

class LogCommand{

	LogCommand(){
	}
	virtual void execute(vector*<String> v);
};

#endif /* LOGCOMMAND_H_ */