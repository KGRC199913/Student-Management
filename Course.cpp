#include "Course.h"

Course::Course() {

}

Course::Course(string code, string year, unsigned int semester, string name, string lec_username, date st_date, date ed_date, ttime st_time, ttime ed_time, int day) {
	this->Course_code = code;
	this->year = year;
	this->semester = semester;
	this->name = name;
	this->Lecturer_username = lec_username;
	this->start_date = st_date;
	this->end_date = ed_date;
	this->start_time = st_time;
	this->end_time = ed_time;
	this->dow = day;
}


Course::~Course()
{
	this->Course_code.clear();
	this->name.clear();
	this->Lecturer_username.clear();
}

void Course::setCourseCode(string code) {
	this->Course_code = code;
}

void Course::setYear(string year) {
	this->year = year;
}

void Course::setSemester(int semester) {
	this->semester = semester;
}

void Course::setName(string name) {
	this->name = name;
}

void Course::setLecUsername(string username) {
	this->Lecturer_username = username;
}

void Course::setStartDate(date start) {
	this->start_date = start;
}

void Course::setEndDate(date end) {
	this->end_date = end;
}

void Course::setStartTime(ttime start) {
	this->start_time = start;
}

void Course::setEndTime(ttime end) {
	this->end_time = end;
}

void Course::setDoW(int dow) {
	this->dow = dow;
}

string Course::getCourseCode() {
	return this->Course_code;
}

string Course::getYear() {
	return this->year;
}

int Course::getSemester() {
	return this->semester;
}

string Course::getName() {
	return this->name;
}

string Course::getLecUsername() {
	return this->Lecturer_username;
}

date Course::getStartDate() {
	return this->start_date;
}

date Course::getEndDate() {
	return this->end_date;
}

ttime Course::getStartTime() {
	return this->start_time;
}

ttime Course::getEndTime() {
	return this->end_time;
}

int Course::getDoW() {
	return this->dow;
}

bool collidedDate(date sd1, date sd2, date ed1, date ed2) {
	if (((sd2.year <= ed1.year) && (sd2.year >= sd1.year)) ||
		((ed2.year <= ed1.year) && (ed2.year >= sd1.year)) ||
		((sd2.year < sd1.year) && (ed2.year > ed1.year))) {
		if (((sd2.month <= ed1.month) && (sd2.month >= sd1.month)) ||
			((ed2.month <= ed1.month) && (ed2.month >= sd1.month)) ||
			((sd2.month < sd1.month) && (ed2.month > ed1.month))) {
			if (((sd2.day <= ed1.day) && (sd2.day >= sd1.day)) ||
				((ed2.day <= ed1.day) && (ed2.day >= sd1.day)) ||
				((sd2.day < sd1.day) && (ed2.day > ed1.day))) {
				return true;
			}
		}
	}
	return false;
}

bool collidedTime(ttime st1, ttime st2, ttime et1, ttime et2) {
	if (((st2.hour <= et1.hour) && (st2.hour >= st1.hour)) ||
		((et2.hour <= et1.hour) && (et2.hour >= st1.hour)) ||
		((st2.hour < st1.hour) && (et2.hour > et1.hour))) {
		if (((st2.minute <= et1.minute) && (st2.minute >= st1.minute)) ||
			((et2.minute <= et1.minute) && (et2.minute >= st1.minute)) ||
			((st2.minute < st1.minute) && (et2.minute > et1.minute))) {
			return true;
		}
	}
	return false;
}