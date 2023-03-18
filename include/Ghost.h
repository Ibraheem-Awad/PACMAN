#pragma once
#include "MovableObject.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

#include "Wall.h"
#include "Key.h"
#include "Food.h"
#include "Gate.h"
#include "TimeGift.h"
#include "SuperGift.h"
#include "LifeGift.h"
#include "FreezeGift.h"

class Ghost : public MovableObject
{
public:
	using MovableObject::MovableObject;

	virtual void move(sf::Time deltaTime, sf::Vector2u posBgn, sf::Vector2u posEnd) override;

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Pacman& pacman) override;
	virtual void handleCollision(SuperPacman& superPacman) override;
	virtual void handleCollision(Ghost& ghost) override;
	virtual void handleCollision(Key& Key) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Food& food) override;
	virtual void handleCollision(TimeGift& gift) override;
	virtual void handleCollision(LifeGift& gift) override;
	virtual void handleCollision(FreezeGift& gift) override;
	virtual void handleCollision(SuperGift& gift) override;

private:
	// Stores the current direction which the ghost is walking towards.
	sf::Vector2f m_ghostDirection;
};