#include "Ghost.h"

/* Move function which moves the ghost randomly on the screen. */
void Ghost::move(sf::Time deltaTime, sf::Vector2u posBgn, sf::Vector2u posEnd)
{	
	int direction = rand() % DIRECTION + dirStart;
	this->setDirection((sf::Keyboard::Key)direction);

	m_prevPosition = m_objSprite.getPosition();
	
	m_objSprite.move(getDirection() * GhostSpeed * deltaTime.asSeconds());

	/* Changes animation direction. */
	if (getDirection() == DOWN_DIRECTION)
		this->m_row = 0;
	if (getDirection() == LEFT_DIRECTION)
		this->m_row = 1;
	if (getDirection() == RIGHT_DIRECTION)
		this->m_row = 2;
	if (getDirection() == UP_DIRECTION)
		this->m_row = 3;

	/* Changes animation sprite. */
	m_objSprite.setTextureRect(sf::IntRect(PLAYER_SIZE * m_col, PLAYER_SIZE * m_row, PLAYER_SIZE, PLAYER_SIZE));

	checkScreenCollision(posBgn, posEnd);
}

/* Double dispatching to know what kind of object it is. */
void Ghost::handleCollision(GameObject& object)
{
	if (&object == this) return;
	object.handleCollision(*this);
}

// Nothing can pass through the ghost.
void Ghost::handleCollision(Wall& wall)
{
	this->setPosition(this->m_prevPosition);
}

void Ghost::handleCollision(Pacman& pacman)
{
	this->setPosition(this->m_prevPosition);
}

void Ghost::handleCollision(SuperPacman& superPacman)
{

}

void Ghost::handleCollision(Ghost& ghost)
{}


void Ghost::handleCollision(Key& Key)
{}

void Ghost::handleCollision(Gate& gate)
{
	this->setPosition(this->m_prevPosition);
}

void Ghost::handleCollision(Food& food)
{}

void Ghost::handleCollision(TimeGift & gift)
{}

void Ghost::handleCollision(LifeGift & gift)
{}

void Ghost::handleCollision(FreezeGift & gift)
{}

void Ghost::handleCollision(SuperGift & gift)
{}
