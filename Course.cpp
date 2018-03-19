#include "Course.h"

Course::Course() {

}

Course::Course(string code, string year, unsigned int semester, string name, string lec_username, date st_date, date ed_date, time st_time, time ed_time, int day) {
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

void Course::setStartTime(time start) {
	this->start_time = start;
}

void Course::setEndTime(time end) {
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

time Course::getStartTime() {
	return this->start_time;
}

time Course::getEndTime() {
	return this->end_time;
}

int Course::getDoW() {
	return this->dow;
}