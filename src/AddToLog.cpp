/*
* AddToLog.cpp
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
* Author: rxj9246@g.rit.edu  Richard Jester
*/

#include "LogCommand.h"

using namespace std;

class AddToLog: public LogCommand {

	AddToLog::AddToLog()
		LogCommand::LogCommand();
	{}

	void LogCommand::execute(vector*<String> v) {
		cout("Please specify what food to add: ");
		Sting food = cin();
		cout("/nPlease specify the number of servings: ");
		String servings = cin();
		cout(/n"Please specify the date(mm/dd/yyyy): ");
		String date = cin();
		&v.push_back(date + ": " + servings + " servings of " + food);
	};


};