#include "Textures.h"

Textures::Textures()
{
	/* Menu loading. */
	loadMenuTexture("background.png");
	loadMenuTexture("new.png");
	loadMenuTexture("help.png");
	loadMenuTexture("exit.png");
	loadMenuTexture("exitHelp.png");

	loadMenuTexture("newHL.png");
	loadMenuTexture("helpHL.png");
	loadMenuTexture("exitHL.png");
	loadMenuTexture("exitHelpHL.png");
	loadMenuTexture("helpDisplay.png");

	/* Game objects loading. */
	loadObjectTexture("pacman.png");
	loadObjectTexture("superPacman.png");
	loadObjectTexture("ghost.png");
	loadObjectTexture("Key.png");
	loadObjectTexture("wall.png");
	loadObjectTexture("door.png");
	loadObjectTexture("food.png");
	loadObjectTexture("gift.png");
	loadObjectTexture("heart.png");
	loadObjectTexture("freeze.png");
	loadObjectTexture("timerIcon.png");

	/* Game levels background loading. */
	loadlevelBGTexture("firstBG.jpg");
	loadlevelBGTexture("secondBG.jpg");
	loadlevelBGTexture("thirdBG.jpg");

	/*Display regarded loadings*/
	loadLevelUpBannerTexture("LevelUp.png");
	loadWinGameBannerTexture("winGameBanner.png");
}

/*This function returns an object's' texture by a given enum*/
sf::Texture* Textures::getObjectTexture(Objects objEnum)
{
	return &(m_objectsTextures[objEnum]);
}
/*This function returns a menu texture by a given menuEnum*/
sf::Texture* Textures::getMenuTexture(Menu_t menuEnum)
{
	return &(m_menuTextures[menuEnum]);
}
/*This function returns a background texture by a given Background Enum*/
sf::Texture* Textures::getLevelBGTexture(LevelsBG_t bgEnum)
{
	return &(m_levelsBGTextures[bgEnum]);
}

/*This function returns a level up banner*/
sf::Texture* Textures::getLevelUpBannerTexture()
{
	return &(m_levelUpBanner);
}
/*This function returns a win game banner*/
sf::Texture* Textures::getWinGameBannerTexture()
{
	return &(m_winGameBanner);
}

//makes an instance and is created only once
Textures& Textures::instance()
{
	static Textures instance;
	return instance;
}
/*This function recieves an object texture by the given filename*/
void Textures::loadObjectTexture(const std::string fileName)
{
	sf::Texture temp;
	temp.loadFromFile(fileName);
	m_objectsTextures.push_back(temp);
}
/*This function loads a menu texture by the given filename*/
void Textures::loadMenuTexture(const std::string fileName)
{
	sf::Texture temp;
	temp.loadFromFile(fileName);
	m_menuTextures.push_back(temp);
}

/*This function loads a background texture by the given filename*/
void Textures::loadlevelBGTexture(const std::string fileName)
{
	sf::Texture temp;
	temp.loadFromFile(fileName);
	m_levelsBGTextures.push_back(temp);
}

/*This function loads a level up banner by the given filename*/
void Textures::loadLevelUpBannerTexture(const std::string fileName)
{
	this->m_levelUpBanner.loadFromFile(fileName);
}

/*This function loads a win game banner by the given filename*/
void Textures::loadWinGameBannerTexture(const std::string fileName)
{
	this->m_winGameBanner.loadFromFile(fileName);
}
