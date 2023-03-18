#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "GameObject.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

#include "Pacman.h"
#include "Ghost.h"

using std::string;
using std::vector;
using std::unique_ptr;

/* The Board class is in charge of the game board in which the game occurs. */
class Board
{
public:
	// C-tor.
	Board();

	/* Management. */
	void resetBoard(); // Resets the board's data.
	void loadFileNames(); // Reads the file names of the levels.
	bool loadLevel(); // Loads the current level from a file.
	void openFile(std::ifstream &file);
	bool createMovableObject(Objects type, sf::Vector2f pos); // Creates a moveable object.
	void createUnmovableObject(Objects type, sf::Vector2f pos); // Creates an unmovable object.
	void adjustObjects(); // Used to adjust the object's position on the screen.
	
	void setBoardframe(sf::Vector2f posBgn, sf::Vector2f posEnd); // Board frame is the area which is played on (displayed with a rectangle shape).
	void setCurrLevel(int level); // For external use.
	void setFoodCounter(int counter); // For external use.

	/* Getters. */
	vector<unique_ptr<MovableObject>>& getCharacters();  // Access to the vector of the players (characters).
	vector<unique_ptr<Ghost>>& getGhosts();
	vector<unique_ptr<UnmovableObject>>& getUnmovables();  // Access to the vector of the unmovable objects.
	int getTime() const; // Access to the time limit (or no time limit if the time in the file is 0 or not specified).
	int getCurrChar() const; // Current player which is played.
	int getCurrLevel() const; // Current level number.
	int getFoodCounter() const; // Current level number.
	int getNumofLevels() const; // Total number of levels.
	sf::Vector2u getBoardSize() const; // Game board size (area in which the game occurs).
	sf::RectangleShape getBoardFrame() const; // Rectangle of the gameboard.
	bool isTimeLim(); // Returns if a time limit is set or not.

	/* Drawing. */
	void drawCharacters(sf::RenderWindow &window);
	void drawGhosts(sf::RenderWindow &window);
	void drawUnmovables(sf::RenderWindow &window);

	void superPacman();

	void regularPac();

	sf::Vector2f getSpawnPos() const;

	void setSpawnPos(const sf::Vector2f& loc);

private:
	vector<unique_ptr<MovableObject>> m_characters; // Stores players (characters).
	vector<unique_ptr<Ghost>> m_ghosts;
	vector<unique_ptr<UnmovableObject>> m_unmovables; // Stores unmovable objects.
	vector<sf::Vector2f> m_portalsLocs; // Stores the locations of the portals.
	vector<string> m_levelFileNames; // Stores the names of the files of the levels.
	int m_currentCharacter; // Stores the index of the currently played character.
	int m_currentLevel; // Stores the index of the current level.
	int m_timeLimit; // Stores the time limit (if there's one).
	int m_foodCounter;
	bool m_timeLim; // Stores if there's a time limit or not.
	bool m_super;
	sf::Vector2u m_boardSize; // Stores the game area size (as read from the files).
	sf::RectangleShape m_boardFrame; // Stores the game area.
	sf::Vector2f m_startPosition; // Stores the previous position (before moving).
};