#pragma once
#include "GameObject.h"


class Scorpion: public GameObject
{
public:
	Scorpion(sf::RenderWindow *);
	~Scorpion();
	void update();
	void collides(GameObject*);
private:
	int pointValue;
	int scuttle; // bool for walking animation
};