#include "Board.h"

// Constructor of the board.
Board::Board()
	: m_currentLevel(0), m_currentCharacter(0), m_boardSize(0, 0), m_timeLimit(0),m_foodCounter(0), m_super(false)
{
	this->m_levelFileNames.push_back("Levels.txt"); // "Levels.txt" needs to contain the names of the levels.
	loadFileNames();
}

/* This function is in charge of reseting the board data. */
void Board::resetBoard()
{
	// Clears vectors.
	m_characters.clear();
	m_ghosts.clear();
	m_unmovables.clear();

	m_currentCharacter = 0;
	m_foodCounter = 0;
}

/* This function is in charge of loading the names of the files of the levels. */
void Board::loadFileNames()
{
	std::ifstream file;
	this->openFile(file);
	char c;
	string name;

	// Reads from file.
	while (file.get(c))
	{
		name.clear();

		while (c != '\n' && !file.eof())
		{
			name += c;
			file.get(c);
		}

		m_levelFileNames.push_back(name);
	}

	// Closes file in the end.
	file.close();
}

/* This function is in charge of adjusting the objects' locations to the game board area. */
void Board::adjustObjects()
{
	/* fixedPos is the top left corner of the game board. */
	auto fixedPos = sf::Vector2u((gameWidth - (m_boardSize.x * BLOCK_SIZE)) / 2, (gameHeight - (m_boardSize.y * BLOCK_SIZE)) / 2);

	// Positions players.
	for (auto& character : this->m_characters)
	{
		auto charPos = character->getPosition();
		character->setPosition(sf::Vector2f(charPos.x + fixedPos.x, charPos.y + fixedPos.y));
		character->setPrevPosition(sf::Vector2f(charPos.x + fixedPos.x, charPos.y + fixedPos.y));
	}


	for (auto& ghost : this->m_ghosts)
	{
		auto ghostPos = ghost->getPosition();
		ghost->setPosition(sf::Vector2f(ghostPos.x + fixedPos.x, ghostPos.y + fixedPos.y));
		ghost->setPrevPosition(sf::Vector2f(ghostPos.x + fixedPos.x, ghostPos.y + fixedPos.y));
	}

	// Positions unmovables.
	for (auto& unmovable : this->m_unmovables)
	{
		auto unmovablePos = unmovable->getPosition();
		unmovable->setPosition(sf::Vector2f(unmovablePos.x + fixedPos.x, unmovablePos.y + fixedPos.y));
	}
}

/* This function is in charge of setting the game board frame. */
void Board::setBoardframe(sf::Vector2f posBgn, sf::Vector2f posEnd)
{
	this->m_boardFrame.setPosition(posBgn);
	this->m_boardFrame.setSize(sf::Vector2f(posEnd.x - posBgn.x, posEnd.y - posBgn.y));
	this->m_boardFrame.setOutlineColor(sf::Color::Black);
	this->m_boardFrame.setOutlineThickness(2);

	// For fun and more visuals.
	if(this->m_currentLevel % 2 == 0)
		this->m_boardFrame.setFillColor(sf::Color(37, 37, 37, 170));
	else
		this->m_boardFrame.setFillColor(sf::Color(150, 150, 150, 170));
}

/* This function is in charge of setting the number of the current level. */
void Board::setCurrLevel(int level)
{
	this->m_currentLevel = level;
}

void Board::setFoodCounter(int counter)
{
	m_foodCounter = counter;
}

/* This function is in charge of loading a level from a file. */
bool Board::loadLevel()
{
	if (m_levelFileNames.size() - 1 > m_currentLevel)
		m_currentLevel++;
	else return false; // If no more levels.

	resetBoard();

	/* Handle file. */
	std::ifstream file;
	openFile(file); // Knows which level to open by m_currentLevel.

	char c;
	char timeLim[3] = { 0 };
	int counter = 0;

	file.get(c);

	while (isdigit(c)) // Reads for a time limit.
	{
		timeLim[counter] = c; 
		counter++;
		file.get(c);
	}

	this->m_timeLimit = atoi(timeLim);
	if (m_timeLimit > 0) // If there's a time limit.
		m_timeLim = true;
	else // If there's no time limit.
		m_timeLim = false;

	m_boardSize.y = 0;

	/* Rows. */
	while (file.get(c))
	{
		m_boardSize.x = 0;

		/* Cols. */
		while (c != '\n' && !file.eof())
		{
			sf::Vector2f pos = sf::Vector2f(m_boardSize.x * BLOCK_SIZE, m_boardSize.y * BLOCK_SIZE);

			if(!createMovableObject((Objects)c, pos))
				createUnmovableObject((Objects)c, pos);

			/* Updates the width and reads another char. */
			m_boardSize.x++;
			file.get(c);
		}

		/* Updates the height. */
		m_boardSize.y++;
	}

	/* Closes the file - no further use. */
	file.close();
	return true;
}

/* This function is in charge of opening a file stream. */
void Board::openFile(std::ifstream& file)
{
	/* Open file. */
	string nameofFile = this->m_levelFileNames[m_currentLevel];
	file.open(nameofFile);

	if (file.fail())
	{
		std::cout << "Can't open file.\n";
		exit(EXIT_FAILURE);
	}
}

/* This function is in charge of creating a movable object with the make_unique method, 
 * and then inserting it to the right vector using a unique_ptr. */
bool Board::createMovableObject(Objects type, sf::Vector2f pos)
{
	switch (type)
	{
	case pacmanC:
	{
		m_characters.push_back(std::make_unique<Pacman>(pos, pacman));
		m_startPosition = pos;
		return true;
	}

	case ghostC:
		m_ghosts.push_back(std::make_unique<Ghost>(pos, ghost));
		return true;

	default: return false;
	}
}

/* This function is in charge of creating an unmovable object with the make_unique method,
 * and then inserting it to the right vector using a unique_ptr. */
void Board::createUnmovableObject(Objects type, sf::Vector2f pos)
{
	switch (type)
	{
	case wallC:
		m_unmovables.push_back(std::make_unique<Wall>(pos, wall));
		break;

	case keyC:
		m_unmovables.push_back(std::make_unique<Key>(pos, key));
		break;

	case doorC:
		m_unmovables.push_back(std::make_unique<Gate>(pos, door));
		break;

	case foodC:
		m_unmovables.push_back(std::make_unique<Food>(pos, food));
		m_foodCounter++;
		break;

	case giftC:
		m_unmovables.push_back(std::make_unique<SuperGift>(pos, gift));
		break;

	case heartC:
		m_unmovables.push_back(std::make_unique<LifeGift>(pos, heart));
		break;

	case freezeC:
		m_unmovables.push_back(std::make_unique<FreezeGift>(pos, freeze));
		break;

	case timerC:
		m_unmovables.push_back(std::make_unique<TimeGift>(pos, timer));
		break;

	default: break;
	}
}

/* Returns the vector of the players. */
vector<unique_ptr<MovableObject>>& Board::getCharacters()
{
	return m_characters;
}

vector<unique_ptr<Ghost>>& Board::getGhosts()
{
	return m_ghosts;
}

/* Returns the vector of the unmovables. */
vector<unique_ptr<UnmovableObject>>& Board::getUnmovables()
{
	return m_unmovables;
}

/* Returns the time limit. */
int Board::getTime() const
{
	return m_timeLimit;
}

/* Returns the index of the current player played. */
int Board::getCurrChar() const
{
	return m_currentCharacter;
}

/* Returns the index of the current level. */
int Board::getCurrLevel() const
{
	return this->m_currentLevel;
}

int Board::getFoodCounter() const
{
	return m_foodCounter;
}

/* Returns the total number of levels. */
int Board::getNumofLevels() const
{
	return this->m_levelFileNames.size();
}

/* Returns the game board size. */
sf::Vector2u Board::getBoardSize() const
{
	return m_boardSize;
}

/* Returns the game board's rectangle. */
sf::RectangleShape Board::getBoardFrame() const
{
	return this->m_boardFrame;
}

/* Returns if there's a time limit. */
bool Board::isTimeLim()
{
	return m_timeLim;
}

/* This function is in charge of drawing the characters. */
void Board::drawCharacters(sf::RenderWindow &window)
{
	for (int i = 0; i < m_characters.size(); i++)
		this->m_characters.at(i).get()->drawObject(window);
}

void Board::drawGhosts(sf::RenderWindow &window)
{
	for (int i = 0; i < m_ghosts.size(); i++)
		this->m_ghosts.at(i).get()->drawObject(window);
}

/* This function is in charge of drawing the unmovables. */
void Board::drawUnmovables(sf::RenderWindow &window)
{
	for (int i = 0; i < m_unmovables.size(); i++)
		this->m_unmovables.at(i).get()->drawObject(window);
}

void Board::superPacman()
{
	if(!m_super){
		sf::Vector2f pos = m_characters[0]->getPosition();
		m_characters.clear();
		m_characters.push_back(std::make_unique<SuperPacman>(pos, superPac));
		m_characters[0]->setTexture(Textures::instance().getObjectTexture(superPac));
		m_super = true;
	}
	
}

void Board::regularPac()
{
	sf::Vector2f pos = m_characters[0]->getPosition();
	m_characters.clear();
	m_characters.push_back(std::make_unique<Pacman>(pos, pacman));
	m_characters[0]->setTexture(Textures::instance().getObjectTexture(pacman));
	m_super = false;
}

sf::Vector2f Board::getSpawnPos() const
{
	return m_startPosition;
}

void Board::setSpawnPos(const sf::Vector2f& loc)
{
	m_startPosition = loc;
}