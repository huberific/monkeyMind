/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the implementation file for the BananaRoom class. It is
**				 a child class that inherits from the Space class.
*******************************************************************************/

#include "BananaRoom.hpp"

/*******************************************************************************
** Function:    BananaRoom
** Description: This is the default constructor.
*******************************************************************************/
BananaRoom::BananaRoom()
{
	this->roomNum = 5;
	this->name = "Banana Room";
	this->numCards = 1;
}

/*******************************************************************************
** Function:    reload
** Description: This function resets the class member variables and deletes
**				previous dynamic memory from a previous game.
*******************************************************************************/
void BananaRoom::printRoomInfo()
{	
	std::system("clear");
	std::cout << std::endl;

	// changes font color to yellow:
	// ref: https://stackoverflow.com/questions/2616906/
	//      how-do-i-output-coloured-text-to-a-linux-terminal
	std::cout << "\033[1;33m"

		<< "\t\t##    ##  #######  ##     ##    ##      ##  #######  "
		<< "##    ##    #### \n"
		<< "\t\t ##  ##  ##     ## ##     ##    ##  ##  ## ##     ## "
		<< "###   ##    #### \n"
		<< "\t\t  ####   ##     ## ##     ##    ##  ##  ## ##     ## "
		<< "####  ##    #### \n"
		<< "\t\t   ##    ##     ## ##     ##    ##  ##  ## ##     ## "
		<< "## ## ##     ##  \n"
		<< "\t\t   ##    ##     ## ##     ##    ##  ##  ## ##     ## "
		<< "##  ####         \n"
		<< "\t\t   ##    ##     ## ##     ##    ##  ##  ## ##     ## "
		<< "##   ###    #### \n"
		<< "\t\t   ##     #######   #######      ###  ###   #######  "
		<< "##    ##    #### \n"

	// change font color back to default:
		<< "\033[0m";
}

/*******************************************************************************
** Function:    printKeyBag
** Description: This function receives the keyBag string array and prints its
**			   	contents.
*******************************************************************************/
void BananaRoom::printKeyBag(std::string* keyBag)
{
	std::cout << "\t      Unlocked Rooms: ";
	
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
** Function:    printTable
** Description: This function overrides Space class function and prints the 
**				image below for a won game.
*******************************************************************************/
void BananaRoom::printTable()
{
	
// ref: https://www.asciiart.eu/food-and-drinks/bananas
// prints table represented as 2D array of chars

    std::cout << R"(

				                 __,__
				        .--.  .-"     "-.  .--.
				       / .. \/  .-. .-.  \/ .. \
				      | |  '|  /   Y   \  |'  | |
				      | \   \  \ 0 | 0 /  /   / |
				       \ '- ,\.-"`` ``"-./, -' /
				        `'-' /_   ^ ^   _\ '-'`
				        .--'|  \._ _ _./  |'--. 
				      /`    \   \.-.  /   /    `\
				     /       '._/  |-' _.'       \
				    /          ;  /--~'   |       \
				   /        .'\|.-\--.     \       \
				  /   .'-. /.-.;\  |\|'~'-.|\       \
				  \       `-./`|_\_/ `     `\'.      \
				   '.      ;     ___)        '.`;    /
				     '-.,_ ;     ___)          \/   /
				      \   ``'------'\       \   `  /
				       '.    \       '.      |   ;/_
 				             '.       \_ _ _/   ,  '--.
				   .'   '.   .-~~~~~-. /     |--'`~~-.  \
				  // / .---'/  .-~~-._/ / / /---..__.'  /
				 ((_(_/    /  /      (_(_(_(---.__    .'
				           | |     _              `~~`
				           | |     \'.
				            \ '....' |
				             '.,___.'

	)" << '\n';
}

/*******************************************************************************
** Function:    run
** Description: This function overrides the Space class function and just prints
**				the room name and the above image because the game is won!
*******************************************************************************/
void BananaRoom::run(std::string* keyBag, int timeElapse)
{
	this->printRoomInfo();
	this->printTable();
}