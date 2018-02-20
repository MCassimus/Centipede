#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	Player(sf::RenderWindow *);
	void update();
	~Player();
protected:
	int health = 3;
	sf::Vector2u currentPosition = sf::Vector2u(15, 30);
	std::vector<sf::RectangleShape> bullets;
	sf::Vector2u interval, originalDimensions;
};