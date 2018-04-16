#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Flea.h"
#include <fstream>

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

	unsigned int getCountOf(char*, unsigned int, unsigned int, unsigned int, unsigned int);

private:
	void resolveCollisions();
	void generateGrid();

	void manageCentipedePopulation();

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
	
	sf::Texture lifeTexture;
	sf::Sprite lives[6];
	sf::RenderTexture playerArea;
	sf::RenderTexture scoreArea;
	sf::Sprite playerAreaSprite;
	sf::Sprite scoreAreaSprite;
<<<<<<< HEAD
	sf::Sprite startingScreen;
=======

	void drawLives();

	bool activeCentipede = false;
<<<<<<< HEAD
>>>>>>> 2f0cc4332c3ffd1b41e9d1fa34e33744329fe40c
=======

	std::ifstream score_in_file;
	std::ofstream score_out_file;

>>>>>>> 9203cc4b9c9caafa0fc35495220938fa9965cac7
};