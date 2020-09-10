/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the BananaRoom class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Space.hpp"

#ifndef BANANAROOM_HPP
#define BANANAROOM_HPP

class BananaRoom : public Space
{
	public:
		BananaRoom();						// default constructor
		~BananaRoom() {};					// destructor
		void reload() {};					// not needed for banana room
		void printKeyBag(std::string*);		// prints unlocked rooms
		void printRoomInfo();				// prints room info
		void run(std::string*, int);		// overrides Space function
		void printTable();					// prints unique image

};
#endif