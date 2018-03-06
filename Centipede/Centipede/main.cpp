/*
	Project Title : Centipede
	Date : 1/24/2018
	Description : Recreate classic arcade game centipede for use with a 
	trackball controller for later use in arcade cabinet
*/

#include "stdafx.h"
#include <ctime>
#include "CentipedeGame.h"


int main()
{

	const sf::Vector2u winDim(16*30, 16*30);

	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(winDim.x, winDim.y), "Centipede");
	CentipedeGame game(&window, winDim);

	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	sf::Event event;
	while (window.isOpen())
	{
		window.pollEvent(event);

		game.update();

		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed)
			window.close();
		else if (event.type == sf::Event::Resized)//resize to keep original aspect ratio
			window.setSize(sf::Vector2u(event.size.width, event.size.width));
	}

	return 0;
}