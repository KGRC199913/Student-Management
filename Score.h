#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct score_list {
	double midterm, lab, final;
};
class Score
{
public:
	string ID;
	score_list score;
	Score(string ID, score_list score);
	~Score();
};


class Scoreboard {
public:
	string Course_code;
	int year;
	int semester;
	vector<Score> data;
};