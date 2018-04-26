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


//StartScreen stuff
/*	sf::Texture startingScreen;
	startingScreen.loadFromFile("../Sprites/startscreen.png");

	sf::Sprite sprite;
	sprite.setTexture(startingScreen);
	sprite.setScale(1.95f, 2.05f);

	sf::Mouse::getPosition(window);

	sf::RectangleShape startButton(sf::Vector2f(120, 50));
	startButton.setFillColor(sf::Color(100, 250, 50));
	startButton.setPosition(185, 335);

	sf::FloatRect boundingBox = startButton.getGlobalBounds();


	window.draw(sprite);
	window.draw(startButton);
	*/window.display();

	CentipedeGame game(&window, winDim);

	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	//window.setKeyRepeatEnabled(false);

	bool frameByFrameMode(false), enterPressed(false);

	sf::Event event;
	while (window.isOpen())
	{

		if (frameByFrameMode) {
			if (enterPressed) {
				game.update();
				enterPressed = false;
			}
		}
		else 
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

	system("pause");

	return 0;
}