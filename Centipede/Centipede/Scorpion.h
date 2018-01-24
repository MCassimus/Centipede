#pragma once
#include "GameObject.h";


class Scorpion: public GameObject
{
public:
	Scorpion();
	void update();
	~Scorpion();
private:
	int pointValue;
};

