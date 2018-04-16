#include "stdafx.h"
#include "Mushroom.h"
#include "Spider.h"
#include "Scorpion.h"
#include "Bullet.h"

Mushroom::Mushroom(sf::RenderWindow* window, int x, int y) : GameObject(window, x, y)
{
	pointValue = 5;
	poisoned = false;
	health = 4;
	object.setOrigin(-2, -2);
	object.setScale(1.25, 1.25);
	soundClip.loadFromFile("../Audio/mushroomReset.ogg");
}


void Mushroom::update()
{
	switch (health)//changes texture based on health
	{
	case 1:
		setTexture("../Sprites/Mushroom/mushroom1.png");
		break;
	case 2:
		setTexture("../Sprites/Mushroom/mushroom2.png");
		break;
	case 3:
		setTexture("../Sprites/Mushroom/mushroom3.png");
		break;
	case 4:
		setTexture("../Sprites/Mushroom/mushroom4.png");
		break;
	}	

	if (poisoned)
		object.setColor(sf::Color::Magenta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		health = 0;
}


bool Mushroom::getPoisoned()//for centipede 
{
	return poisoned;
}


void Mushroom::resetHeath()//for end of level
{
		if (health < 4 && soundPlayer.getStatus() == sf::Sound::Stopped)
		{
			//set texture
			switch (health++)//changes texture based on health
			{
			case 1:
				setTexture("../Sprites/Mushroom/mushroom1.png");
				break;
			case 2:
				setTexture("../Sprites/Mushroom/mushroom2.png");
				break;
			case 3:
				setTexture("../Sprites/Mushroom/mushroom3.png");
				break;
			case 4:
				setTexture("../Sprites/Mushroom/mushroom4.png");
				break;
			}

			//play sound
			soundPlayer.play();
	}

	poisoned = false;
	return true;
}


void Mushroom::collideWith( GameObject* other ) //dynamic_cast returns null pointer if class
{                                               //is not what it is asked to change it to
	if (dynamic_cast<Spider*>(other) != nullptr)
	{
		pointValue = 0;
		health = 0;
	}
	if (dynamic_cast<Scorpion*>(other) != nullptr)
		poisoned = true;
	if (dynamic_cast<Bullet*>(other) != nullptr)
		--health;
}

char* Mushroom::getType() {
	return "Mushroom";
}


Mushroom::~Mushroom()
{
}