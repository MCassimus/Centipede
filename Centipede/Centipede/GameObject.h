#pragma once
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	GameObject(sf::RenderWindow *);
	~GameObject();
	int getPointValue() const;
	unsigned int getHealth() const;
	sf::Vector2f getVelocity() const;
	void setTexture(const char *);
	virtual void update() = 0;
	void render();
	void collideWith(GameObject *);
protected:
	void setPointValue(unsigned int);
	void setVelocity(sf::Vector2i);
	void addHealth(int);

	sf::Sprite object;
	unsigned int health = 1;
	unsigned int pointValue;
	sf::Vector2u velocity, currentPosition;
	sf::RenderWindow * window = nullptr;
};