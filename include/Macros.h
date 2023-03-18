#pragma once
/* Macros contains the enums and consts of the game. */

/* Name of the game. */
const std::string GAME_NAME = "Pacman";

/* Sizes for measuring. */
const unsigned int BLOCK_SIZE = 64, FIXED_BLOCK_SIZE = 60, PLAYER_SIZE = 32;
const unsigned int menuHeight = 720, menuWidth = 1280;
const unsigned int gameHeight = 1080, gameWidth = 1920;
const unsigned int buttonBarHeight = 110, buttonBarWidth = 660;
const unsigned int buttonHeight = 550, buttonWidth = 1060;
const unsigned int lvUpHeight = 482, lvUpWidth = 718;
const unsigned int winGameBannerHeight = 649, winGameBannerWidth = 603;
const unsigned int heightGap = 15;
const unsigned int GAP = 10;
const unsigned int dirStart = 71;

/* Directions for movable objects.*/
const sf::Vector2f LEFT_DIRECTION = sf::Vector2f(-1, 0);
const sf::Vector2f RIGHT_DIRECTION = sf::Vector2f(1, 0);
const sf::Vector2f UP_DIRECTION = sf::Vector2f(0, -1);
const sf::Vector2f DOWN_DIRECTION = sf::Vector2f(0, 1);
const sf::Vector2f DEFAULT_DIRECTION = sf::Vector2f(0, 0);

const sf::Time cooldown = sf::seconds(2); // Cooldown between levels.
const float endTime = (-0.5); // Time up.
const float superPacTime = 12; // Time up.

/* Speed of movable objects */
const auto GhostSpeed = 100.f;
const auto PlayerSpeed = 150.f;


/* Seed of randomize time gifts*/
const unsigned int TimeGiftSeed = 10;

/* Different. */
const unsigned int defaultVol = 60;
const int TIMER = -1;
const unsigned int DIRECTION = 4;

/* Enum section of the objects. */
enum Objects
{
	pacman, superPac, ghost, key, wall, door, food, gift, heart, freeze, timer,

	pacmanC = 'a', superPacmanC = '@', ghostC = '&', keyC = '%',
	wallC = '#', doorC = 'D', foodC = '*', 
	giftC = '$', heartC = '^', freezeC = '!', timerC = '+'
};

/* Enum section of the directions. */
enum sideNum
{
	left, right, up, down
};

/* Enum section for the menu. */
enum Menu_t
{
	background, newGame, help, exitGame, exitHelp, newGameHL, helpHL, exitGameHL, exitHelpHL, helpDisplay, numofTextures
};

/* Enum section for the backgrounds of the levels. */
enum LevelsBG_t
{
	firstBG, secondBG, thirdBG ,numofLevelsBG
};

/* Enum section for the sounds of the whole program. */
enum Sounds_t
{
	bumpIntoWall, keyLoot, winLevelSound, gateOpen, hoverSound, gameStart, clickSound,
	collectGiftSound, winGameSound
};

/* Enum section for the musics of the program. */
enum Music_t
{
	menuMusic, firstTheme, secondTheme, thirdTheme
};