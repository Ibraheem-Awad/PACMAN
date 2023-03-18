# PACMAN
Object-Oriented Programming project.<br />
Pacman Game<br />
Written by: Ibrahim Awad.<br />

# General description
At this game your goal is to get Pacman to eat all the food.<br />
Pacman can turn into Super Pacman when it eats the proper food.<br />
Pacman loses a life when it collides with a ghost<br />
Super Pacman can break through walls and can't be eaten by the ghosts.<br />
The player loses when they lose all of their lives.<br />

There are multiple types of food that can be eaten:
1) Cherries to increase your score!
2) Keys to open doors.
3) Gifts to turn Pacman to Super Pacman.
4) Snow flakes to freeze to time for a short period.
5) Hearts to increase the number of of the player's lives
6) Clocks to add time

# Game in depth
The program will read 3 levels from one file,<br />
It will create an interface using SFML graphics and sound<br />
When the user runs the program we will see the menu which includes<br />
3 main buttons:<br />
The first one is for starting the game, the second is the Help button <br />
which will display the game instructions and features.<br />
the last one is to exit the game.<br />
When the player starts the game they will have 3 lives, the player loses life <br />
when it collides with a ghost, each level has multiple ghosts. When the player <br />
loses all three lives they lose the game.<br />
There will also be a timer, when the time finishes the game restarts.<br />
In order for the player to beat each level they have to eat all the food in the 
level. <br />
each level has a slightly increased difficulty<br />
the game also has different features that are triggered upon collecting gifts:<br />
Freezing gift that freezes all the ghosts in the game for a certain amount of time.<br />
Lives gift that increases the number of lives the player has.<br />
Time addition gift that will increase the player's time.<br />
Super gift that will turn Pacman to Super Pacman.<br />
There are also gates and keys, in order for pacman to open a gate and loot the food<br />
inside of the room, the player has to collect keys to open all of the gates.<br />
Unlike Pacman, Super Pacman doesn't lose lives when colliding with the ghosts,<br />
also it doesn't need keys to open the gates, Super Pacman can just simply smash it's
way through the gates, and after a certain amount of time, Super Pacman turns back into
Pacman and the game resumes.

# Technichalities and data structure
There are 23 Classes:
Controller, Buffers, Macros, Menu, Sound, Textures and Board, all of these classes don't
inherite anything.
GameObject: which is a class that has MovableObject and UnmovableObject inheriting from it
from UnmovableObject we inherite to the classes of Food, Gate, Key, Wall and Gift 
LifeGift, FreezeGift, SuperGift and TimeGift all inherite from the class Gift.
Player class inherites from MovableObject
Pacman and SuperPacman are both classes that inherite from Player Class.



# Input File
    
The input format of the file includes the number of rows and columns of the map
and which object will be included in each cell

# Files
Board.h
Signature of Board class and functions related to it
Buffers.h
Signature of Buffers class and functions related to it
Controller.h
Signature of Controller class and functions related to it
Food.h
Signature of Food class and functions related to it
FreezeGift.h
Signature of FreezeGift class and functions related to it
GameObject.h
Signature of GameObject class and functions related to it
Gate.h
Signature of Gate class and functions related to it
Gifts.h
Signature of Gifts class and functions related to it
Key.h
Signature of Key class and functions related to it
LifeGift.h
Signature of LifeGift class and functions related to it
Macros.h
Signature of Macros class and functions related to it
Menu.h
Signature of Menu class and functions related to it
MovableObject.h
Signature of MovableObject class and functions related to it
Pacman.h
Signature of Pacman class and functions related to it
Player.h
Signature of Player class and functions related to it
Sound.h
Signature of Sound class and functions related to it
SuperGift.h
Signature of SuperGift class and functions related to it
SuperPacman.h
Signature of SuperPacman class and functions related to it
Textures.h
Signature of Textures class and functions related to it
TimeGift.h
Signature of TimeGift class and functions related to it
UnmovableObject.h
Signature of UnmovableObject class and functions related to it
Wall.h
Signature of Wall class and functions related to it
The file that creates the class that controls the game and is in charge of all the other files
Menu.cpp
This file that has the buttons that the user can press at the beggining
Pacman.cpp
includes the functions of pacman

# Bugs
The entry spawn of the ghosts, it was difficult to get them to spawn
