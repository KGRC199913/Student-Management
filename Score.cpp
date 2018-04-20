#include "Score.h"



Score::Score(string ID, score_list score)
{
	this->ID = ID;
	this->score = score;
}


Score::~Score()
{
	this->ID.clear();
}

