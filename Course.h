#pragma once
#include <string>

using namespace std;

struct date {
	int day, month, year;
	
};

struct ttime {
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
	ttime start_time;
	ttime end_time;
	int dow;
public:
	Course();
	Course(string code, string year, unsigned int semester, string name, string lec_username, date st_date, date ed_date, ttime st_time, ttime ed_time, int day);
	~Course();

	void setCourseCode(string code);
	void setYear(string year);
	void setSemester(int semester);
	void setName(string name);
	void setLecUsername(string username);
	void setStartDate(date start);
	void setEndDate(date end);
	void setStartTime(ttime start);
	void setEndTime(ttime end);
	void setDoW(int dow);

	string getCourseCode();
	string getYear();
	int getSemester();
	string getName();
	string getLecUsername();
	date getStartDate();
	date getEndDate();
	ttime getStartTime();
	ttime getEndTime();
	int getDoW();
};

bool collidedDate(date sd1, date sd2, date ed1, date ed2); //compare if d2 is collided with d1
bool collidedTime(ttime shour1, ttime shour2, ttime ehour1, ttime ehour2); //compare if t2 time is collided t1