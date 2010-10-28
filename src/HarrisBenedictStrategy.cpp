#include "HarrisBenedictStrategy.h"

double HarrisBenedictStrategy::calcDailyCalories() {
	double gender;
	double weightMult;
	double heightMult;
	double ageMult;
	if (profile->getGender().compare("female") == 0) {
		gender = 655;
		weightMult = 4.35;
		heightMult = 4.7;
		ageMult = 4.7;
	}
	else {
		gender = 66;
		weightMult = 6.23;
		heightMult = 12.7;
		ageMult = 6.76;
	}
	double age = ageMult * profile->getAge();
	double height = heightMult * (profile->getHeightFeet() * 12 + profile->getHeightInches());
	double weight = weightMult * profile->getWeight();
	double activityLevel = calcActivityLevel(profile->getActivityLevel());
	return activityLevel * (gender + weight + height - age);
}

double HarrisBenedictStrategy::calcActivityLevel(double level) {
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
