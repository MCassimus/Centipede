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
	do
	{
		window.pollEvent(event);
		if (event.type == sf::Event::EventType::Closed)
			window.close();

		game.draw();
	} while (game.update() && window.isOpen());


	window.close();
	return 0;
}