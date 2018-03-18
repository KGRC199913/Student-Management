#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "console.h"
#define TEXTCOLOR 64
#define BGCOLOR 70
using namespace std;
typedef char str[30];
str menu1[4] = { "USER","COURSE","PRESENCE","SCORE" };
enum STATE{UP,DOWN,LEFT,RIGHT,ENTER,BACK};
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
int menu(str menu1[4], int n)
{
	int st = 0;//Bien chi dang o thao tac thu nhat
	int *color = new int[n];
	for (int i = 0; i < n; i++)
		color[i] = TEXTCOLOR;
	color[0] = BGCOLOR;//thao tac thu nhat
	while (true)
	{
		clrscr();
		gotoXY(0, 1);
		TextColor(70);
		cout << "=========================================================MENU===========================================================" << endl;
		for (int i = 0; i < n; i++)
		{
			TextColor(color[i]);
			cout << "\n\n" << endl;
			cout << "\t\t\t\t\t\t\t"<<i + 1 << "." << menu1[i] << endl;
		}
		TextColor(70);
		gotoXY(0, 28);
		cout << "========================================================================================================================" << endl;
		int z = _getch();
		STATE state = key(z);
		switch (state)
		{
		case UP:
		{
			if (st == 0)
			{
				st == n - 1;
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
				st == 0;
			}
			else
			{

				st++;
			}
			break;

		}
		case ENTER:
			return st;
		}
		for (int i = 0; i < n; i++)
			color[i] = TEXTCOLOR;
		color[st] = BGCOLOR;

	}
}
int main()
{
	system("color 49");
	menu(menu1, 4);
	system("pause");
}

