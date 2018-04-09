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
enum STATE { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
//ham xac dinh phim bam va dieu khien menu
STATE key(int z)
{
	if (z == 224)
	{
		char c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (z == 13)
		return ENTER;
}
int menu(int n)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	str menu1[5] = { "USER","COURSE","PRESENCE","SCORE","LOGOUT" };
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
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
		TextColor(color[4]);
		gotoXY(4, 23);
		cout << menu1[4] << endl;
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
				return st;
			if (st == 1)
				menucourse(5);
			if (st == n - 1)
			{
				exit(0);
			}
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;

	}
	delete []color;
}
void frame()
{
	gotoXY(2, 1);
	for (int i = 0; i < 115; i++)
	{
		TextColor(7);
		printf("%c", 219);
	}
	int j = 2;
	for (int i = 0; i < 27; i++)
	{
		gotoXY(2, j);
		TextColor(7);
		printf("%c%c\n", 219, 219);
		j++;
	}
	gotoXY(2, 28);
	for (int i = 0; i < 115; i++)
	{
		TextColor(7);
		printf("%c", 219);
	}
	int k = 1;
	for (int i = 0; i < 28; i++)
	{
		gotoXY(116, k);
		TextColor(7);
		printf("%c%c\n", 219, 219);
		k++;
	}
	TextColor(TEXTCOLOR);
}
void addcourseframe(int x,int y, int z,int v, int j,int k,int m)
{
	//gotoXY(20, 3);
	gotoXY(x, y);
	for (int i = 0; i < z; i++)
	{
		TextColor(55);
		printf("%c", 95);
	}
	for (int i = 0; i < v; i++)
	{
		gotoXY(19, j);
		TextColor(55);
		printf("%c", 124);
		j++;
	}
	gotoXY(x, y+v);
	for (int i = 0; i < z; i++)
	{
		TextColor(55);
		printf("%c", 95);
	}
	for (int i = 0; i < v; i++)
	{
		gotoXY(x+z, k);
		TextColor(55);
		printf("%c", 124);
		k++;
	}
	for (int i = 0; i < v; i++)
	{
		gotoXY(x+35, m);
		TextColor(55);
		printf("%c", 124);
		m++;
	}
	TextColor(TEXTCOLOR);
}
int menucourse(int n)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	str menu1[5] = { "ADD NEW COURSE","EDIT COURSE","REMOVE COURSE","VIEW COURSE","BACK"};
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
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
		cout << "COURSE" << endl;
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
		TextColor(color[n-1]);
		gotoXY(4, 23);
		cout << menu1[n-1] << endl;
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
				vector<Course> add;
				add_new_course(add);
			}
			if (st == 1)
			{
				menueditcourse(11);
			}
			if (st == 2)
			{
				vector<Course> remove;
				remove_course(remove);
			}
			if (st == n - 1)
			{
				menu(5);
			}
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;

	}
	delete[]color;
}
int menueditcourse(int n)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	typedef char str[30];
	Course code;
	str menu1[11] = {"COURSE CODE","YEAR","SEMESTER","NAME","LECTURE NAME","START DATE","END DATE","START TIME","END TIME","DOW","BACK"};
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
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
		cout << "EDIT COURSE" << endl;
		gotoXY(0, 2);
		for (int i = 0; i < 120; i++)
		{
			TextColor(48);
			printf("%c", 61);
		}
		int k = 4;
		for (int i = 0; i < n - 1; i++)
		{
			TextColor(color[i]);
			gotoXY(55, k);
			cout<< i + 1 << "." << menu1[i] << endl;
			k=k+2;
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
				string x;
				frame();
				gotoXY(45, 10);
				cout << "Enter new code:" << endl;
				gotoXY(60, 10);
				getline(cin, x, '\n');
				code.setCourseCode(x);
				system("cls");
			}
			if (st == 1)
			{
				system("cls");
				string year;
				frame();
				gotoXY(45, 10);
				cout << "Enter new year:" << endl;
				gotoXY(60, 10);
				getline(cin, year, '\n');
				code.setYear(year);
				system("cls");
			}
			if (st == 2)
			{
				system("cls");
				string semester;
				frame();
				gotoXY(45, 10);
				cout << "Enter new semester:" << endl;
				gotoXY(65, 10);
				getline(cin, semester, '\n');
				code.setSemester(stoi(semester));
				system("cls");
			}
			if (st == 3)
			{
				system("cls");
				string name;
				frame();
				gotoXY(45, 10);
				cout << "Enter new course's name:" << endl;
				gotoXY(70, 10);
				getline(cin, name, '\n');
				code.setName(name);
				system("cls");
			}
			if (st == 4)
			{
				system("cls");
				string lname;
				frame();
				gotoXY(45, 10);
				cout << "Enter new course's lecture name:" << endl;
				gotoXY(78, 10);
				getline(cin, lname, '\n');
				code.setName(lname);
				system("cls");
			}
			if (st == 5)
			{
				system("cls");
				date stdate;
				string sdate;
				frame();
				gotoXY(30, 10);
				cout << "Enter New Start Date (format dd/mm/yyyy):";
				gotoXY(72, 10);
				getline(cin, sdate, '/');
				stdate.day = stoi(sdate);
				getline(cin, sdate, '/');
				stdate.month = stoi(sdate);
				getline(cin, sdate, '\n');
				stdate.year = stoi(sdate);
				code.setStartDate(stdate);
				system("cls");
			}
			if (st == 6)
			{
				system("cls");
				date endate;
				string edate;
				frame();
				gotoXY(30, 10);
				cout << "Enter New End Date (format dd/mm/yyyy):";
				gotoXY(70, 10);
				getline(cin, edate, '/');
				endate.day = stoi(edate);
				getline(cin, edate, '/');
				endate.month = stoi(edate);
				getline(cin, edate, '\n');
				endate.year = stoi(edate);
				code.setStartDate(endate);
				system("cls");
			}
			if (st == 7)
			{
				system("cls");
				time sttime;
				string stime;
				frame();
				gotoXY(30, 10);
				cout << "Enter New Course Start Time (format hh:mm):";
				gotoXY(72, 10);
				getline(cin, stime, ':');
				sttime.hour = stoi(stime);
				getline(cin, stime, '\n');
				sttime.minute = stoi(stime);
				code.setStartTime(sttime);
				system("cls");
			}
			if (st == 8)
			{
				system("cls");
				time entime;
				string etime;
				frame();
				gotoXY(30, 10);
				cout << "Enter New Course End Time (format hh:mm):";
				gotoXY(72, 10);
				getline(cin, etime, ':');
				entime.hour = stoi(etime);
				getline(cin, etime, '\n');
				entime.minute = stoi(etime);
				code.setStartTime(entime);
				system("cls");
			}
			if (st == 9)
			{
				system("cls");
				string dow;
				frame();
				gotoXY(45, 10);
				cout << "Enter new DoW:" << endl;
				gotoXY(60, 10);
				getline(cin, dow, '\n');
				code.setDoW(stoi(dow));
				system("cls");
			}
			if (st == n - 1)
			{
				menucourse(5);
			}
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;

	}
	delete[]color;
}
