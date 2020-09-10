/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Room1 class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Space.hpp"

#ifndef ROOM1_HPP
#define ROOM1_HPP

class Room1 : public Space
{
	public:
		Room1();				// default constructor
		~Room1() {};			// destructor
		void reload();			// resets class member variables to originals
		void printRoomInfo();	// prints unique game play table

};
#endif