#pragma once
enum STATE { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
STATE key(int z);
int menu(int n);
void frame();
void addcourseframe(int x, int y, int z, int v, int j, int k, int m);
int menucourse(int n);
int menueditcourse(int n);
int st_menu(int n,User *user);
int viewscore(int n, User *user, Scoreboard &temp, string course);
int viewsch(int n, User *user, string path, vector<Course> &list);
