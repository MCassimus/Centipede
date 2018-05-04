#include "stdafx.h"
#include "Spider.h"
#include "CentipedeGame.h"

static sf::Vector2i velocities[6] = { sf::Vector2i(0, -1), sf::Vector2i(1, -1), sf::Vector2i(1, 1), sf::Vector2i(0, 1), sf::Vector2i(-1, 1), sf::Vector2i(-1, -1) };


Spider::Spider(int x, int y) : GameObject(x, y)
{
	currentPosition.x = x;
	currentPosition.y = y;
	object.setOrigin(0, -4);//sprite offset
	setTexture("../Sprites/Spider/spider0.png");

	//decides which direction to move first
	dir = x < 15 ? true : false; //true = right, false = left
	if (dir)
		setVelocity(velocities[2]);
	else
		setVelocity(velocities[4]);

	soundClip.loadFromFile("../Audio/spider.ogg");
	soundPlayer.play();
	soundPlayer.setLoop(true);
	soundPlayer.setVolume(20);
}

void Spider::setTarget(std::shared_ptr<Player> _player)
{
	player = _player;
}


void Spider::update(CentipedeGame *gameHandle)
{
	static int scuttle = 0; //for animation
	if (CentipedeGame::clock % delay == 0)
	{
		//animations
		if (scuttle++ >= 4)//dancing
			scuttle = 0;

		if (scuttle == 0)//dancing
			setTexture("../Sprites/Spider/Spider0.png");
		else if (scuttle == 1)
			setTexture("../Sprites/Spider/Spider1.png");
		else if (scuttle == 2)
			setTexture("../Sprites/Spider/Spider2.png");
		else
			setTexture("../Sprites/Spider/Spider3.png");

		move();//determine vel and move player		
	}
}


//finds the distance between spider and player for pointValue
void Spider::setPointValue()
{
	if (((player->getPosition().x <= currentPosition.x + 1) && (player->getPosition().x >= currentPosition.x - 1)) &&
		((player->getPosition().y <= currentPosition.y + 1) && (player->getPosition().y >= currentPosition.y - 1)))
		pointValue = 900;
	else if (((player->getPosition().x <= currentPosition.x + 4) && (player->getPosition().x >= currentPosition.x - 4)) &&
		((player->getPosition().y <= currentPosition.y + 4) && (player->getPosition().y >= currentPosition.y - 4)))
		pointValue = 600;
	else
		pointValue = 300;
}


//defines collision behavior
void Spider::collideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
	else if (dynamic_cast<Player*>(other) != nullptr)
		health = 0;
}


//apply and determine velocity of spider
static int count = 0;
void Spider::move()
{
	if (getVelocity() == velocities[2])//player is moving down right
	{
		//move straight up 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[0]);
		//move up right 1/6 chance, or if max dist reached, or if approaching bottom of screen
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 29)
			setVelocity(velocities[1]);
	}
	else if (getVelocity() == velocities[1])//player is moving up right
	{
		//move down 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[3]);
		//move down right 1/6 chance, max dist reached, or approaching top of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 18)
			setVelocity(velocities[2]);
	}
	else if (getVelocity() == velocities[4])//player is moving down left
	{
		//move up 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[0]);
		//move up left 1/6 chance, if max dist reached, or reaching bottom of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 29)
			setVelocity(velocities[5]);
	}
	else if (getVelocity() == velocities[5])//player is moving up left
	{
		//move down 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[3]);
		//move down left 1/6 chance, max dist reached or if reaching top of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 18)
			setVelocity(velocities[4]);
	}
	else if (getVelocity() == velocities[0])//player is moving up
	{
		//move down 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[3]);
		//move down right/left depending on dir of spider movement
		// 1/6 chance, max dist reached, or reaching top of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 18)
			setVelocity(velocities[dir ? 2 : 4]);//determine if left or right movement
	}
	else if (getVelocity() == velocities[3])//player is moving down
	{
		//move up 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[0]);
		//move up right/left depending on dir of spider movement
		// 1/6 chance, max dist reached, or reaching top of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 29)
			setVelocity(velocities[dir ? 1 : 5]);//determine if left or right movement
	}

	//apply vel
	currentPosition.x += velocity.x;
	currentPosition.y += velocity.y;

	count++;//used for additional delay to give ooportunity for random change
}


//sets score to 0 when die off screen else return score
unsigned int Spider::die(bool &readyToDie, CentipedeGame *gameHandle) {
	readyToDie = true;
	setPointValue();//determine current point value

	if (currentPosition.x == -1 || currentPosition.x == 30)//if offscreen return no points
		return 0;
	return getPointValue();
}