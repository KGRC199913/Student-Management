#include "GeneralFeatures.h"


using namespace std;

void login(User* user) {
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
	
	//Password
	if (password == sha256("000")) {
		cout << "This is your first login, please change your password" << endl;
		resetPassword(user);
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
				User temp(username, fname, mobilePhone, infofile);
				*user = temp;
				user->setPassword(password);
			}
		}
	}
	else {

	}
	



	//

	
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
}

bool fexist(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}