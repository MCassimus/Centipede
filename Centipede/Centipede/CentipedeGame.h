#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Flea.h"

class CentipedeGame
{
public:
	CentipedeGame(sf::RenderWindow *, const sf::Vector2u);
	~CentipedeGame();
	bool update();
	void draw();
	static bool isMushroomCell(unsigned int, unsigned int);
	void reset();
	static void placeObject(unsigned int, unsigned int, GameObject *);
	static unsigned int clock;
private:
	void resolveCollisions();
	void generateGrid();

	static void kill(GameObject*);
	sf::VertexArray linePoints;

	static bool frame;
	static std::vector<GameObject *> map[30][30][2];
	sf::RenderWindow * window = nullptr;
	const sf::Vector2u originalWindowDimensions;
	static unsigned int score;
	static int playerLives;

	sf::Font arcadeFont;
	sf::Text scoreDisplay;
	sf::RenderTexture playerArea;
	sf::RenderTexture scoreArea;
	sf::Sprite playerAreaSprite;
	sf::Sprite scoreAreaSprite;
	sf::Sprite startingScreen;
};