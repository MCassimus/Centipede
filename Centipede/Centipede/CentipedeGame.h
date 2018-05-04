#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Flea.h"
#include <fstream>
#include <memory>

class CentipedeManager;

class CentipedeGame
{
public:
	CentipedeGame(sf::RenderWindow *, const sf::Vector2u);
	~CentipedeGame();
	bool update();
	void draw();
	static bool isMushroomCell(unsigned int, unsigned int);
	void reset();
	void placeObject(unsigned int, unsigned int, std::shared_ptr<GameObject>);
	sf::Vector2i getRelMousePos();

	template <typename type> std::shared_ptr<type> spawnObject(unsigned int x, unsigned int y) {
		std::shared_ptr<type> thing(nullptr);
		if (isInBounds(x, y)) {
			thing = std::make_shared<type>(x, y);
			map[y][x][frame].push_back(thing);
		}
		return thing;
	};

	static unsigned int clock;

	unsigned int getCountOf(char*, unsigned int, unsigned int, unsigned int, unsigned int);

private:
	void resolveCollisions();
	void generateGrid();

	void manageCentipedePopulation();
	static bool isInBounds(unsigned int x, unsigned int y) { return x < 30 && y < 30; }

	void kill(std::shared_ptr<GameObject>&);
	sf::VertexArray linePoints;

	static bool frame;
	static std::vector<std::shared_ptr<GameObject>> map[30][30][2];
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

	CentipedeManager *centMan;

	template <class type> std::shared_ptr<type> findFirstInstanceOf() {
		std::shared_ptr<type> instance = nullptr;
		for (int y = 0; y < 30; ++y)
			for (int x = 0; x < 30; ++x)
				for (int i = 0; i < map[y][x][frame].size(); ++i)
					if (std::dynamic_pointer_cast<type>(map[y][x][frame].at(i)))
						instance = std::dynamic_pointer_cast<type>(map[y][x][frame].at(i));
		return instance;
	}
};