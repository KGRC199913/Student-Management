#pragma once
#include "Course.h"
#include <string>
#include <vector>

using namespace std;
class User
{
	string username;
	string full_name;
	string email;
	string mphone;
	unsigned char type;
	string password;
	string Class;
	string createUsername(string);
public:
	User(string ID, string name, string phone, string Class);
	User(string name, string phone, char type);
	User();
	int printinfo();
	
	bool checkLegitPassword(string newPass_same);
	
	void setUsername(string newUsername);
	void setName(string newName);
	void setPhone(string newPhone);
	void setClass(string newClass);
	void setPassword(string newPass);
	

	string getUsername();
	string getFullName();
	string getEmail();
	string getMobilePhone();
	string getPassword();
	string getClass();
	bool check_in(string course_code, vector<Course> &course_list);
	~User();
};

