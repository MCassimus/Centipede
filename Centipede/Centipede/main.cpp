/*
	Project Title : Centipede
	Date : 1/24/2018
	Description : Recreate classic arcade game centipede for use with a 
	trackball controller for later use in arcade cabinet
*/

#include "stdafx.h"
#include "CentipedeGame.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(240, 256), "Centipede");
	CentipedeGame game(&window);	

	sf::Event event;
	while (window.isOpen())
	{
		game.update();

		//events for window
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::Resized)//resize to keep original aspect ratio
			window.setSize(sf::Vector2u(event.size.width, event.size.width * 1.066));
	}

	return 0;
}