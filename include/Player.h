#pragma once
#include "MovableObject.h"

class Player : public MovableObject
{
public:
	// C-tor.
	using MovableObject::MovableObject;

	// Function to move the players.
	virtual void move(sf::Time deltaTime, sf::Vector2u posBgn, sf::Vector2u posEnd) override;

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Pacman& pacman) = 0;
	virtual void handleCollision(SuperPacman& superPacman) = 0;
	virtual void handleCollision(Ghost& ghost) = 0;
	virtual void handleCollision(Key& key) = 0;
	virtual void handleCollision(Gate& gate) = 0;
	virtual void handleCollision(Food& food) = 0;
	virtual void handleCollision(TimeGift& gift) = 0;
	virtual void handleCollision(LifeGift& gift) = 0;
	virtual void handleCollision(FreezeGift& gift) = 0;
	virtual void handleCollision(SuperGift& gift) = 0;
};