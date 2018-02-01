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
	bool collides(GameObject *);
protected:
	void setPointValue(unsigned int);
	void setVelocity(sf::Vector2f);
	void addHealth();
	void takeHealth();
	sf::Sprite object;
	unsigned int health = 1;
	unsigned int pointValue = 0;
	sf::Vector2f velocity;
	sf::RenderWindow * window = nullptr;
};