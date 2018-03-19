#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "User.h"
#include "Course.h"
#include "Presence.h"
#include "Score.h"
#include "GeneralFeatures.h"
#include "Academic_staff_features.h"

using namespace std;

int main() {
	vector<Course> test;
	import_course("Course.csv", test);
	add_new_course(test);
	print_course_list_to_file("Course.test.csv", test);
	system("pause");
	return 0;
}