#ifndef _PROFILE_H
#define _PROFILE_H
#include <string>
#include <sstream>
#include "ProfileFile.h"

class Profile {

private:
	ProfileFile* filePointer;
	int age;
	int activityLevel;
	std::string gender;
	int feet;
	int inches;
	int weight;

public:
	Profile();

public:
	int getAge();

	std::string getGender();

	int getWeight();

	int getHeightFeet();

	int getHeightInches();

	double getActivityLevel();

	void setAge(int);

	void setWeight(int);

	void setHeightFeet(int);

	void setHeightInches(int);

	bool setGender(std::string);

	void setActivityLevel(double);

	void setProfile();

	void writeProfile();

	double getDailyCalories(int);
};
#endif
