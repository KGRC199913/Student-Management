#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "User.h"
#include "Course.h"
#include "sha256.h"

using namespace std;
void import_students(string path, vector<User>&);
void add_new_student(vector<User>&);
void append_new_student_info(User);
int get_student_pos(vector<User>&, string ID);
void remove_student(vector<User>&, string ID);
void remove_student(vector<User>&, int pos);
void print_class_to_file(string Class, vector<User>&);
void print_list_of_class();
void print_student_list(string Class);
void change_class(vector<User>&);
void add_new_class(string className);


void import_course(string path, vector<Course>& list);
void print_course_list_to_file(string path, vector<Course>& list);
void add_new_course(vector<Course>& list);
void remove_course(vector<Course>& list);