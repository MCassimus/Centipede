#pragma once
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	GameObject();
	GameObject(sf::RenderWindow *);
	~GameObject();
	int getPointValue() const;
	unsigned int getHealth() const;
	sf::Vector2i getVelocity() const;
	void setTexture(const char *);
	virtual void update() = 0;
	void render();
	void collideWith(GameObject *);
	void collideWith(std::vector<GameObject *> *);

	sf::Vector2i getRelMousePos();
	sf::Vector2i getNearestCellPos(sf::Vector2i);

	static sf::Vector2u oWD;

protected:
	void setPointValue(unsigned int);
	void setVelocity(sf::Vector2i);
	void addHealth(int);

	sf::Sprite object;
	unsigned int health = 1;
	unsigned int pointValue;
	sf::Vector2i velocity;
	sf::Vector2u currentPosition;
	sf::RenderWindow * window = nullptr;
	sf::Texture textureTemp;
	static sf::Vector2u interval;
};