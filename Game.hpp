/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Game class. This class
**				 controls the game flow.
*******************************************************************************/
#include "Menu.hpp"
#include "Space.hpp"
#include "MainRoom.hpp"
#include "Room1.hpp"
#include "Room2.hpp"
#include "Room3.hpp"
#include "Room4.hpp"
#include "BananaRoom.hpp"
#include <thread>					// used for pausing screen
#include <chrono>					// used for pausing screen
using namespace std::this_thread;	// needed for pausing 
using namespace std::chrono;		// needed for time functions

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	private:
		Menu menu;
		MainRoom mainRoom;
		Room1 room1;
		Room2 room2;
		Room3 room3;
		Room4 room4;
		BananaRoom bananaRoom;
		Space* currentRoom;			// pointer used for controlling above rooms
		std::string keyBag[5];		// holds unlocked rooms
		int currentRoomNum;			// current room number
		int timeElapse;				// holds elapsed time in seconds (needs <90)
		bool gameWon;				// if true, you won the game
		void printWelcomePage();	// prints welcome page
		void printInstructions();	// prints instructions of game
		void printLosePage();		// prints if you lose (out of time)
		bool outOfTime;				// if true, you're out of time

	public:
		Game();						// default constructor
		~Game() {};					// destructor
		void reload();				// reloads rooms and variables for new game
		void run();					// runs main game flow
};
#endif