#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iterator>
#include "User.h"
#include "Course.h"
#include "Score.h"
#include "Presence.h"
#include "sha256.h"


using namespace std;
void import_students(string path, vector<User>&);
void add_new_student(vector<User>&);
void append_new_student_info(User);
int get_student_pos(vector<User>&, string ID);
void remove_student(vector<User>&, string ID);
void remove_student(vector<User>&, int pos);
void print_class_to_file(string Class, vector<User>&);
void print_list_of_class(); //ko dung ham nay
void print_student_list(string Class);
void change_class(vector<User>&);
void add_new_class(string className);


void import_course(string path, vector<Course>& list);
void print_course_list_to_file(string path, vector<Course>& list);
void add_new_course(vector<Course>& list);
bool isCollied(const Course &c1, const Course &c2);
void remove_course(vector<Course>& list);

vector<string> read_directory(); //dung ham nay de lay list class

void import_scoreboard(string course, Scoreboard &list);
void export_scoreboard(Scoreboard &list);

void import_attendance(string course, Attendance &list);
void export_attendance(Attendance &list);