#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"

class Ghost;
class Player;
class Pacman;
class SuperPacman;
class Key;
class Food;
class Wall;
class Gate;
class TimeGift;
class FreezeGift;
class LifeGift;
class SuperGift;

/* The GameObject class is the base class of all of the objects in the game. */
class GameObject
{
public:
	//D-tor and C-tor
	GameObject(sf::Vector2f& pos, Objects objEnum);
	virtual ~GameObject() = default;

	virtual void drawObject(sf::RenderWindow& window); // Draw function for the objects.

	/* Getters. */
	sf::FloatRect getGlobalBounds() const; // Returns the bounding rectangle of the object.
	sf::Sprite& getSprite(); // Returns the sprite of the object.
	sf::Vector2f getPosition() const; // Returns the position of the object.

	/* Setters. */
	void setPosition(const sf::Vector2f& loc);
	void setTexture(const sf::Texture* texture);
	void setDisposal(bool dispose);

	// Returns wether the object should be removed.
	bool isDisposed() const
	{
		return m_isDisposed;
	}
	
	bool getAteKey() const;
	void setAteKey(bool ate);
	
	bool getAteFood() const;
	void setAteFood(bool ate);
	
	bool getAteSuperGift() const;
	void setAteSuperGift(bool ate);

	bool getAteTimeGift() const;
	void setAteTimeGift(bool ate);

	bool getAteFreezeGift() const;
	void setAteFreezeGift(bool ate);

	bool getAteLifeGift() const;
	void setAteLifeGift(bool ate);


	sf::Vector2f getSpawnLoc() const;
	void setSpawnLoc(const sf::Vector2f& loc);

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Pacman& pacman) = 0;
	virtual void handleCollision(SuperPacman& superPacman) = 0;
	virtual void handleCollision(Ghost& ghost) = 0;
	virtual void handleCollision(Key& Key) = 0;
	virtual void handleCollision(Food& food) = 0;
	virtual void handleCollision(Gate& gate) = 0;
	virtual void handleCollision(TimeGift& gift) = 0;
	virtual void handleCollision(LifeGift& gift) = 0;
	virtual void handleCollision(FreezeGift& gift) = 0;
	virtual void handleCollision(SuperGift& gift) = 0;

protected:
	sf::Sprite m_objSprite; // Stores the sprite of the object.
	sf::Vector2f m_spawnPosition; // Stores the previous position (before moving).
	bool m_isDisposed = false; // Stores the current disposal status.
	bool m_ateKey = false; // Stores the current disposal status.
	bool m_ateFood = false; // Stores the current disposal status.
	bool m_ateSuperGift = false; // Stores the current disposal status.
	bool m_ateLifeGift = false; // Stores the current disposal status.
	bool m_ateFreezeGift = false; // Stores the current disposal status.
	bool m_ateTimeGift = false; // Stores the current disposal status.

	// For animations.
	int m_row; 
	int m_col;
};