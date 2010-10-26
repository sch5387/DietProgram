#ifndef _HARRISBENEDICTSTRATEGY_H
#define _HARRISBENEDICTSTRATEGY_H
#include <string>
#include <sstream>
#include <vector>
#include "Profile.h"
#include "ProfileStrategy.h"

class HarrisBenedictStrategy : public ProfileStrategy {

private:
	Profile * profile;

public:
	HarrisBenedictStrategy(Profile * pro) : ProfileStrategy(pro) , profile(pro) {
	}

public:

	double virtual calcDailyCalories();

private:
	double calcActivityLevel(double);

};
#endif