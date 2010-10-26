#include "ProfileFile.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

ProfileFile::ProfileFile(string fileName) {
	this->fileName = fileName;
};

bool ProfileFile::writeFile(vector<string> settings) {
	FILE * handler = fopen(fileName.c_str(), "a+");
	fclose(handler);
	ofstream file;
	file.open(fileName.c_str());
	if (file) {
		for (unsigned int i = 0; i < settings.size(); i++) {
			file << settings.at(i);
			if (i + 1 < settings.size()) {
				file << " ";
			}
		}
		file.close();
		return true;
	}
	else {
		return true;
	}
};

vector<string> ProfileFile::readFile() {
	ifstream file;
	file.open(fileName.c_str());
	string fileLine = "";
	vector<string> fileVector;
	if (file) {
		getline(file, fileLine);
		vector<string> testVector = ProfileFile::parseLine(fileLine);
		if (testVector.size() == 6) {
			if (atoi(testVector.at(1).c_str()) > 0 && atoi(testVector.at(2).c_str()) > 0
			 && atoi(testVector.at(3).c_str()) > 0 && atoi(testVector.at(4).c_str()) > 0
			 && atoi(testVector.at(5).c_str()) > 0) {
				fileVector = testVector;
			}
		}

	}
	file.close();
	return fileVector;

};

vector<string> ProfileFile::parseLine(string line) {
	stringstream stringToken (line);
	string str;
	vector<string> fileVector (0);
	for (int i = 0; i < 6 && stringToken >> str; i++) {
		fileVector.push_back(str);
	}
	return  fileVector;
}

