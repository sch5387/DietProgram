/*
 * LogMemento.h
 *
 * Created on: Oct 8, 2010
 *
 * Author: jaw6891@rit.edu
 * Author: rxj9246@g.rit.edu
 */

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef LOGMEMENTO_H_
#define LOGMEMENTO_H_

class LogMemento{

	LogMemento(){
	}

	virtual revertTo();
};

#endif /* LOGMEMENTO_H_ */