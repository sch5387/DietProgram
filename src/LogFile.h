/*
 * LogFile.h
 *
 * Created on: Oct 8, 2010
 *
 * Author: jaw6891@rit.edu
 */

#ifndef LOGFILE_H_
#define LOGFILE_H_
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

class LogFile{

	LogFile(){
	}

	virtual addItem();
	virtual removeItem();
	virtual undoChange();
	virtual redoChange();
	virtual giveLog();
	virtual setLogItems();
};

#endif /* LOGFILE_H_ */