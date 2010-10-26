#include "Profile.h"
#include "ProfileFile.h"
#include <stdio.h>
#include <stdlib.h>
#include "ProfileStrategy.h"
#include "MifflinStrategy.h"
#include "HarrisBenedictStrategy.h"

using namespace std;

Profile::Profile() {
	filePointer = new ProfileFile::ProfileFile("profile.diet");
	ProfileFile::ProfileFile & file = *filePointer;
	vector<string> settings = file.readFile();
	if (settings.size() == 6) {
		age = atoi(settings.at(2).c_str());
		gender = settings.at(0);
		weight = atoi(settings.at(3).c_str());
		activityLevel = atof(settings.at(1).c_str());
		feet = atoi(settings.at(4).c_str());
		inches = atoi(settings.at(5).c_str());
	}
	else {
		setProfile();
	}
};

int Profile::getAge() {
	return age;
}

void Profile::writeProfile() {
	vector<string> settings (0);
	settings.push_back(gender);
	stringstream stringToken;
	stringToken << activityLevel;
	settings.push_back(stringToken.str());
	stringToken.str(std::string());
	stringToken << age;
	settings.push_back(stringToken.str());
	stringToken.str(std::string());
	stringToken << weight;
	settings.push_back(stringToken.str());
	stringToken.str(std::string());
	stringToken << feet;
	settings.push_back(stringToken.str());
	stringToken.str(std::string());
	stringToken << inches;
	settings.push_back(stringToken.str());
	ProfileFile::ProfileFile & file = *filePointer;
	file.writeFile(settings);
}

void Profile::setProfile() {
	cout << "Please set up your profile." << endl;
	string input;
	stringstream stringToken(input);
	if (gender.empty()) {
		int genderInt;
		do {
			cout << "Are you male or female? (Type 1 for male or 2 for female)" << endl;
			getline(cin, input);
			stringstream stringToken(input);
			stringToken >> genderInt;
		}
		while (genderInt != 1 && genderInt != 2);
		if (genderInt == 1) gender = "male";
		else gender = "female";
	}
	do {
		cout << "How old are you in years?" << endl;
		getline(cin, input);
		stringstream stringToken(input);
		stringToken >> age;
	}
	while (age < 1);
	do {
		cout << "In feet and inches, how many feet?" << endl;
		getline(cin, input);
		stringstream stringToken(input);
		stringToken >> feet;
	}
	while (feet < 1);
	do {
		cout << "How many inches?" << endl;
		getline(cin, input);
		stringstream stringToken(input);
		stringToken >> inches;
	}
	while (inches < 1);
	do {
		cout << "What weight are you?" << endl;
		getline(cin, input);
		stringstream stringToken(input);
		stringToken >> weight;
	}
	while (weight < 1);
	do {
		cout << "How active are you? Type in the number corresponding to your level of activity." << endl;
		cout << "1 - Barly Active" << endl;
		cout << "2 - Lightly Active" << endl;
		cout << "3 - Moderately Active" << endl;
		cout << "4 - Very Active Active" << endl;
		cout << "5 - Extra Active" << endl;
		getline(cin, input);
		stringstream stringToken(input);
		stringToken >> activityLevel;
	}
	while (activityLevel < 1 || activityLevel > 5);
	writeProfile();
}

string Profile::getGender() {
	return gender;
}

int Profile::getWeight() {
	return weight;
}

int Profile::getHeightFeet() {
	return feet;
}

int Profile::getHeightInches() {
	return inches;
}

double Profile::getActivityLevel() {
	return activityLevel;
}

void Profile::setAge(int user_age) {
	age = user_age;
}

void Profile::setHeightFeet(int ft) {
	feet = ft;
}

void Profile::setHeightInches(int in) {
	inches = in;
}

void Profile::setWeight(int user_weight) {
	weight = user_weight;
}

void Profile::setActivityLevel(double user_activityLevel) {
	activityLevel = user_activityLevel;
}

bool Profile::setGender(string user_gender) {
	gender = user_gender;
	return true;
}

double Profile::getDailyCalories(int method) {
	ProfileStrategy::ProfileStrategy * strat;
	if (method == 1) {
		strat = new MifflinStrategy::MifflinStrategy(this);
	}
	else {
		strat = new HarrisBenedictStrategy::HarrisBenedictStrategy(this);
	}
	ProfileStrategy::ProfileStrategy & strategy = *strat;
	return strategy.calcDailyCalories();
}
