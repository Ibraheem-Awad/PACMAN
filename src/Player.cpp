#include "Player.h"

void Player::move(sf::Time deltaTime, sf::Vector2u posBgn, sf::Vector2u posEnd)
{
	m_prevPosition = m_objSprite.getPosition();
	

	m_objSprite.move(getDirection() * PlayerSpeed * deltaTime.asSeconds());

	/*changing animation*/
	if (getDirection() == DOWN_DIRECTION)
		this->m_row = 0;
	if (getDirection() == LEFT_DIRECTION)
		this->m_row = 1;
	if (getDirection() == RIGHT_DIRECTION)
		this->m_row = 2;
	if (getDirection() == UP_DIRECTION)
		this->m_row = 3;

	/*sets new texture*/
	m_objSprite.setTextureRect(sf::IntRect(PLAYER_SIZE * m_col, PLAYER_SIZE * m_row, PLAYER_SIZE, PLAYER_SIZE));
	
	checkScreenCollision(posBgn, posEnd);
}
