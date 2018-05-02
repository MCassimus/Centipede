#include "stdafx.h"
#include "Mushroom.h"
#include "Spider.h"
#include "Scorpion.h"
#include "Bullet.h"


int Mushroom::color = -1;

Mushroom::Mushroom(sf::RenderWindow* window, int x, int y) : GameObject(window, x, y)
{
	pointValue = 5;
	poisoned = false;
	health = 4;
	object.setOrigin(-2, -2);
	object.setScale(1.25, 1.25);
}


void Mushroom::update()
{
	if (!poisoned)
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
	}
	else//mushroom is poisoned used poisoned sprite
	{
		switch (health)//changes texture based on health
		{
		case 1:
			setTexture("../Sprites/Mushroom/Poisoned1.png");
			break;
		case 2:
			setTexture("../Sprites/Mushroom/Poisoned2.png");
			break;
		case 3:
			setTexture("../Sprites/Mushroom/Poisoned3.png");
			break;
		case 4:
			setTexture("../Sprites/Mushroom/Poisoned4.png");
			break;
		}
	}

	switch (color)
	{
	case 0://default white
		object.setColor(sf::Color::White);
		break;
	case 1://green
		object.setColor(sf::Color(127, 255, 0));
		break;
	case 2://red
		object.setColor(sf::Color(209, 60, 60));
		break;
	case 3://yellow
		object.setColor(sf::Color(255, 255, 0));
		break;
	case 4: //light blue
		object.setColor(sf::Color(0, 204, 204));
		break;
	case 5://purple
		object.setColor(sf::Color(215, 74, 237));
		break;
	}
}


bool Mushroom::getPoisoned()//for centipede 
{
	return poisoned;
}


bool Mushroom::resetHeath()//for end of level
{
	static sf::Sound mushroomRebuildSound;
	static sf::SoundBuffer rebuildSound;

	rebuildSound.loadFromFile("../Audio/mushroomReset.ogg");
	mushroomRebuildSound.setBuffer(rebuildSound);

	if (health < 4)
	{
		switch (++health)//changes texture based on health
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

		mushroomRebuildSound.play();

		while (mushroomRebuildSound.getStatus() != sf::Sound::Stopped)
		{
			//printf("Health - %i\n", health);
		}
		poisoned = false;
		return true;
	}
	return false;
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