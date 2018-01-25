#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "Mushroom.h"
#include "CentipedeSegment.h"
#include "Scorpion.h"
#include "Spider.h"
#include "Player.h"
#include "Flea.h"


class CentipedeGame
{
public:
	CentipedeGame(sf::RenderWindow *);
	~CentipedeGame();
	bool loop();
	void reset();
private:
	sf::Clock clock;
	sf::RenderWindow * window = nullptr;
	std::vector<Mushroom *> mushrooms;
	std::vector<CentipedeSegment *> centipedes;
	Scorpion * scorpion = nullptr;
	Spider * spider = nullptr;
	Flea * flea = nullptr;
	Player * player = nullptr;
};