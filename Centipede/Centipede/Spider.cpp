#include "stdafx.h"
#include "Spider.h"
#include "CentipedeGame.h"


Spider::Spider(sf::RenderWindow * renderWindow, int x, int y, Player& p) : GameObject(renderWindow, x,  y)
{
	currentPosition.x = x;
	currentPosition.y = y;
	object.setOrigin(0, -4);
	setTexture("../Sprites/Spider/spider0.png");
	pointValue = 300;
	player = &p;
	scuttle = 0;
	
	velocities[0] = sf::Vector2i(0, -1);//sets all velocitys for the velocities array
	velocities[1] = sf::Vector2i(1, -1);//0 starts at up
	velocities[2] = sf::Vector2i(1, 1);//then the velocitys rotate clockwise skipping horizontal
	velocities[3] = sf::Vector2i(0, 1);
	velocities[4] = sf::Vector2i(-1, 1);
	velocities[5] = sf::Vector2i(-1, -1);
	
	if (x < 15)                      //decides which direction to move first
		setVelocity(velocities[2]);
	else
		setVelocity(velocities[4]);
	count = 0;

	soundClip.loadFromFile("../Audio/spider.ogg");
	soundPlayer.play();
	soundPlayer.setLoop(true);
	soundPlayer.setVolume(20);
}


void Spider::update()
{
	setPointValue();//determine current point value

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
		else if(scuttle ==3)
			setTexture("../Sprites/Spider/Spider3.png");
		else
			setTexture("../Sprites/Spider/Spider3.png");

		move();//determine vel and move player
	}
}


void Spider::setPointValue()//finds the distance between spider and player for pointValue
{
	if (currentPosition.x < 0 || currentPosition.x > 29)
	{
		pointValue = 0;
		health = 0;
		return;
	}
	else
	{
		if(((player->getPosition().x <= currentPosition.x + 1)&&(player->getPosition().x >= currentPosition.x -1)) && 
			((player->getPosition().y <= currentPosition.y + 1) && (player->getPosition().y >= currentPosition.y - 1)))
		{
			pointValue = 300;
			return;
		}
		else if (((player->getPosition().x <= currentPosition.x + 4) && (player->getPosition().x >= currentPosition.x - 4)) &&
			((player->getPosition().y <= currentPosition.y + 4) && (player->getPosition().y >= currentPosition.y - 4)))
		{
			pointValue = 600;
			return;
		}
		else
		{
			pointValue = 900;
			return;
		}
	}
}


void Spider::collideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
	else if (dynamic_cast<Player*>(other) != nullptr)
		health = 0;
}


void Spider::move()
{
	count++;	

	if (getVelocity() == velocities[2])//player is moving down right
	{
		//move straight up 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[0]);
		//move up right 1/6 chance, or if max dist reached, or if approaching bottom of screen
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 29)
			setVelocity(velocities[1]);
	}
	else if (getVelocity() == velocities[1])//player ismoving up right
	{
		//move down 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[3]);
		//move down 1/6 chance, max dist reached, or approaching top of player area
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 18)
			setVelocity(velocities[3]);
	}
	else if (getVelocity() == velocities[4])//player is moving down left
	{
		//move up 1/6 chance
		if (rand() % 6 == 1)
			setVelocity(velocities[0]);
		else if (rand() % 6 == 1 || count % 6 == 0 || currentPosition.y == 29)
			setVelocity(velocities[]);
		//move up left 1/6 chance
		//after 6 steps move up left
		//override die to set score to 0 when offscreen, then kill.
	}
	else if (getVelocity() == velocities[5])//moving up left
	{
		//options
		//move down left 1/6 chance
		//move down 1/6 chance
		//after 6 steps move down left
		//if reaching top of player bounds, move down right
	}
	else if (getVelocity() == velocities[0])//moving up
	{
		//options
		//move down 1/6 chance
		//if last moving right, move down right 1/6 chance
		//if last moving left, move down left 1/6 chance
		//after 6 steps, if last moving right, move down right
		//after 6 steps, if last moving left, move down left
		//if reaching top of player boundary, if last moving right, move down right
		//if reaching top of player boundary, if last moving left, move down left 
	}
	else if (getVelocity() == velocities[3])	//moving down
	{
		//options
		//move up 1/6 chance
		//if last moving right, move up right 1/6 chance
		//if last moving left, move up left 1/6 chance
		//after 6 steps, if last moving right, move up right
		//after 6 steps, if last moving left, move up left
		//if reaching top of player boundary, if last moving right, move up right
		//if reaching top of player boundary, if last moving left, move up left
	}

	//apply vel
	currentPosition.x += velocity.x;
	currentPosition.y += velocity.y;
	//increase count delay
	count++;//used for additional delay to give ooportunity for random change

	#pragma region temp
	//#pragma region toomuch
	////all direction have a chance to go two directions every move untill they move
	////the same direction 5 times which will cause the spider to move in the standered
	////direction.

	//if (getVelocity() == velocities[2])//options for moving down right
	//{
	//	lastDir = 0;
	//	count++;
	//	
	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[1]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[0]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		setVelocity(velocities[1]);
	//		count = 0;
	//	}

	//	//if (currentPosition.x > 30)//bounderys
	//	//{
	//	//	pointValue = 0;
	//	//	health = 0;
	//	//}
	//	/*else*/ if (currentPosition.y > 30)
	//	{
	//		count = 0;
	//		setVelocity(velocities[1]);
	//	}
	//}

	//if (getVelocity() == velocities[1])//options fro moving up right
	//{
	//	lastDir = 0;
	//	count++;

	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[2]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[3]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		setVelocity(velocities[2]);
	//		count = 0;
	//	}
	//	//if (currentPosition.x > 30)//bounderys
	//	//{
	//	//	pointValue = 0;
	//	//	health = 0;
	//	//}
	//	/*else*/ if (currentPosition.y < 17)
	//	{
	//		count = 0;
	//		setVelocity(velocities[2]);
	//	}
	//}
	
	//if (getVelocity() == velocities[4])//options for moving down left
	//{
	//	lastDir = 1;
	//	count++;

	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[5]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[0]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		setVelocity(velocities[5]);
	//		count = 0;
	//	}
	//	
	//	//if (currentPosition.x < 0)
	//	//{
	//	//	pointValue = 0;
	//	//	health = 0;
	//	//}
	//	/*else*/ if (currentPosition.y > 30)
	//	{
	//		count = 0;
	//		setVelocity(velocities[5]);
	//	}
	//}

	//if (getVelocity() == velocities[5])//options for moving up left
	//{
	//	lastDir = 1;
	//	count++;

	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[4]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[3]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		setVelocity(velocities[4]);
	//		count = 0;
	//	}
	//	//if (currentPosition.x < 0)//bounderys
	//	//{
	//	//	pointValue = 0;
	//	//	health = 0;
	//	//}
	//	/*else*/ if (currentPosition.y < 17)
	//	{
	//		count = 0;
	//		setVelocity(velocities[2]);
	//	}
	//}

	//if (getVelocity() == velocities[0])//options for moving up
	//{
	//	count++;

	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[3]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		if(lastDir==0)
	//			setVelocity(velocities[2]);
	//		else
	//			setVelocity(velocities[4]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		if (lastDir == 0)
	//			setVelocity(velocities[2]);
	//		else
	//			setVelocity(velocities[4]);
	//		count = 0;
	//	}
	//}

	//if (getVelocity() == velocities[3]) //options for moving down
	//{
	//	count++;

	//	if (rand() % 6 == 1)
	//	{
	//		setVelocity(velocities[0]);
	//		count = 0;
	//	}
	//	else if (rand() % 6 == 1)
	//	{
	//		if (lastDir == 0)
	//			setVelocity(velocities[1]);
	//		else
	//			setVelocity(velocities[5]);
	//		count = 0;
	//	}

	//	if (count >= 5)
	//	{
	//		if (lastDir == 0)
	//			setVelocity(velocities[1]);
	//		else
	//			setVelocity(velocities[5]);
	//		count = 0;
	//	}
	//}
	//#pragma endregion
	#pragma endregion
}


Spider::~Spider()
{
}