#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <ctime>
#include "User.h"
#include "Presence.h"
#include "Academic_staff_features.h"

using namespace std;

User::User() {
}

User::User(string ID, string name, string phone, string Class)
{
	this->username = ID;
	this->full_name = name;
	this->mphone = phone;
	this->Class = Class;
	this->password = "000";
	this->email = ID + "@hcmus.edu.vn";
	this->type = 0;
}


User::User(string name, string phone, char type) {
	this->full_name = name;
	this->type = type;
	this->password = "000";
	this->Class = "";
	this->mphone = phone;
	this->username = createUsername(name);
	this->email = this->username;
	this->email.append("@fit.hcmus.edu.vn");
}

string User::createUsername(string name) {
	string result;
	result += static_cast<char> (tolower(name[0]));
	unsigned int len = name.length();
	for (int i = 1; i < len; ++i) {
		if (name[i - 1] == ' ') {
			result += static_cast<char> (tolower(name[i]));
		}
	}
	string temp;
	for (int i = len-1; i > 1; --i) {
		if (name[i - 1] == ' ') break;
		temp = name[i] + temp;
	}
	return result + temp;
}
User::~User()
{
	this->username.clear();
	this->email.clear();
	this->full_name.clear();
	this->Class.clear();
	this->mphone.clear();
	this->password.clear();
}

int User::printinfo() {
	cout << "Name: " << this->full_name << endl << "Email: " << this->email << endl << "Mobile Phone: " << this->mphone << endl;
	if (!type) cout << "Class: " << this->Class << endl;
	else if (type == 1) cout << "Academic Staff" << endl;
	else cout << "Lecturer" << endl;
	return 0;
}

string User::getUsername() {
	return this->username;
}

string User::getEmail() {
	return this->email;
}

string User::getMobilePhone() {
	return this->mphone;
}

string User::getFullName() {
	return this->full_name;
}

string User::getClass() {
	return this->Class;
}

bool User::checkLegitPassword(string newPass_same) {
	bool haveUpper = false, haveLower = false, haveNum = false, samePass = false;
	int len = this->password.length();
	for (int i = 0; i < len; ++i) {
		if (isupper(this->password[i])) haveUpper = true;
		if (islower(this->password[i])) haveLower = true;
		if (isdigit(this->password[i])) haveNum = true;
	}
	if (this->password == newPass_same) samePass = true;
	bool legit = haveUpper && haveLower && haveNum && samePass && (len < 36) && (len > 8);
	if (legit) return legit;
	else
	{
		if (!samePass) cout << "\tYour later inputed password is not the same with your former inputed password" << endl;
		if (!haveUpper) cout << "\tYour password is not containing any UPPER character" << endl;
		if (!haveLower) cout << "\tYour password is not containing any lower character" << endl;
		if (!haveNum) cout << "\tYour password is not containing any number" << endl;
		if (len < 8) cout << "\tYour password is too short (min 8 characters)" << endl;
		if (len > 36) cout << "\tYour password is too long (max 36 characters)" << endl;
		return legit;
	}
}

void User::setUsername(string newUsername) {
	this->username = newUsername;
}

void User::setPassword(string newPass) {
	this->password = newPass;
}
void User::setName(string newName) {
	this->full_name = newName;
}
void User::setPhone(string newPhone) {
	this->mphone = newPhone;
}
void User::setClass(string newClass) {
	this->Class = newClass;
}


string User::getPassword() {
	return this->password;
}

bool User::check_in(string course_code, vector<Course> &course_list) {
	for (auto i : course_list) {
		if (i.getCourseCode() == course_code) {
			time_t current_time = time(nullptr);
			tm* timePtr = localtime(&current_time);
			if (timePtr->tm_wday == (i.getDoW() - 1)) {
				Attendance temp;
				import_attendance("CTT008 (3)", temp);
				for (auto j : temp.attendance_list) {
					if (j.ID == this->username) {
						if (((timePtr->tm_mon + 1) - i.getStartDate().month) < 0) return false;
						int cur_week = ((timePtr->tm_mon + 1) - i.getStartDate().month) * 4 + (i.getStartDate().day / 7);
						if (cur_week > 10) cur_week = 10;
						j.check_in[cur_week - 1] = true;
						return true;
					}
				}
			}
		}
	}
	return false;
}