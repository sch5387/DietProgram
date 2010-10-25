/*
 * LogActionMemento.cpp
 *
 * Created October 24th, 2010
 *
 * Author: jaw6891@rit.edu "Jordan Wayman"
 * Author: rxj9246@g.rit.edu  Richard Jester
 */

#include "LogMemento.h"

using namespace std;

class LogActionMemento: public LogMemento {
	private:
	 	vector*<Stirng> state;

	public: 
		void LogActionMemento::LogActionMomento (vector*<String> s) 
			LogMemento::LogMemento();
		{
			state = s;
		};

		vector*<String> LogMemento::revertTo() {
			return state;
		};
};
