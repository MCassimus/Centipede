#pragma once
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	GameObject();
	GameObject(sf::RenderWindow *);
	GameObject(sf::RenderWindow *, int, int);
	~GameObject();
	virtual int getPointValue();
	unsigned int getHealth() const;
	sf::Vector2i getVelocity() const;
	sf::Vector2i getPosition() const;
	void setTexture(const char *);
	virtual void update() = 0;
	virtual void render();
	virtual void collideWith(GameObject *);
	//virtual void collideWith(std::vector<GameObject *> *);

	sf::Vector2i getRelMousePos();
	sf::Vector2i getNearestCellPos(sf::Vector2i);

	static sf::Vector2u oWD;
	static sf::Vector2i interval;

	virtual unsigned int die(bool&);

	virtual char* getType();

protected:
	void setPointValue(unsigned int);
	void setVelocity(sf::Vector2i);
	void addHealth(int);
	void setPixels();

	sf::Sprite object;
	unsigned int health = 1;
	unsigned int pointValue;
	sf::Vector2i velocity;
	sf::Vector2i currentPosition;
	sf::RenderWindow * window = nullptr;
	sf::Texture textureTemp;
};