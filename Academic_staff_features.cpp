#include "Academic_staff_features.h"
#include "GeneralFeatures.h"

void import_students(string path, vector<User> &list) {
	ifstream listFile;
	listFile.open(path, ios::in);
	string buffer;
	getline(listFile, buffer, '\n');
	getline(listFile, buffer, '\n');
	buffer.clear();

	string clss = path;
	clss.pop_back();
	clss.pop_back();
	clss.pop_back();
	clss.pop_back();

	string ID, fname, phone, email;
	while (!listFile.eof()) {
		getline(listFile, buffer, ',');
		getline(listFile, ID, ',');
		getline(listFile, fname, ',');
		getline(listFile, email, ',');
		getline(listFile, phone, '\n');
		User temp(ID, fname, phone, clss);
		list.push_back(temp);
	}

	listFile.close();
}

void append_new_student_info(User user, vector<User>& list) {
	fstream loginDat;
	loginDat.open("LoginDat.csv", ios::in | ios::app);
	string buffer;
	getline(loginDat, buffer, '\n');
	getline(loginDat, buffer, '\n');
	buffer.clear();
	while (!loginDat.eof()) {
		getline(loginDat, buffer, ',');
		if (buffer == user.getUsername()) {
			cerr << "This student is already exist" << endl;
			list.pop_back();
		}
		getline(loginDat, buffer, '\n');
	}
	loginDat << user.getUsername() << "," << sha256(user.getPassword()) << "," << user.getClass() + ".csv" << endl;
	loginDat.close();
}


void add_new_student(vector<User>& list) {
	string ID, fname, phone, Class;
	cout << "ID: ";
	getline(cin, ID, '\n');
	cout << "Full Name: ";
	getline(cin, fname, '\n');
	cout << "Phone: ";
	getline(cin, phone, '\n');

	cout << "Class: ";
	getline(cin, Class, '\n');
	if (!fexist(Class + ".csv")) {
		cerr << "This class is not exist yet, please add this class first" << endl;
		return;
	}

	User temp(ID, fname, phone, Class);
	list.push_back(temp);
	
	append_new_student_info(temp, list);
}

int get_student_pos(vector<User>& list, string ID) {
	for (int i = 0; i < list.size(); ++i) {
		if (list[i].getUsername() == ID) {
			return i;
		}
	}
	return -1;
}


void remove_student(vector<User>& list, string ID) {
	list.erase(list.begin() + get_student_pos(list, ID));
}

void remove_student(vector<User>& list, int pos) {
	list.erase(list.begin() + pos);
}

void print_class_to_file(string Class, vector<User>& list) {
	ofstream fo;
	fo.open(Class + ".csv", ios::out);

	fo << "Class," << Class << ",\n";
	fo << "No,ID,Full Name,Email,Mobile Phone\n";

	string temp;
	for (int i = 0; i < list.size(); ++i) {
		temp = to_string(i + 1);
		if (temp.size() < 2) fo << "0" << temp << ",";
		else fo << temp << ",";
		fo << list[i].getUsername() << "," << list[i].getFullName() << "," << list[i].getEmail() << "," << list[i].getMobilePhone() << ",\n";
	}

	fo.close();
}

void print_list_of_class() {
	ifstream classList;
	classList.open("ClassList.csv", ios::in);


	string buffer;
	getline(classList, buffer, '\n');
	buffer.clear();
	while (!classList.eof()){
		getline(classList, buffer, '\n');
		cout << buffer << endl;
	}

	classList.close();
}

void print_student_list(string Class) {
	if (!fexist(Class + ".csv")) {
		cerr << "This class is not exist yet" << endl;
		return;
	}
	ifstream ClassFile;
	ClassFile.open(Class + ".csv");

	string buffer;
	getline(ClassFile, buffer, '\n');
	getline(ClassFile, buffer, '\n');

	cout << "Students of " + Class << endl;
	while (!ClassFile.eof()) {
		getline(ClassFile, buffer, ',');
		cout << buffer << ") ";
		getline(ClassFile, buffer, ',');
		cout << buffer << " ";
		getline(ClassFile, buffer, ',');
		cout << buffer << endl;
		getline(ClassFile, buffer, '\n');
		buffer.clear();
	}
	ClassFile.close();
}

void change_class(vector<User>& list) {
	string buffer;
	cout << "Input Student ID: ";
	getline(cin, buffer, '\n');
	int pos = get_student_pos(list, buffer);
	if (pos == -1) {
		cerr << "Cant not find student with ID " << buffer << endl;
		return;
	}

	User temp = list[pos];
	string newClass;
	cout << "Input new class: ";
	getline(cin, newClass, '\n');
	if (!fexist(newClass + ".csv")) {
		cerr << "Class not found" << endl;
		return;
	}

	ifstream desfile(newClass + ".csv");
	int line = count(istreambuf_iterator<char>(desfile), istreambuf_iterator<char>(), '\n') - 2;
	desfile.close();

	ofstream fo;
	fo.open(newClass + ".csv", ios::app | ios::ate);
	
	string tempString = to_string(line + 1);
	if (tempString.size() < 2) fo << "0" << tempString << ",";
	else fo << tempString << ",";
	fo << temp.getUsername() << "," << temp.getFullName() << "," << temp.getEmail() << "," << temp.getMobilePhone() << endl;

	fo.close();
	remove_student(list, pos);
	
	//change loginDat
	ifstream loginDat("loginDat.csv", ios::in);
	ofstream newLoginDat("loginDat.csv.temp", ios::out);
	buffer.clear();

	getline(loginDat, buffer, '\n');
	newLoginDat << buffer << endl;
	getline(loginDat, buffer, '\n');
	newLoginDat << buffer << endl;

while (!loginDat.eof()) {
	getline(loginDat, buffer, ',');
	if (buffer == temp.getUsername()) {
		newLoginDat << buffer << ",";
		getline(loginDat, buffer, ',');
		newLoginDat << buffer << ",";
		newLoginDat << newClass + ".csv" << endl;
		getline(loginDat, buffer, '\n');
		buffer.clear();
	}
	else {
		if (buffer.length() > 2) {
			newLoginDat << buffer << ",";
			getline(loginDat, buffer, '\n');
			newLoginDat << buffer << endl;
		}
	}
}

loginDat.close();
newLoginDat.close();
remove("loginDat.csv");
rename("loginDat.csv.temp", "loginDat.csv");
}

void add_new_class(string className) {
	if (fexist(className + ".csv")) {
		cerr << "Class " << className << " is already existed" << endl;
		return;
	}

	ofstream fo;
	fo.open(className + ".csv", ios::out);
	fo << "Class," << className << "," << endl;
	fo << "No,ID,Full Name,Email,Mobile Phone" << endl;
	fo.close();
}

void import_course(string path, vector<Course>& list) {
	ifstream fi(path, ios::in);
	string buffer;
	getline(fi, buffer, '\n');
	getline(fi, buffer, '\n');
	buffer.clear();

	date date_temp;
	ttime time_temp;
	Course course_temp;
	while (!fi.eof()) {
		getline(fi, buffer, ',');
		course_temp.setCourseCode(buffer);
		getline(fi, buffer, ',');
		course_temp.setName(buffer);
		getline(fi, buffer, ',');
		course_temp.setLecUsername(buffer);
		getline(fi, buffer, ',');
		course_temp.setYear(buffer);
		getline(fi, buffer, ',');
		course_temp.setSemester(stoi(buffer));

		getline(fi, buffer, '/');
		date_temp.day = stoi(buffer);
		getline(fi, buffer, '/');
		date_temp.month = stoi(buffer);
		getline(fi, buffer, ',');
		date_temp.year = stoi(buffer);
		course_temp.setStartDate(date_temp);

		getline(fi, buffer, '/');
		date_temp.day = stoi(buffer);
		getline(fi, buffer, '/');
		date_temp.month = stoi(buffer);
		getline(fi, buffer, ',');
		date_temp.year = stoi(buffer);
		course_temp.setEndDate(date_temp);

		getline(fi, buffer, 'h');
		time_temp.hour = stoi(buffer);
		getline(fi, buffer, ',');
		time_temp.minute = stoi(buffer);
		course_temp.setStartTime(time_temp);

		getline(fi, buffer, 'h');
		time_temp.hour = stoi(buffer);
		getline(fi, buffer, ',');
		time_temp.minute = stoi(buffer);
		course_temp.setEndTime(time_temp);

		getline(fi, buffer, '\n');
		course_temp.setDoW(stoi(buffer));

		list.push_back(course_temp);
	}

	fi.close();
}

void print_course_list_to_file(string path, vector<Course>& list) {
	ofstream fo(path, ios::out);

	fo << "CourseDat,\nCourse Code, Name, Lecturer Username, Year, Semester, Start date, End date, Start time, End time, Date of Week\n";

	for (int i = 0; i < list.size(); ++i) {
		fo << list[i].getCourseCode() << "," << list[i].getName() << "," << list[i].getLecUsername() << "," << list[i].getYear() << "," << list[i].getSemester() << "," << list[i].getStartDate().day << "/" << list[i].getStartDate().month << "/" 
			<< list[i].getStartDate().year << "," << list[i].getEndDate().day << "/" << list[i].getEndDate().month << "/" << list[i].getEndDate().year << ","
			<< list[i].getStartTime().hour << "h" << list[i].getStartTime().minute << "," << list[i].getEndTime().hour << "h" << list[i].getEndTime().minute << "," << list[i].getDoW() << endl;
	}
	
	fo.close();
}

void add_new_course(vector<Course>& list) {
	string buffer;
	Course temp;
	cout << "Course Code: ";
	getline(cin, buffer, '\n');
	for (int i = 0; i < list.size(); ++i) {
		if (buffer == list[i].getCourseCode()) {
			cerr << "This Course is already existed" << endl;
			return;
		}
	}

	temp.setCourseCode(buffer);

	cout << "Name of the course: ";
	getline(cin, buffer, '\n');
	temp.setName(buffer);

	cout << "Lecturer's Username: ";
	getline(cin, buffer, '\n');
	temp.setLecUsername(buffer);

	cout << "Course year: ";
	getline(cin, buffer, '\n');
	temp.setYear(buffer);

	cout << "Semester: ";
	getline(cin, buffer, '\n');
	temp.setSemester(stoi(buffer));

	date date_temp;
	cout << "Start Date (format dd/mm/yyyy): ";
	getline(cin, buffer, '/');
	date_temp.day = stoi(buffer);
	getline(cin, buffer, '/');
	date_temp.month = stoi(buffer);
	getline(cin, buffer, '\n');
	date_temp.year = stoi(buffer);
	temp.setStartDate(date_temp);

	cout << "End Date (format dd/mm/yyyy): ";
	getline(cin, buffer, '/');
	date_temp.day = stoi(buffer);
	getline(cin, buffer, '/');
	date_temp.month = stoi(buffer);
	getline(cin, buffer, '\n');
	date_temp.year = stoi(buffer);
	temp.setEndDate(date_temp);

	ttime time_temp;
	cout << "Course Start Time (format hh:mm): ";
	getline(cin, buffer, ':');
	time_temp.hour = stoi(buffer);
	getline(cin, buffer, '\n');
	time_temp.minute = stoi(buffer);
	temp.setStartTime(time_temp);

	cout << "Course End Time (format hh:mm): ";
	getline(cin, buffer, ':');
	time_temp.hour = stoi(buffer);
	getline(cin, buffer, '\n');
	time_temp.minute = stoi(buffer);
	temp.setEndTime(time_temp);

	cout << "Course DoW: ";
	getline(cin, buffer, '\n');
	temp.setDoW(stoi(buffer));

	list.push_back(temp);
}

void remove_course(vector<Course>& list) {
	cout << "Input Course ID to remove: ";
	string buffer;
	getline(cin, buffer, '\n');

	bool remove_flag = false;
	for (int i = 0; i < list.size(); ++i) {
		if (list[i].getCourseCode() == buffer) {
			list.erase(list.begin() + i);
			remove_flag = true;
			break;
		}
	}
	if (!remove_flag) {
		cerr << "This Course is not existed" << endl;
	}
}

vector<string> read_directory() {
	vector<string> list;
	string search_path = ".\\Classes\\*.*";
	WIN32_FIND_DATA fd;
	string temp;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				temp = fd.cFileName;
				temp.pop_back();
				temp.pop_back();
				temp.pop_back();
				temp.pop_back();
				list.push_back(temp);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return list;
}

//check if c2 is collided with c1
bool isCollied(Course &c1, Course &c2) {
	if (c1.getLecUsername() == c2.getLecUsername()) {
		if (c1.getDoW() == c2.getDoW()) {
			if (collidedDate(c1.getStartDate(), c2.getStartDate(), c1.getEndDate(), c2.getEndDate())) {
				if (collidedTime(c1.getStartTime(), c2.getStartTime(), c1.getEndTime(), c2.getEndTime())) {
					return true;
				}
			}
		}
	}
	return false;
}

void import_scoreboard(string course, Scoreboard &list) {
	ifstream fi(".\\Scores\\" + course + ".csv");
	if (!fi) {
		cerr << "Course Scoreboard not exit" << endl;
		return;
	}
	string buffer;
	
	list.Course_code = course;
	getline(fi, buffer, ',');
	list.semester = stoi(buffer);
	getline(fi, buffer, ',');
	list.year = stoi(buffer);
	getline(fi, buffer, '\n');
	buffer.clear();
	list.data.clear();
	
	string ID;
	getline(fi, buffer, '\n');
	buffer.clear();
	score_list temp;
	while (!fi.eof()) {
		getline(fi, ID, ',');
		if (ID == "") break;
		getline(fi, buffer, ',');
		temp.midterm = stod(buffer);
		getline(fi, buffer, ',');
		temp.lab = stod(buffer);
		getline(fi, buffer, '\n');
		temp.final = stod(buffer);
		Score score(ID, temp);
		list.data.push_back(score);
	}
	fi.close();
}

void export_scoreboard(Scoreboard &list) {
	ofstream fo(".\\Scores\\" + list.Course_code + ".csv");
	if (!fo) {
		cerr << "cant write to/create course's score file" << endl;
		return;
	}
	fo << list.semester << " " << list.year << ",," << endl << "ID,Midterm,Lab,Final" << endl;
	for (auto it = list.data.begin(); it != list.data.end(); ++it) {
		fo << it->ID << "," << it->score.midterm << "," << it->score.lab << "," << it->score.final << endl;
	}
	fo.close();
}

void import_attendance(string course, Attendance &list) {
	ifstream fi(".\\Attendance\\" + course + ".csv");
	if (!fi) {
		cerr << "Course not found" << endl;
		return;
	}
	string buffer, name, ID;
	list.Course_code = course;
	bool data[10];
	getline(fi, buffer, '\n');
	while (!fi.eof()) {
		getline(fi, ID, ',');
		getline(fi, name, ',');
		for (int i = 0; i < 10; ++i) {
			if (i == 9) getline(fi, buffer, '\n');
			else getline(fi, buffer, ',');
			data[i] = buffer == "V" ? true : false;
		}
		Presence temp(ID, name, data);
		list.attendance_list.push_back(temp);
	}
}

void export_attendance(Attendance &list) {
	ofstream fo(".\\Attendance\\" + list.Course_code + ".csv");
	if (!fo) {
		cerr << "Error loading file" << endl;
		return;
	}
	fo << "ID,Name,1,2,3,4,5,6,7,8,9,10" << endl;
	for (auto&& i : list.attendance_list) {
		fo << i.ID << "," << i.name << ",";
		for (int j = 0; j < 10; ++j) {
			char out = i.check_in[j] ? 'V' : 'A';
			if (j == 9) fo << out << endl;
			else fo << out << ",";
		}
	}
}
