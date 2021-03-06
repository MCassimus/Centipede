/*
	Project Title : Centipede
	Date : 1/24/2018
	Description : Recreate classic arcade game centipede for use with a 
	trackball controller for later use in arcade cabinet
*/

#include "stdafx.h"
#include <ctime>
#include "CentipedeGame.h"
using namespace std;


int main()
{

	std::time_t seed = time(NULL);
	srand(seed);

	const sf::Vector2u winDim(480, 504);

	sf::RenderWindow window(sf::VideoMode(winDim.x, winDim.y), "Centipede");

	CentipedeGame game(&window, winDim);

	sf::Texture startingScreen;
	startingScreen.loadFromFile("../Sprites/startscreen.png");

	sf::Sprite sprite;
	sprite.setTexture(startingScreen);
	sprite.setScale(1.95f, 2.05f);

	window.draw(sprite);
	window.display();

	window.setFramerateLimit(60);
	//window.setKeyRepeatEnabled(false);

	bool frameByFrameMode(false), enterPressed(false);
	bool gameStart = false;

	sf::Event event;

	while (window.isOpen())
	{
		if (sf::Mouse::getPosition(window).x > 185 &&
			sf::Mouse::getPosition(window).x < 305 &&
			sf::Mouse::getPosition(window).y > 335 &&
			sf::Mouse::getPosition(window).y < 385 &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			gameStart = true;
			window.setMouseCursorVisible(false);
		}

		if (frameByFrameMode && gameStart) {
			if (enterPressed) {
				game.update();
				enterPressed = false;
			}
		}
		else if (gameStart)
			game.update();


		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)//resize to keep original aspect ratio
				window.setSize(sf::Vector2u(event.size.width, event.size.width * 1.05));
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				else if (event.key.code == sf::Keyboard::F1)
					frameByFrameMode = !frameByFrameMode;
				else if (event.key.code == sf::Keyboard::Return)
					enterPressed = true;
		}
	}
	
	return 0;
}