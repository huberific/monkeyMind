/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the MainRoom class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Space.hpp"

#ifndef MAINROOM_HPP
#define MAINROOM_HPP

class MainRoom : public Space
{
	public:
		MainRoom();							// default constructor
		~MainRoom() {};						// destructor
		void reload();						// restores original class values
		void printKeyBag(std::string*);		// prints unlocked rooms
		void printTimeRem(int);				// prints time remaining in game
		void printRoomInfo();				// prints room header
		void run(std::string*, int);		// runs functionality of main room
		void buildTable();					// assigns chars to table
		void printTable();					// prints table (room image)

};
#endif