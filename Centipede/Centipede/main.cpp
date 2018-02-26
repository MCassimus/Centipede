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
	srand(static_cast<unsigned int>(time(NULL)));

	const sf::Vector2u originalWindowDimensions(16*30, 16*30);

	sf::RenderWindow window(sf::VideoMode(originalWindowDimensions.x, originalWindowDimensions.y), "Centipede");
	CentipedeGame game(&window, originalWindowDimensions);	

	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	sf::Event event;
	while (window.isOpen())
	{

		//events for window
		window.pollEvent(event);


		game.update();

		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::Resized)//resize to keep original aspect ratio
			window.setSize(sf::Vector2u(event.size.width, event.size.width));
	}

	return 0;
}