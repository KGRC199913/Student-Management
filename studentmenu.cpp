#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "User.h"
#include "Course.h"
#include "Presence.h"
#include "Score.h"
#include "GeneralFeatures.h"
#include "console.h"
#include "menu.h"
#include <conio.h>
#include "Academic_staff_features.h"
#define TEXTCOLOR 48
#define BGCOLOR 55
using namespace std;
//ham xac dinh phim bam va dieu khien menu
int st_menu(int n,User *user)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	str menu1[4] = {"CHECKIN RESULT","SCOREBOARD","SCHEDULES","LOGOUT" };
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
	vector<Course> test1;
	import_course("3.csv", test1);
	while (true)
	{
		clrscr();
		gotoXY(0, 0);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		TextColor(58);
		gotoXY(57, 1);
		cout << "MENU" << endl;
		gotoXY(0, 2);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		for (int i = 0; i < n - 1; i++)
		{
			TextColor(color[i]);
			cout << "\n\n" << endl;
			cout << "\t\t\t\t\t\t\t" << i + 1 << "." << menu1[i] << endl;
		}
		TextColor(color[n - 1]);
		gotoXY(4, 23);
		cout << menu1[n - 1] << endl;
		gotoXY(0, 26);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(0, 28);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		int z = _getch();
		STATE state = key(z);
		switch (state)
		{
		case UP:
		{
			if (st == 0)
			{
				st = n - 1;
			}
			else
			{
				st--;
			}
			break;
		}
		case DOWN:
		{
			if (st == n - 1)
			{
				st = 0;
			}
			else
			{

				st++;
			}
			break;

		}
		case ENTER:
			if (st == 0)
			{
				system("cls");
				frame();
				string x;
				gotoXY(45, 13);
				cout << "Enter course code:";
				getline(cin, x, '\n');
				import_course("Course.csv", test1);
				system("cls");
				frame();
				if (user->check_in(x, test1))
				{
					gotoXY(45, 13);
					cout << "SUCCESS";
				}
				else
				{
					gotoXY(45, 13);
					cout << "FAIL";
				}
				system("pause");
				system("cls");
			}
			if (st == 1)
			{
				system("cls");
				frame();
				string x;
				gotoXY(45, 13);
				cout << "Enter course code:";
				getline(cin, x, '\n');
				system("cls");
				Scoreboard temp;
				import_scoreboard(x, temp);
				viewscore(1, user, temp, x);
				//viewscore(x, temp,user);
			}
			if (st == 2)
				viewsch(1, user, "3.csv", test1);
			if (st == n - 1)
			{
				exit(0);
			}
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;

	}
	delete color;
}
int viewscore(int n, User *user, Scoreboard &temp, string course)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	str menu1[1] = { "BACK" };
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
	vector<Course> test1;
	import_course("3.csv", test1);
	while (true)
	{
		system("cls");
		ifstream fi(".\\Scores\\" + course + ".csv");
		if (!fi) {
			cerr << "Course Scoreboard not exit" << endl;
			return st_menu(5,user);
		}
		score_list list;
		gotoXY(0, 0);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		TextColor(58);
		gotoXY(57, 1);
		cout << course << endl;
		gotoXY(0, 2);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(0, 26);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(0, 28);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(40, 4);
		cout << "MIDTERM";
		gotoXY(55, 4);
		cout << "|";
		gotoXY(65, 4);
		cout << "LAB ";
		gotoXY(80, 4);
		cout << "|";
		gotoXY(85, 4);
		cout << "FINAL";
		gotoXY(95, 4);
		cout << "|";
		gotoXY(100, 4);
		cout << "BONUS";
		int k = 6;

		for (auto it = temp.data.begin(); it != temp.data.end(); ++it)
		{
			if (it->ID == user->getUsername())
			{
				gotoXY(40, k);
				cout << it->score.midterm;
				gotoXY(55, k);
				cout << "|";
				gotoXY(65, k);
				cout << it->score.lab;
				gotoXY(80, k);
				cout << "|";
				gotoXY(85, k);
				cout << it->score.final;
				gotoXY(95, k);
				cout << "|";
				gotoXY(100, k);
				cout << it->score.bonus;
			}
		}
		fi.close();
		TextColor(color[n - 1]);
		gotoXY(4, 23);
		cout << menu1[n - 1] << endl;
		int z = _getch();
		STATE state = key(z);
		switch (state)
		{
		case UP:
		{
			if (st == 0)
			{
				st = n - 1;
			}
			else
			{
				st--;
			}
			break;
		}
		case DOWN:
		{
			if (st == n - 1)
			{
				st = 0;
			}
			else
			{

				st++;
			}
			break;

		}
		case ENTER:
		{
			if (st == n - 1)
				st_menu(4, user);
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;
		}
	}
	delete color;
}

int viewsch(int n, User *user, string path, vector<Course> &list)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	str menu1[1] = { "BACK" };
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
	import_course("3.csv", list);
	while (true)
	{
		system("cls");
		ifstream fi(path);
		if (!fi) {
			cerr << "Course Schedule not exit" << endl;
			return st_menu(5, user);
		}
		gotoXY(0, 0);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		TextColor(58);
		gotoXY(57, 1);
		cout << "SCHEDULE" << endl;
		gotoXY(0, 2);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(0, 26);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(0, 28);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		gotoXY(2, 4);
		cout << "Course Code ";
		gotoXY(15, 4);
		cout << "|";
		gotoXY(20, 4);
		cout << "Lecture name ";
		gotoXY(34, 4);
		cout << "|";
		gotoXY(37, 4);
		cout << "Start Date ";
		gotoXY(50, 4);
		cout << "|";
		gotoXY(55, 4);
		cout << "End Date";
		gotoXY(70, 4);
		cout << "|";
		gotoXY(75, 4);
		cout << "Start Hour ";
		gotoXY(90, 4);
		cout << "|";
		gotoXY(95, 4);
		cout << "End Hour ";
		gotoXY(105, 4);
		cout << "|";
		gotoXY(110, 4);
		cout << "DoW";
		int k = 6;
		for (int i = 0; i < list.size()-5; ++i) 
		{
			gotoXY(2, k);
			cout << list[i].getCourseCode();
			gotoXY(15, k);
			cout << "|";
			gotoXY(20, k);
			cout << list[i].getLecUsername();
			gotoXY(34, k);
			cout << "|";
			gotoXY(37, k);
			cout << list[i].getStartDate().day << "/" << list[i].getStartDate().month << "/" << list[i].getStartDate().year;
			gotoXY(50, k);
			cout << "|";
			gotoXY(55, k);
			cout << list[i].getEndDate().day << "/" << list[i].getEndDate().month << "/" << list[i].getEndDate().year;
			gotoXY(70, k);
			cout << "|";
			gotoXY(75, k);
			cout << list[i].getStartTime().hour << "h" << list[i].getStartTime().minute;
			gotoXY(90, k);
			cout << "|";
			gotoXY(95, k);
			cout << list[i].getEndTime().hour << "h" << list[i].getEndTime().minute;
			gotoXY(105, k);
			cout << "|";
			gotoXY(111, k);
			cout << list[i].getDoW() << endl;
			k++;
		}
		TextColor(color[n - 1]);
		fi.close();
		gotoXY(4, 23);
		cout << menu1[n - 1] << endl;
		int z = _getch();
		STATE state = key(z);
		switch (state)
		{
		case UP:
		{
			if (st == 0)
			{
				st = n - 1;
			}
			else
			{
				st--;
			}
			break;
		}
		case DOWN:
		{
			if (st == n - 1)
			{
				st = 0;
			}
			else
			{

				st++;
			}
			break;

		}
		case ENTER:
		{
			if (st == n - 1)
				st_menu(4, user);
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;
		}
	}
	delete color;
}