#pragma once
#include "GameObject.h"


class Scorpion: public GameObject
{
public:
	Scorpion(sf::RenderWindow *);
	~Scorpion();
	void update();
	void collideWith(GameObject*);
private:
	int pointValue;
	int scuttle; // for walking animation
	
	unsigned int frameMax = 40;
};