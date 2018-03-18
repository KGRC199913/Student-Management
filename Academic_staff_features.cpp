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
	
	cout << "Input new class: ";
	getline(cin, buffer, '\n');
	if (!fexist(buffer + ".csv")) {
		cerr << "Class not found" << endl;
		return;
	}

	ifstream desfile(buffer + ".csv");
	int line = count(istreambuf_iterator<char>(desfile), istreambuf_iterator<char>(), '\n') - 2;
	desfile.close();

	ofstream fo;
	fo.open(buffer + ".csv", ios::app | ios::ate);
	
	string tempString = to_string(line + 1);
	if (tempString.size() < 2) fo << "0" << tempString << ",";
	else fo << tempString << ",";
	fo << temp.getUsername() << "," << temp.getFullName() << "," << temp.getEmail() << "," << temp.getMobilePhone() << endl;

	fo.close();
	remove_student(list, pos);
}