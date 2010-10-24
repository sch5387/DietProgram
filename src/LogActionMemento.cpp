/*
* LogActionMemento.cpp
*
* Created October 24th, 2010
* Author: jaw6891@rit.edu "Jordan Wayman"
*/

using namespace std;

class LogActionMemento: public LogMomento {

	private vector* state;

	public LogActionMomento::LogActionMomento (vector &s) {
		state = s;
	};		

};