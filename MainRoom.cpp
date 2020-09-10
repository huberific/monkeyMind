/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the implementation file for the MainRoom class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "MainRoom.hpp"

/*******************************************************************************
** Function:    MainRoom
** Description: This is the default constructor.
*******************************************************************************/
MainRoom::MainRoom()
{
	this->roomNum = 0;
	this->name = "Main Room";
	this->numCards = 5;
}

/*******************************************************************************
** Function:    reload
** Description: This function resets the class member variables and deletes
**				previous dynamic memory from a previous game.
*******************************************************************************/
void MainRoom::reload()
{
	if (this->table != nullptr)
	{
		for (int count = 0; count < tableRows; ++count)
			delete[] this->table[count];
		delete[] this->table;
	}

	this->table = nullptr;
}

/*******************************************************************************
** Function:    printRoomInfo
** Description: This function prints room info.
*******************************************************************************/
void MainRoom::printRoomInfo()
{	
	std::system("clear");
	std::cout << std::endl;

	// changes font color to yellow:
	// ref: https://stackoverflow.com/questions/2616906/
	//      how-do-i-output-coloured-text-to-a-linux-terminal
	std::cout << "\033[1;33m"

		<< "\t   ##     ##    ###    #### ##    ##    ########   #######   "
		<< "#######  ##     ## \n"
		<< "\t   ###   ###   ## ##    ##  ###   ##    ##     ## ##     ## ##  "
		<< "   ## ###   ### \n"
		<< "\t   #### ####  ##   ##   ##  ####  ##    ##     ## ##     ## ## "
		<< "    ## #### #### \n"
		<< "\t   ## ### ## ##     ##  ##  ## ## ##    ########  ##     ## ## "
		<< "    ## ## ### ## \n"
		<< "\t   ##     ## #########  ##  ##  ####    ##   ##   ##     ## ##  "
		<< "   ## ##     ## \n"
		<< "\t   ##     ## ##     ##  ##  ##   ###    ##    ##  ##     ## ##  "
		<< "   ## ##     ## \n"
		<< "\t   ##     ## ##     ## #### ##    ##    ##     ##  #######   "
		<< "#######  ##     ##\n"

	// change font color back to default:
		<< "\033[0m";
}

/*******************************************************************************
** Function:    printKeyBag
** Description: This function receives the keyBag string array and prints its
**			   	contents.
*******************************************************************************/
void MainRoom::printKeyBag(std::string* keyBag)
{
	std::cout << "\t\t    Unlocked Rooms: ";
	
	for (int i = 0; i < 5; i++)
	{
		if (keyBag[i] != "empty")
		{
			std::cout << "[" << "\033[33m" << keyBag[i] << "\033[0m" << "] ";
		}
		else
			std::cout << "[" << keyBag[i] << "] ";
	}
}

/*******************************************************************************
** Function:    buildTable
** Description: This function assigns characters necessary to create room image.
*******************************************************************************/
void MainRoom::buildTable()
{
	// variables used divide board evenly for 2D array layout:
	this->rowDiv = tableRows / 2;
	this->colDiv = tableCols / (this->numCards + 1);

	// assign table top and bottom row characters:
	for (int i = 1; i < tableCols - 1; i++)
	{
		this->table[0][i] = '-';
		this->table[tableRows - 1][i] = '-';
	}

	// assign table corner characters:
	this->table[0][0] = '+';
	this->table[0][tableCols - 1] = '+';
	this->table[tableRows - 1][0] = '+';
	this->table[tableRows - 1][tableCols - 1] = '+';

	// assign table side characters:
	for (int i = 1; i < tableRows - 1; i++)
	{
		this->table[i][0] = '|';
		this->table[i][tableCols - 1] = '|';
	}

	// assign all "cells" within table boundary to blank:
	for (int i = 1; i < tableRows - 1; i++)
		for (int j = 1; j < tableCols - 1; j++)
			this->table[i][j] = 32;

	// assigns all card properties (including numbers):
	for (int m = 1; m < (numCards + 1); m++)
	{
		for (int n = 1; n < 2; n++)
		{
			// assign top and bottom of card:
			for (int i = -6; i < 6; i++)
			{
				this->table[n * this->rowDiv - 6][m * this->colDiv + i] = '-';
				this->table[n * this->rowDiv + 5][m * this->colDiv + i] = '-';
			}

			// assign sides of card:
			for (int i = -5; i < 5; i++)
			{
				this->table[n * this->rowDiv + i][m * this->colDiv - 7] = '|';
				this->table[n * this->rowDiv + i][m * this->colDiv + 6] = '|';
			}

			// assign door numbers:
			char colChar = '0' + m;		// converts n to char

			this->table[n * this->rowDiv - 3][m * this->colDiv] = colChar;

			// print door handle:
			this->table[n * this->rowDiv][m * this->colDiv + 4] = 'o';

			// print Bananas room
			if (m == numCards)
			{
				this->table[n * this->rowDiv - 3][m * this->colDiv - 3] = 'B';
				this->table[n * this->rowDiv - 3][m * this->colDiv - 2] = 'a';	
				this->table[n * this->rowDiv - 3][m * this->colDiv - 1] = 'n';
				this->table[n * this->rowDiv - 3][m * this->colDiv] = 'a';		
				this->table[n * this->rowDiv - 3][m * this->colDiv + 1] = 'n';
				this->table[n * this->rowDiv - 3][m * this->colDiv + 2] = 'a';
				this->table[n * this->rowDiv - 3][m * this->colDiv + 3] = 's';	
			}
		}
	}
}

/*******************************************************************************
** Function:    printTable
** Description: This function prints whatever is currently assigned to the table
*******************************************************************************/
void MainRoom::printTable()
{
	for (int i = 0; i < tableRows; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < tableCols; j++)
		{
			if (this->table[i][j] != '+' && this->table[i][j] != '-' &&
				this->table[i][j] != '|' && this->table[i][j] != 'o')
			{
				// font color change:
				std::cout << "\033[33m" << this->table[i][j] << "\033[0m";
			}
			else
				std::cout << this->table[i][j];
		}

	}
	std::cout << std::endl;
}

/*******************************************************************************
** Function:    printTimeRem
** Description: This function receives the current elapsed time during game play
**				and calculates the time remaining from 90 seconds. It prints
**				the results. Negative numbers are set to 0.
*******************************************************************************/
void MainRoom::printTimeRem(int timeElapse)
{
	int timeRem = 90 - timeElapse;

	if (timeRem <= 90)
	{
		if (timeRem < 0)
			timeRem = 0;

		std::cout << "\n\t\t\t\t    Time Remaining: " << timeRem << " seconds";
	}
}

/*******************************************************************************
** Function:    run
** Description: This function carries out the game play of the room. Time is
**				is printed. All info is printed.
*******************************************************************************/
void MainRoom::run(std::string* keyBag, int timeElapse)
{
	this->printRoomInfo();
	this->printKeyBag(keyBag);
	this->printTimeRem(timeElapse);
	this->newTable();
	this->buildTable();
	this->printTable();
}