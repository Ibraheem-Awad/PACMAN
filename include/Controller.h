#pragma once
/* Libraries. */
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <cmath>
#include <cstdlib>
using std::string; // To avoid using "std::".

/* Classes. */
#include "Pacman.h"
#include "Ghost.h"
#include "Board.h"
#include "Macros.h"
#include "Menu.h"
#include "Sound.h"

/* The Controller class is the main class of the game. 
 * It controls the functionality of the game, it runs the menu and runs the game itsghost. */
class Controller
{
public:
	// C-tor.
	Controller();

	// Runs the menu and the game itsghost.
	void run();

	/* Window and event management functions. */
	void update(); // Updates the state of the game.
	void render(); // Displays the game.
	void updateVideo(); // Updates the game board area.
	void convertToSuper();

	/* Game management. */
	void pollEvents(); // Manages new events.
	void winLevel(); // Manages a level win.
	void updateTime(const sf::Time deltaTime); // Manages the time.
	void restartLevel(); // Restarts the current level.
	void getNext(); // Reads a new level (or the same one again if restarted).
	void resetWinCon(); // Turns win bolean to false.
	void erase(); // Erases objects which are set for erasing.
	void updateThemeMusic(); // Updates the theme music when the level changes.
	void handleSounds(GameObject* object); // Plays the right sound.

	/* Setters and loaders. */
	int getLives() const;
	int getScore() const;
	void setLives(int lives);
	void setScore(int score);

	void freezeGhosts();

	void loadLevelsBG();
	void setTimeBG(sf::Vector2f pos);
	void loadLevelUpandWinGame();
	void loadMenu();
	/* Handlers. */
	void handleGameBoard(); // Handles the game board (the area you can play on).
	void handleKeyPressed(); // Handles keyboard keys use.

	/* Move. */
	void moveGhost(const sf::Time deltaTime); 
	void moveCurrent(const sf::Time deltaTime); // Moves the current played character.

	/* Collisions. */
	void ghostCollision(); 
	void unmovableCollision(); // Handles the collisions of unmovable objects.

	void setStopShadow();

private:
	/* Variables. */
	sf::RenderWindow* m_window; // Used to display the game.
	sf::Event m_event; // Used to keep up with the events given.
	sf::VideoMode m_video; // Used to set the window and control it.

	/* Time related. */
	sf::Clock m_clock; // Used to keep up with the time passed in game.
	sf::Time m_time; // Used to save the time limit in a certain level.
	sf::Font m_timeFont; // Used to load the font of the text of the timer.
	sf::Text m_timeText; // Used to display the text of the timer.
	sf::Text m_Text; // Used to display the text of the timer.
	sf::RectangleShape m_infoBG; // Used to display a background for the timer.

	/* Buttons variables. */
	sf::Sprite m_buttonBar; // Used to display a background for the buttons.
	std::vector<bool> m_reHoveredButton; // Used to keep track of which version of the button should be displayed ('highlighted' or not).
	bool m_helpMode; // Used to activate the help mode (in which the user can view an explanation of the game).
	bool m_helpExitHover; // Used to manage hovering the help screen's exit button.
	/*--------------------*/

	/* New level and win game display. */
	sf::Sprite m_levelUpBanner;
	sf::Sprite m_winGameBanner;

	/* Others. */
	std::vector<sf::Sprite> m_levelsBGSprites; // Used to control the backgrounds of the levels.
	Sound m_sound; // Used to control the musics and sounds of the game.
	Board m_board; // Used to control the game board.
	Menu m_menu; // Used to control the client.
	bool m_win; // Used to control the condition of the game.
	bool m_pause; // Used to activate a pause.
	bool m_superPac; // Used to activate a pause.
	float m_superTimer;
	int m_stopShadow = 0;
	int m_score, m_lives;

	/* Initiation functions. */
	void initVars();
	void initWindow();
	void initTimeSet();

};
