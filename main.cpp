#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "User.h"
#include "Course.h"
#include "Presence.h"
#include "Score.h"
#include "Presence.h"
#include "GeneralFeatures.h"
#include "Academic_staff_features.h"

using namespace std;

int main() {
	Attendance temp;
	import_attendance("CTT008 (3)", temp);
	temp.Course_code = "test";
	export_attendance(temp);
	return 0;
}