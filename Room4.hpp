/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Room4 class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Space.hpp"

#ifndef ROOM4_HPP
#define ROOM4_HPP

class Room4 : public Space
{
	public:
		Room4();				// default constructor
		~Room4() {};			// destructor
		void reload();			// resets class member variables to originals
		void printRoomInfo();	// prints unique game play table

};
#endif