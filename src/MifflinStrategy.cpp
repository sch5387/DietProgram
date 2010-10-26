#include "MifflinStrategy.h"

using namespace std;

double MifflinStrategy::calcDailyCalories() {
	Profile::Profile & profile = *this->profile;
	double gender;
	double weightMult = 10;
	double heightMult = 6.25;
	double ageMult = 5;
	if (profile.getGender().compare("male") == 0) {
		gender = 5;
	}
	else {
		gender = -161;
	}
	double age = ageMult * (double)profile.getAge();
	double height = heightMult * (((double)profile.getHeightFeet() * 12 + (double)profile.getHeightInches()) * 2.54);
	double weight = weightMult * (double)profile.getWeight() * 0.45359237;
	double activityLevel = calcActivityLevel(profile.getActivityLevel());
	return activityLevel * (weight + height - age + gender);
}

double MifflinStrategy::calcActivityLevel(double level) {
	double activityLevel;
	if (level == 1) {
		activityLevel = 1.2;
	}
	else if (level == 2) {
		activityLevel = 1.375;
	}
	else if (level == 3) {
		activityLevel = 1.55;
	}
	else if (level == 4) {
		activityLevel = 1.725;
	}
	else {
		activityLevel = 1.9;
	}
	return activityLevel;
}