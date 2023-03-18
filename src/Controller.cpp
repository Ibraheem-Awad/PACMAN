#include "Controller.h"

/* Constructor of the controller. */
Controller::Controller()
    : m_win(true), m_pause(false), m_helpMode(false), m_lives(3), m_score(0), m_superPac(false), m_superTimer(0)
{
    this->initVars();
    this->loadLevelsBG(); // Loads the backgrounds for the levels.
    this->loadLevelUpandWinGame(); // Loads the sprites of the level-up and game win.
}

/* Main function of the program. 
 * The function runs the menu (by making it run itsghost) and the game. */
void Controller::run()
{
    this->loadMenu(); // Loads the menu.
    m_clock.restart(); // Restarts the clock before starting.
    this->getNext(); // First level seperately.
    this->initTimeSet(); // Sets the time display.

    // Repositions the "help mode" display positions.
    this->m_menu.setHelpAndExitPos(sf::Vector2f((gameWidth - menuWidth) / 2, (gameHeight - menuHeight) / 2), 
                                   sf::Vector2f(((gameWidth - menuWidth) / 2) + buttonWidth, ((gameHeight - menuHeight) / 2) + buttonHeight));

    /* Game loop. */
    while (m_window->isOpen())
    {
        /* If won level (perhaps the last level). */
        if (this->m_win)
            this->winLevel();

        /* Updates the state of the game.. */
        update();

        /* Renders. */
        render();

        erase();
    }
}

/* This function is in charge of loading the menu of the game. */
void Controller::loadMenu()
{
    this->m_sound.playMusic("menuMusic.ogg"); // Menu bg music.
    this->m_menu.runMenu(this->m_sound); // Menu loop activation.
    this->m_sound.stopMusic(); // Stops the bg music after the loop.
}

/* This function is in charge of updating the current game state. */
void Controller::update()
{
    if (m_lives < 0) {
        this->m_win = false;
        this->restartLevel();
    }
    if (m_board.getFoodCounter() == 0)
        this->m_win = true;

    if(m_superPac)
       convertToSuper();
    
    this->pollEvents(); // Handles new events.
    const sf::Time deltaTime = m_clock.restart(); // deltaTime saves time passed.

    if (!this->m_pause && !this->m_helpMode) // If we're not in pause or help mode.
    {
        this->updateTime(deltaTime);
        this->moveCurrent(deltaTime); // Moves currently played character.
        std::srand((unsigned)std::time(NULL)); // Polls a set of random numbers.
        
        
        if (m_stopShadow == 0) 
            this->moveGhost(deltaTime); 
        else
            m_stopShadow--;
    }
}

/* This function is in charge of handling events. */
void Controller::pollEvents()
{
    /* Events loop. */
    while (this->m_window->pollEvent(this->m_event))
    {
        switch (this->m_event.type)
        {
        /* In case the game was closed. */
        case sf::Event::Closed:
            this->m_window->close();
            break;

        /* In case the user pressed a key. */
        case sf::Event::KeyPressed:
            if (this->m_event.key.code == sf::Keyboard::Escape) // If escape key then close.
                this->m_window->close();

            if (!this->m_pause && !this->m_helpMode) // If we're not in pause or help mode then respond to the keyboard.
                this->handleKeyPressed();
            break;

        default:
            // In any case, we want to set the direction of the currently played character.
            m_board.getCharacters()[m_board.getCurrChar()]->setDirection(sf::Keyboard::Unknown);
            break;
        }
    }
}

/* This function is in charge of moving the currently played character. */
void Controller::moveCurrent(const sf::Time deltaTime)
{
    int index = m_board.getCurrChar(); // Takes the index of the curr character.
    auto size = this->m_board.getBoardSize();
    // fixedPos is the start position (top left corner) of the game board.
    auto fixedPos = sf::Vector2u((gameWidth - (size.x * BLOCK_SIZE)) / 2, (gameHeight - (size.y * BLOCK_SIZE)) / 2);
    // The player moves itsghost.
    m_board.getCharacters()[index]->move(deltaTime, fixedPos, sf::Vector2u(this->m_video.width, this->m_video.height));

    /* Handling collisions */
    unmovableCollision();
    ghostCollision();
}

/* This function is in charge of handling the keyboard key pressed by the user. */
void Controller::handleKeyPressed()
{
    // Sets the direction of the character.
    m_board.getCharacters()[m_board.getCurrChar()]->setDirection(this->m_event.key.code);
 
    // Mute sounds and music.
    if (this->m_event.key.code == sf::Keyboard::M)
        this->m_sound.muteVolume();
}

/* This function is in charge of managing the win of a level. */
void Controller::winLevel()
{
    sf::Time timer = cooldown; // Sets a timer to display the banner (win level or win game).
    this->m_clock.restart();

    if (this->m_board.getCurrLevel() < this->m_board.getNumofLevels() - 1)  // Minus the last level.
    {
        this->m_sound.playSound(winLevelSound);
        this->m_window->draw(this->m_levelUpBanner);
    }
    else // Won game.
    {
        this->m_sound.playSound(winGameSound);
        this->m_window->draw(this->m_winGameBanner);
    }

    // Displays the window with the banner.
    this->m_window->display();

    // Timer loop.
    while (timer.asSeconds() > endTime)
        timer -= m_clock.restart();
    unsigned int size = m_board.getGhosts().size();
    m_score = m_score + 50 + (size * 2);
    this->getNext(); // Loads next level.
}

/* This function is in charge of updating the time. */
void Controller::updateTime(const sf::Time deltaTime)
{
    char timeInChars[50] = { 0 }; // Buffer.
    std::string printed;
    printed = "Lives: " + std::to_string(m_lives) + "           Score: " + std::to_string(m_score) + "           Time Left: ";
    if (this->m_board.isTimeLim()) // If there's a time limit.
        this->m_time -= deltaTime;
    else
        this->m_time += deltaTime;

    // If the time's not up.
    if (this->m_time.asSeconds() > endTime)
    {
        if (this->m_time.asSeconds() <= 10 && this->m_board.isTimeLim()) // Last 10 seconds warning.
        {
            this->m_timeText.setFillColor(sf::Color::Red);
            this->m_timeText.setOutlineColor(sf::Color::White);
            this->m_timeText.setOutlineThickness(2);
            this->m_infoBG.setOutlineColor(sf::Color::Red);
        }

        _itoa((int)this->m_time.asSeconds(), timeInChars, 10);
        printed += timeInChars;
        this->m_timeText.setString(printed);

    }
    else
        this->restartLevel(); // Restarts the level if time's up.
}

/* This function is in charge of handling the area which the game is played on. */
void Controller::handleGameBoard()
{
    auto size = this->m_board.getBoardSize();

    auto fixedPos = sf::Vector2f((gameWidth - (size.x * BLOCK_SIZE)) / 2, (gameHeight - (size.y * BLOCK_SIZE)) / 2);
    this->m_board.setBoardframe(sf::Vector2f(this->m_video.width, this->m_video.height), fixedPos);
}

/* This function decreases the current level number because getNext() increases it. */
void Controller::restartLevel()
{
    m_score = 0;
    m_lives = 3;
    this->m_board.setCurrLevel(this->m_board.getCurrLevel() - 1);
    this->getNext();
}

/* This function is in charge of updating the bottom right corner of the game board. */
void Controller::updateVideo()
{
    auto size = this->m_board.getBoardSize();
    // fixedPos is the start position (top left corner) of the game board.
    auto fixedPos = sf::Vector2f((gameWidth - (size.x * BLOCK_SIZE)) / 2, (gameHeight - (size.y * BLOCK_SIZE)) / 2);

    // Updates the bottom right corner.
    this->m_video.height = gameHeight - fixedPos.y;
    this->m_video.width = gameWidth - fixedPos.x;
}

void Controller::convertToSuper()
{
    m_board.superPacman();
    
    // if time is up
    if (m_time.asSeconds() < m_superTimer) {
        m_board.regularPac();
        m_superTimer = 9999;
        m_superPac = false;
    }
}

/* This function is in charge of displaying the game. */
void Controller::render()
{
    this->m_window->clear(sf::Color{ 0x373737FF });

    /* Background of the level and background of the game board. */
    unsigned int currBG = (this->m_board.getCurrLevel() - 1) % numofLevelsBG;
    this->m_window->draw(this->m_levelsBGSprites[currBG]);
    this->m_window->draw(this->m_board.getBoardFrame());

    /* Objects. */
    m_board.drawGhosts(*this->m_window);
    m_board.drawUnmovables(*this->m_window);
    m_board.drawCharacters(*this->m_window);

    /* Timer. */
    this->m_window->draw(this->m_infoBG);
    this->m_window->draw(this->m_timeText);

    /* Help mode drawings. */
    if (this->m_helpMode)
    {
        this->m_window->draw(this->m_menu.getMenuSprite(helpDisplay));

        if(this->m_helpExitHover)
            this->m_window->draw(this->m_menu.getMenuSprite(exitHelpHL));
        else
            this->m_window->draw(this->m_menu.getMenuSprite(exitHelp));
    }

    this->m_window->display();
}

/* This function is in charge of hadling collisions of currently played player with unmovables. */
void Controller::unmovableCollision()
{
    auto index = m_board.getCurrChar();
    unsigned int curScore = getScore();
    unsigned int curLives = getLives();

    // Loops through the unmovables.
    for (auto& unmovable : m_board.getUnmovables())
        if (m_board.getCharacters()[index]->collidesWith(*unmovable))
        {
            m_board.getCharacters()[index]->handleCollision(*unmovable);

            if(unmovable->getAteKey())
                setScore(curScore + 7);

            else if (unmovable->getAteFood()) {
                setScore(curScore + 3);
                unsigned int temp = m_board.getFoodCounter();
                m_board.setFoodCounter(--temp);
            }

            else if (unmovable->getAteLifeGift()) {
                setScore(curScore + 5);
                setLives(++curLives);
            }
            else if (unmovable->getAteFreezeGift()) {
                freezeGhosts();
                setScore(curScore + 5);
            }

            else if (unmovable->getAteSuperGift()) {
                m_superTimer = m_time.asSeconds() - 5;
                m_superPac = true;
                convertToSuper();
                setScore(curScore + 5);
            }

            // For dynamic casting.
            this->handleSounds(unmovable.get());
        }
}

/* This function is in charge of loading the backgrounds of the levels. */
void Controller::loadLevelsBG()
{
    for (int i = 0; i < numofLevelsBG; i++)
    {
        sf::Sprite tempSprite;
        tempSprite.setTexture(*Textures::instance().getLevelBGTexture((LevelsBG_t)i));
        this->m_levelsBGSprites.push_back(tempSprite);
    }
}

/* This function is in charge of getting the next level. */
void Controller::getNext()
{
    // If you can't get another level you've probably won.
    if (!this->m_board.loadLevel())
    {
        std::cout << "You win!\n";
        this->m_sound.stopMusic();
        exit(EXIT_SUCCESS);
    }
    
    this->updateVideo(); // Updates the bottom right corner of the game board.
    this->m_board.adjustObjects(); // Adjusts the objects' locations.

    if(!this->m_window) // Initiates the window if needed.
        this->initWindow();

    // Updates between levels.
    this->updateThemeMusic();
    this->initTimeSet();
    this->handleGameBoard();
    this->resetWinCon();
}

/* Resets win con. */
void Controller::resetWinCon()
{
    this->m_win = false;   
}

/* This function is in charge of erasing the objects which were set to be erased. */
void Controller::erase()
{
    // Unmovables.
    std::erase_if(m_board.getUnmovables(), [](auto& unmovable)
        {
            return unmovable->isDisposed();
        });

    std::erase_if(m_board.getGhosts(), [](auto& ghost)
        {
            return ghost->isDisposed();
        });
}

// Initiates window to nullptr.
void Controller::initVars()
{
    this->m_window = nullptr;
}

/* Initiates the game window. */
void Controller::initWindow()
{
    this->m_video.height = gameHeight;
    this->m_video.width = gameWidth;
    this->m_window = new sf::RenderWindow(this->m_video, GAME_NAME, sf::Style::Fullscreen);
    this->updateVideo();
}

/* This function is in charge of initiating the time display. */
void Controller::initTimeSet()
{
    // Time text visuals.
    this->m_time = sf::seconds(m_board.getTime());
    this->m_timeFont.loadFromFile("digital.ttf");
    this->m_timeText.setFont(this->m_timeFont);
    this->m_timeText.setCharacterSize(50);
    this->m_timeText.setFillColor(sf::Color::White);
    this->m_timeText.setOutlineThickness(0);

    // Time text location.
    auto size = this->m_board.getBoardSize();
    auto pos = sf::Vector2f(this->m_video.width /*- BLOCK_SIZE*/, (gameHeight - (size.y * BLOCK_SIZE)) / 2 - BLOCK_SIZE); // for rect
    this->setTimeBG(pos);
    pos = sf::Vector2f(this->m_video.width - 900, (gameHeight - (size.y * BLOCK_SIZE)) / 2 - BLOCK_SIZE - GAP); // for text
    this->m_timeText.setPosition(pos);
  
}

/* This function is in charge of updating the background music of the level. */
void Controller::updateThemeMusic()
{
    switch ((this->m_board.getCurrLevel() % 3) + 1)
    {
    case firstTheme:
        this->m_sound.stopMusic();
        this->m_sound.playMusic("firstLevelMusic.ogg");
        break;

    case secondTheme:
        this->m_sound.stopMusic();
        this->m_sound.playMusic("secondLevelMusic.ogg");
        break;

    case thirdTheme:
        this->m_sound.stopMusic();
        this->m_sound.playMusic("thirdLevelMusic.ogg");
        break;

    default: break;
    }
}

/* This function is in charge of handling the sounds of the game. */
void Controller::handleSounds(GameObject* object)
{
    auto index = m_board.getCurrChar();

    /*---------------------- Dynamic cast -----------------------*/
    /* Player encountered a time gift. */
    if (TimeGift* timegift = dynamic_cast<TimeGift*>(object))
    {
        this->m_sound.playSound(collectGiftSound);
        this->m_time += sf::seconds(5);
        setScore(getScore()+ 5);

    }

    if (Key* key = dynamic_cast<Key*>(object))
    {
        if (key->isDisposed())
            this->m_sound.playSound(keyLoot);
    }

    if (Gate* gate = dynamic_cast<Gate*>(object))
    {
        if (gate->isDisposed())
            this->m_sound.playSound(gateOpen);
        else
            this->m_sound.playSound(bumpIntoWall);
    }
    /*-----------------------------------------------------------*/

    /*---------------------- RTTI -----------------------*/

    /* Player encountered a wall. */
    if (typeid(Wall) == typeid(*object))
        this->m_sound.playSound(bumpIntoWall);

    /*---------------------------------------------------*/
}

int Controller::getLives() const
{
    return m_lives;
}

int Controller::getScore() const
{
    return m_score;
}

void Controller::setLives(int lives)
{
    m_lives = lives;
}

void Controller::setScore(int score)
{
    m_score = score;
}

void Controller::freezeGhosts()
{
    setStopShadow();
}

/* This function is in charge of setting the time text background visuals and position. */
void Controller::setTimeBG(sf::Vector2f pos)
{
    this->m_infoBG.setFillColor(sf::Color::Black);
    this->m_infoBG.setOutlineColor(sf::Color::White);
    this->m_infoBG.setOutlineThickness(2);
    this->m_infoBG.setSize(sf::Vector2f(-964, 70));
    this->m_infoBG.setPosition(sf::Vector2f(pos.x, pos.y - 12));
}

/* This function is in charge of loading the textures and setting the positions of the win level/game banners. */
void Controller::loadLevelUpandWinGame()
{
    this->m_levelUpBanner.setTexture(*Textures::instance().getLevelUpBannerTexture());
    this->m_levelUpBanner.setPosition(sf::Vector2f((gameWidth - lvUpWidth) / 2, (gameHeight - lvUpHeight) / 2));

    this->m_winGameBanner.setTexture(*Textures::instance().getWinGameBannerTexture());
    this->m_winGameBanner.setPosition(sf::Vector2f((gameWidth - winGameBannerWidth) / 2, (gameHeight - winGameBannerHeight) / 2));
}

void Controller::moveGhost(const sf::Time deltaTime)
{
    auto size = this->m_board.getBoardSize();
    // fixedPos is the start position (top left corner) of the game board.
    auto fixedPos = sf::Vector2u((gameWidth - (size.x * BLOCK_SIZE)) / 2, (gameHeight - (size.y * BLOCK_SIZE)) / 2);

    for (auto& ghost : m_board.getGhosts())
    {
        ghost->move(deltaTime, fixedPos, sf::Vector2u(this->m_video.width, this->m_video.height));

        for (auto& unmovable : m_board.getUnmovables())
            if (ghost->collidesWith(*unmovable))
                unmovable->handleCollision(*ghost);

        for (auto& player : m_board.getCharacters()){

            if (ghost->collidesWith(*player))
            {
                player->handleCollision(*ghost);
                ghost->handleCollision(*player);
                m_lives--;
                break;
            }
            else if (player->collidesWith(*ghost)) {
                player->handleCollision(*ghost);
                ghost->handleCollision(*player);
                m_lives--;
                break;
            }
        }
    }
}

void Controller::setStopShadow()
{
    m_stopShadow = 2000;
}

void Controller::ghostCollision()
{
    int index = m_board.getCurrChar();

    for (auto& ghost : m_board.getGhosts())
        if (m_board.getCharacters()[index]->collidesWith(*ghost)){
            m_board.getCharacters()[index]->handleCollision(*ghost);
        }

}