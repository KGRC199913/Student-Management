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
	//resetPassword(&current_login);
	vector<User> test;
	import_students("17CLC3.csv", test);
	change_class(test);
	return 0;
}