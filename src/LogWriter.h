/*
 * LogWriter.h
 *
 * Created on: Oct 8, 2010
 *
 * Author: jaw6891@rit.edu
 */

#ifndef LOGWRITER_H_
#define LOGWRITER_H_
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LogFile.cpp"

class LogWriter{

	LogWriter(LogFile newLog){
	}

	LogWriter() {
	}

	virtual saveLog();
	virtual loadLog();
};

#endif /* LOGWRITER_H_ */