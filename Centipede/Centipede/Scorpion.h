#pragma once
#include "GameObject.h";


class Scorpion: public GameObject
{
public:
	Scorpion();
	~Scorpion();
	void update();
private:
	int pointValue;
};