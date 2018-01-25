#pragma once
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	GameObject(sf::RenderWindow *);
	~GameObject();
	int getPointValue() const;
	sf::Vector2f getPosition() const;
	unsigned int getHealth() const;
	sf::Vector2f getVelocity() const;
	sf::FloatRect getBoundingBox() const;
	void setTexture(const char *);
	virtual void update(float) = 0;//takes time delta as param
	void render();
	bool collides(GameObject *);
private:
	void setPointValue(unsigned int);
	void setPosition(sf::Vector2f);
	void setPosition(float, float);
	void setVelocity(sf::Vector2f);
	void addHealth();
	bool takeHealth();//returns true when health == 0
	sf::Sprite object;
	unsigned int health = 1;
	unsigned int pointValue = 0;
	sf::Vector2f velocity;
	sf::RenderWindow * window = nullptr;
};