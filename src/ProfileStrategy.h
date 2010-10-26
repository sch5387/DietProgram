#ifndef _PROFILESTRATEGY_H
#define _PROFILESTRATEGY_H
#include "Profile.h"

class ProfileStrategy {

private:

public:
	ProfileStrategy(Profile *) {
	}

public:

	double virtual calcDailyCalories() = 0;

};
#endif
