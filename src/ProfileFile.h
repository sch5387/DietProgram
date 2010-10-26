#ifndef _PROFILEFILE_H
#define _PROFILEFILE_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class ProfileFile {

private:
	std::string fileName;

public:
	ProfileFile(std::string);

public:
	bool writeFile(std::vector<std::string>);

	std::vector<std::string> readFile();

private:
	std::vector<std::string> parseLine(std::string);
};
#endif
