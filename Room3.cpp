/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the implementation file for the Room3 class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "Room3.hpp"

/*******************************************************************************
** Function:    Room3
** Description: This is the default constructor.
*******************************************************************************/
Room3::Room3()
{
	this->roomNum = 3;			// holds room number
	this->name = "Room 3";
	this->hintTime = 3;			// holds time alotted for hint view
	this->numGuesses = 7;		// holds number of guesses permitted within room
	this->numHidden = 4;		// holds number of hidden dots
	this->numCards = 3;			// holds number of cards per row and col
	this->numAllCards = 9;
}

/*******************************************************************************
** Function:    reload
** Description: This function resets the class member variables and deletes
**				previous dynamic memory from a previous game.
*******************************************************************************/
void Room3::reload()
{
	if (this->table != nullptr)
	{
		for (int count = 0; count < tableRows; ++count)
			delete[] this->table[count];
		delete[] this->table;
	}

	if (this->numPermitted != nullptr)
		delete[] this->numPermitted;

	while (!hiddenItems.empty())
	{
		hiddenItems.pop();
	}

	while (!correctGuesses.empty())
	{
		correctGuesses.pop();
	}

	this->table = nullptr;
	this->numPermitted = nullptr;
	this->numGuesses = 7;		// holds number of guesses permitted within room
	this->numHidden = 4;		// holds number of hidden dots
	this->numCards = 3;			// holds number of cards per row and col
	this->numAllCards = 9;
}

/*******************************************************************************
** Function:    printRoomInfo
** Description: This function prints room info.
*******************************************************************************/
void Room3::printRoomInfo()
{
	std::cout << std::endl;

	// changes font color to yellow:
	// ref: https://stackoverflow.com/questions/2616906/
	//      how-do-i-output-coloured-text-to-a-linux-terminal
	std::cout << "\033[1;33m"

		<< "\t\t\t########   #######   #######  ##     ##     #######  \n"
		<< "\t\t\t##     ## ##     ## ##     ## ###   ###    ##     ## \n"
		<< "\t\t\t##     ## ##     ## ##     ## #### ####           ## \n"
		<< "\t\t\t########  ##     ## ##     ## ## ### ##     #######  \n"
		<< "\t\t\t##   ##   ##     ## ##     ## ##     ##           ## \n"
		<< "\t\t\t##    ##  ##     ## ##     ## ##     ##    ##     ## \n"
		<< "\t\t\t##     ##  #######   #######  ##     ##     #######  \n"

	// change font color back to default:
		<< "\033[0m";
}