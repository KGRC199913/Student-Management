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
	if (password == "000") {
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

	//unfinished
	//read from data file to get name, phone & class/type (depend)
	//temporary login set
	if (isdigit(username[0])) {
		User temp(username, "Pham Hoang Anh Tuan", "000000000000", "17CLC3");
		*user = temp;
	}
	else {
		User temp("Ho Tuan Thanh", "????????????", 2);
		*user = temp;
	}

	//

	loginDat.close();
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