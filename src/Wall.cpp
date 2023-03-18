#include "Wall.h"

Wall::~Wall()
{}

void Wall::handleCollision(GameObject& object)
{}

void Wall::handleCollision(Wall& wall)
{}

void Wall::handleCollision(Pacman& pacman)
{
	pacman.handleCollision(*this);
}

void Wall::handleCollision(SuperPacman& superPacman)
{
	superPacman.handleCollision(*this);
}

/*Ghost encountered a wall*/
void Wall::handleCollision(Ghost& ghost)
{
	ghost.handleCollision(*this);
}

void Wall::handleCollision(Key & Key)
{}

void Wall::handleCollision(Gate & gate)
{}

void Wall::handleCollision(Food & food)
{}

void Wall::handleCollision(TimeGift & gift)
{
}

void Wall::handleCollision(LifeGift& gift)
{
}

void Wall::handleCollision(FreezeGift& gift)
{
}

void Wall::handleCollision(SuperGift& gift)
{
}
