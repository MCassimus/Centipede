#include "stdafx.h"
#include "ScoreBoi.h"



ScoreBoi::ScoreBoi()
{
}


std::string ScoreBoi::getScoreX(int place)
{
	score_in_file.open("scores.txt");
	if (score_in_file.is_open())
	{
		int count = 0;
		while (getline(score_in_file, inStuff))//gets lines untill it gets the line asked for
		{
			if (count != place)
				inStuff.clear();
			else
			{
				score_in_file.close();
				return inStuff;
			}
			count++;
		}
	}
	else
		std::cout << "file error\n";

	return "This is a default string";
}


void ScoreBoi::addScore(std::string score)
{
	int newScoreInt, oldScoreInt;
	newScoreInt = cutScore(score);
	std::string scores[8];
	bool shifting = false;
	std::string temp1, temp2;

	for (int i = 0; i < 8; i++)//finds where the to place new score
	{
		if (!shifting)
		{
			oldScoreInt = cutScore(getScoreX(i));

			if (newScoreInt > oldScoreInt)
			{
				for (int z = 0; z < 8; z++)
				{
					scores[z] = getScoreX(z);
				}

				temp1 = scores[i];
				scores[i] = score;
				shifting = true;
			}
		}
		else
		{
			temp2 = scores[i];
			scores[i] = temp1;
			temp1 = temp2;
		}
	}
	score_out_file.open("scores.txt", std::ofstream::out | std::ofstream::trunc);//replaces file with new order
	if (score_out_file.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			score_out_file << scores[i] << "\n";
		}
	}
	else
		std::cout << "file out not opened\n";

	return;
}


void ScoreBoi::addScore(int score, std::string name)
{
	int oldScoreInt;
	std::string scores[8];
	bool shifting = false;
	std::string temp1, temp2;

	std::string scoreTotal = std::to_string(score) + " " + name;

	for (int i = 0; i < 8; i++)//finds where the to place new score
	{
		if (!shifting)
		{
			oldScoreInt = cutScore(getScoreX(i));

			if (score > oldScoreInt)
			{
				for (int z = 0; z < 8; z++)
				{
					scores[z] = getScoreX(z);
				}

				temp1 = scores[i];
				scores[i] = scoreTotal;
				shifting = true;
			}
		}
		else
		{
			temp2 = scores[i];
			scores[i] = temp1;
			temp1 = temp2;
		}
	}
	score_out_file.open("scores.txt", std::ofstream::out | std::ofstream::trunc);//replaces file with new order
	if (score_out_file.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			score_out_file << scores[i] << "\n";
		}
	}
	else
		std::cout << "file out not opened\n";

	return;
}


int ScoreBoi::cutScore(std::string score)//helper function
{
	int scoreInt = std::stoi(score.substr(0, 6));
	return scoreInt;
}


ScoreBoi::~ScoreBoi()
{
}