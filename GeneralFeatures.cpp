#include "GeneralFeatures.h"


using namespace std;

void login(User* &user) {
	ifstream loginDat;
	loginDat.open("LoginDat.csv", ios::in);
	string buffer;
	getline(loginDat, buffer, '\n');
	getline(loginDat, buffer, '\n');
	buffer.clear();

	string username, password, infofile;
	bool usernameFound = false;
	while (!usernameFound) {		
		cout << "Username: ";
		getline(cin, buffer, '\n');
		while (!loginDat.eof()) {
			getline(loginDat, username, ',');
			getline(loginDat, password, ',');
			getline(loginDat, infofile, '\n');
			if (buffer == username) {
				usernameFound = true;
				break;
			}
		}
		if (!usernameFound) {
			system("cls");
			cout << "username not found" << endl;
			loginDat.clear();
			loginDat.seekg(0, ios::beg);
			getline(loginDat, buffer, '\n');
			getline(loginDat, buffer, '\n');
			buffer.clear();
		}
	}
	loginDat.close();
	//Password
	User* fake_user = new User();
	fake_user->setUsername(username);
	string tmm = sha256("000");
	if (password == tmm) {
		cout << "This is your first login, please change your password" << endl;
		resetPassword(fake_user);
		password = fake_user->getPassword();
		delete fake_user;
	}
	else {
		cout << "Password: ";
		getline(cin, buffer, '\n');
		string hash_buffer = sha256(buffer);
		while (hash_buffer != password) {
			system("cls");
			cout << "Wrong password!!" << endl;
			cout << "Username: " << username << endl;
			cout << "Password: ";
			getline(cin, buffer, '\n');
			hash_buffer = sha256(buffer);
		}
	}
	
	//end of password
	loginDat.close();
	//unfinished
	//read from data file to get name, phone & class/type (depend)
	//temporary login set

	if (isdigit(username[0])) {
		infofile = ".\\Classes\\" + infofile;
		ifstream info;
		info.open(infofile, ios::in);
		infofile.pop_back();
		infofile.pop_back();
		infofile.pop_back();
		infofile.pop_back();
		string fname, email, mobilePhone;
		getline(info, buffer, '\n');
		getline(info, buffer, '\n');
		while (!info.eof()) {
			getline(info, buffer, ',');
			getline(info, buffer, ',');
			if (buffer == username) {
				getline(info, fname, ',');
				getline(info, email, ',');
				getline(info, mobilePhone, '\n');
				user = new User(username, fname, mobilePhone, infofile);
				user->setPassword(password);
			}
		}
	}
	else {
		ifstream info;
		info.open(infofile, ios::in);
		getline(info, buffer, '\n');
		while (!info.eof()) {
			getline(info, buffer, ',');
			if (buffer == username) {
				string phone, temp;
				getline(info, phone, ',');
				getline(info, temp, '\n');
				char type = temp[0];
				user = new User(username, phone, type);
				user->setPassword(password);
			}
			else getline(info, buffer, '\n');
		}
	}
	return;
}


void resetPassword(User* user) {
	string pass, pass_same;
	cout << "Please enter your new password: ";
	getline(cin, pass, '\n');
	cout << "Please re-enter your new password: ";
	getline(cin, pass_same, '\n');
	
	
	user->setPassword(pass);
	while (!user->checkLegitPassword(pass_same))
	{
		cout << "Please enter another password: ";
		getline(cin, pass, '\n');
		cout << "Please re-enter your new password: ";
		getline(cin, pass_same, '\n');
		user->setPassword(pass);
	}
	cout << "Password was changed successfully" << endl;
	ifstream loginDat("loginDat.csv");
	ofstream temp_new_login("loginDat.csv.tmp");
	string buffer;
	getline(loginDat, buffer, '\n');
	temp_new_login << buffer << endl;
	getline(loginDat, buffer, '\n');
	temp_new_login << buffer << endl;
	while (!loginDat.eof()) {
		getline(loginDat, buffer, ',');
		if (buffer == "") break;
		if (buffer == user->getUsername()) {
			temp_new_login << buffer << ',' << sha256(user->getPassword()) << ',';
			getline(loginDat, buffer, ',');
			getline(loginDat, buffer, '\n');
			temp_new_login << buffer << endl;
		}
		else {
			temp_new_login << buffer << ',';
			getline(loginDat, buffer, ',');
			temp_new_login << buffer << ',';
			getline(loginDat, buffer, '\n');
			temp_new_login << buffer << endl;
		}
	}
	loginDat.close();
	temp_new_login.close();
}

bool fexist(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}