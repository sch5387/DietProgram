#ifndef _MIFFLINSTRATEGY_H
#define _MIFFLINSTRATEGY_H
#include <string>
#include <sstream>
#include <vector>
#include "Profile.h"
#include "ProfileStrategy.h"

class MifflinStrategy : public ProfileStrategy {

private:
	Profile * profile;

public:
	MifflinStrategy(Profile * pro) : ProfileStrategy(pro) , profile(pro) {
	}

public:

	double virtual calcDailyCalories();

private:

	double calcActivityLevel(double);
};
#endif