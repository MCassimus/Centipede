#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Flea.h"
#include "CentipedeManager.h"
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

	template <typename type> static void spawnObject(unsigned int, unsigned int);
	

	static unsigned int clock;

	unsigned int getCountOf(char*, unsigned int, unsigned int, unsigned int, unsigned int);

private:
	void resolveCollisions();
	void generateGrid();

	void manageCentipedePopulation();
	static bool isInBounds(unsigned int x, unsigned int y) { return x < 30 && y < 30; }

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
	sf::Sprite startingScreen;

	void drawLives();

	bool activeCentipede = false;

	std::ifstream score_in_file;
	std::ofstream score_out_file;

	CentipedeManager centMan;
};

template<typename type>
inline void CentipedeGame::spawnObject(unsigned int x, unsigned int y)
{
	this;

	if (isInBounds(x, y))
		map[y][x][frame].push_back(type(playerArea, x, y));
}