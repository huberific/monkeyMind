/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Room2 class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Space.hpp"

#ifndef ROOM2_HPP
#define ROOM2_HPP

class Room2 : public Space
{
	public:
		Room2();				// default constructor
		~Room2() {};			// destructor
		void reload();			// resets class member variables to originals
		void printRoomInfo();	// prints unique game play table

};
#endif