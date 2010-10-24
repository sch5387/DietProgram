/*
 * LogMemento.h
 *
 *  Created on: Oct 8, 2010
 *      Author: jaw6891@rit.edu
 */

using namespace std;
#ifndef LOGMEMENTO_H_
#define LOGMEMENTO_H_

class LogMemento{

	LogMemento(){
	}
	virtual createMemento();
	virtual revertTo();
};

#endif /* LOGMEMENTO_H_ */