#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>


class ScoreBoi
{
public:
	ScoreBoi();
	std::string getScoreX(int);// recieves an int that is the place for a score and returns that score
	void addScore(std::string);
	void addScore(int, std::string);
	~ScoreBoi();
private:
	std::ifstream score_in_file;
	std::ofstream score_out_file;
	std::string inStuff;
	int cutScore(std::string);
};