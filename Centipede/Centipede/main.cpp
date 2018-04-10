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
	srand(time(NULL));

	const sf::Vector2u winDim(480, 504);
	
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
		if (event.type == sf::Event::Resized)//resize to keep original aspect ratio
			window.setSize(sf::Vector2u(event.size.width, event.size.width * 1.05));
		if (event.type == sf::Event::KeyPressed)
			if(event.key.code == sf::Keyboard::Escape)
				window.close();
	}

	return 0;
}