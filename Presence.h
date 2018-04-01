#pragma once
#include <string>
#include <vector>

using namespace std;
class Presence
{
public:
	string ID;
	string name;
	bool check_in[10];
	Presence();
	Presence(string ID, string name, bool check_inp[10]);
};

class Attendance {
public:
	string Course_code;
	vector<Presence> attendance_list;
};

