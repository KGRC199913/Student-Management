#pragma once
#include <string>

using namespace std;

struct date {
	int day, month, year;
	
};

struct time {
	int hour, minute;
};


class Course
{
	string Course_code;
	string year;
	unsigned int semester;
	string name;
	string Lecturer_username;
	date start_date;
	date end_date;
	time start_time;
	time end_time;
	int dow;
public:
	Course();
	Course(string code, string year, unsigned int semester, string name, string lec_username, date st_date, date ed_date, time st_time, time ed_time, int day);
	~Course();

	void setCourseCode(string code);
	void setYear(string year);
	void setSemester(int semester);
	void setName(string name);
	void setLecUsername(string username);
	void setStartDate(date start);
	void setEndDate(date end);
	void setStartTime(time start);
	void setEndTime(time end);
	void setDoW(int dow);

	string getCourseCode();
	string getYear();
	int getSemester();
	string getName();
	string getLecUsername();
	date getStartDate();
	date getEndDate();
	time getStartTime();
	time getEndTime();
	int getDoW();
};

bool collidedDate(date sd1, date sd2, date ed1, date ed2); //compare if d2 is collided with d1
bool collidedTime(time shour1, time shour2, time ehour1, time ehour2); //compare if t2 time is collided t1