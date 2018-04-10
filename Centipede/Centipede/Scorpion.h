#pragma once
#include "GameObject.h"


class Scorpion: public GameObject
{
public:
	Scorpion(sf::RenderWindow *, int, int);
	~Scorpion();
	void update();
	void collideWith(GameObject*);
	char* getType() { return "Scorpion"; }
private:
	int scuttle; // for walking animation
	
	unsigned int frameMax = 40;
};