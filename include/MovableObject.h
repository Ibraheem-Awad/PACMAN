#pragma once
#include "GameObject.h"

class MovableObject : public GameObject
{
public:
	//C-tor and D-tor
	MovableObject(sf::Vector2f& pos, Objects objEnum);
	virtual ~MovableObject() = default;

	/* Getters. */
	sf::Vector2f getPrevPosition() const;
	sf::Vector2f getDirection() const;

	/* Setters. */
	void setDirection(sf::Keyboard::Key key);
	void setPrevPosition(const sf::Vector2f& loc);

	/* Moving related functions. */
	void checkScreenCollision(sf::Vector2u posBgn, sf::Vector2u posEnd);
	virtual void move(sf::Time deltaTime, sf::Vector2u posBgn, sf::Vector2u posEnd) = 0; // Pure virtual function

	/* Collision functions. */
	bool collidesWith(const GameObject& obj);
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

private:
	sf::Vector2f m_direction; // Stores the direction which the object is walking towards.

protected:
	sf::Vector2f m_prevPosition; // Stores the previous position (before moving).
	sf::Vector2f m_spawnPosition; // Stores the previous position (before moving).
};