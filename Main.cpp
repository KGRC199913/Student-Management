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
#include "menu.h"
using namespace std;

int main() 
{
	system("color 30");
	Attendance temp;
	import_attendance("CTT008(3)", temp);
	temp.Course_code = "test";
	export_attendance(temp);
	menu(5);
	return 0;
}