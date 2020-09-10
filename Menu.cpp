/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the implementation file for the Menu class. This class
**				 outputs user interface with the game, receives inputs, and
**				 validates them against acceptable criteria.
*******************************************************************************/

#include "Menu.hpp"

/*******************************************************************************
** Function:     Menu
** Description:  This is the default constructor. All member variables are set
**				 to either zero or blank.
*******************************************************************************/
Menu::Menu() :
	choiceStr{"\0"}, choiceInt{0}, ptrChoiceInt{&choiceInt}, validInput{true} {}

/*******************************************************************************
** Function:     runGameMenu
** Description:  The runGameMenu function carries out the functions of printing 
**               the game menu, receiving input, sending it for validation via  
**               numValidateArray, and continuing until valid input is given.
**
**				 Steps are included to control function calls when menu options
**				 are chosen.
*******************************************************************************/
void Menu::runGameMenu(int* numPermitted, int numAllCards, 
					   std::queue <int> numGuessed)
{
    choiceInt = 0;					// resets menu choice to 0 for functionality
	printGameMenu();

	numValidateArray(numPermitted, numAllCards, numGuessed);

    while (!validInput)
    {
        std::cout << "Oops! Invalid entry. Please try again: ";
		numValidateArray(numPermitted, numAllCards, numGuessed);
    }
}

/*******************************************************************************
** Function:     runMainRoomMenu
** Description:  The runMainRoomMenu function carries out the functions of  
**               printing the game menu, receiving input, sending it for 
**               validation via numValidate, and continuing until valid input 
**				 is given.
**
**				 Steps are included to control function calls when menu options
**				 are chosen.
*******************************************************************************/
void Menu::runMainRoomMenu(std::string roomName)
{
    choiceInt = 0;					// resets menu choice to 0 for functionality
	printMainRoomMenu(roomName);
	std::cout << "Selection: ";
	numValidate(1, 2);

    while (!validInput)
    {
        std::cout << "Oops! Invalid entry. Please try again: ";
		numValidate(1, 2);
    }
}

/*******************************************************************************
** Function:     runPlayAgain
** Description:  The function carries out the functions of printing the play
**               again menu, receiving input, sending it for validation via  
**               numValidate, and continuing until valid input is given.
**
**				 Steps are included to control function calls when menu options
**				 are chosen.
*******************************************************************************/
void Menu::runPlayAgain()
{
    choiceInt = 0;					// resets menu choice to 0 for functionality
	printPlayAgain();
    std::cout << "\nSelection: ";
	numValidate(1, 2);

    while (!validInput)
    {
        std::cout << "Oops! Invalid entry. Please try again: ";
		numValidate(1, 2);
    }
}

/*******************************************************************************
** Function:     runMain
** Description:  The runMain function carries out the functions of printing the 
**               main menu, receiving input, sending it for validation via  
**               numValidate, and continuing until valid input is given.
**
**				 Steps are included to control function calls when menu options
**				 are chosen.
*******************************************************************************/
void Menu::runMain()
{
    choiceInt = 0;					// resets menu choice to 0 for functionality
	printMain();
    std::cout << "\t\t\t\t   Selection: ";
	numValidate(1, 2);

    while (!validInput)
    {
        std::cout << "\t\t\t\t   Oops! Invalid entry. Please try again: ";
		numValidate(1, 2);
    }
}

/*******************************************************************************
** Function:     printMainRoomMenu
** Description:  The printMainRoomMenu function prints a game play menu.
*******************************************************************************/
void Menu::printMainRoomMenu(std::string roomName)
{
	choiceInt = 0;									// reset for menu
			
	std::cout << "Monkey517, select an action:\n"
			  << std::endl;
	std::cout << "\t1. Enter " << roomName << std::endl;
	std::cout << "\t2. Exit game\n" << std::endl;
}


/*******************************************************************************
** Function:     printGameMenu
** Description:  The printGameMenu function prints a game play menu.
*******************************************************************************/
void Menu::printGameMenu()
{
	std::cout << "Monkey517, enter a card number (e.g. \"11\") containing "
			  << "a red dot: ";
}

/*******************************************************************************
** Function:     runHintMenu
** Description:  The printGameMenu function prints a helpful message.
*******************************************************************************/
void Menu::runHintMenu()
{
	std::cout << "Okay Monkey517, remember where these red dots are located!"
			  << std::endl;
}

/*******************************************************************************
** Function:     runSuccessMenu
** Description:  Prints message if monkey solves room challenge successfully.
*******************************************************************************/
void Menu::runSuccessMenu(std::string roomName)
{
	if(roomName == "Banana Room")
	{
		std::cout << "Congratulations Monkey517! You've unlocked the " 
				  << roomName << "!\n"
			  << "Press [enter] to exit to the main room: ";
	}

	else
	{
		std::cout << "Well done Monkey517! You've unlocked " 
				  << roomName << "!\n"
			  << "Press [enter] to exit to the main room: ";
	}

	std::cin.ignore();
}

/*******************************************************************************
** Function:     runFailMenu
** Description:  Prints message if Monkey doesn't solve the room challenge.
*******************************************************************************/
void Menu::runFailMenu(std::string roomName)
{
	std::cout << "Too bad, Monkey517! You'll have to try "
			  << roomName << " again if you still have time.\n"
			<< "Press [enter] to exit to the main room: ";
	std::cin.ignore();
}

/*******************************************************************************
** Function:     printPlayAgain
** Description:  The printPlayAgain message asks the user if they would like to
**				 play again.
*******************************************************************************/
void Menu::printPlayAgain()
{
	choiceInt = 0;									// reset for menu
			
	std::cout << "Would you like to play again? Please make a selection.\n"
			  << std::endl;
	std::cout << "\t1. Play again" << std::endl;
	std::cout << "\t2. Exit game" << std::endl;
}

/*******************************************************************************
** Function:     printMain
** Description:  The printMain function prints the main menu to allowing the
**				 user to play the game or exit.
*******************************************************************************/
void Menu::printMain()
{
	choiceInt = 0;									// reset for menu

	std::cout << "\t\t\t\t   Select from the following choices:\n" << std::endl;
	std::cout << "\t\t\t\t     1. Play Monkey Mind" << std::endl;
	std::cout << "\t\t\t\t     2. Exit\n" << std::endl;
}

int Menu::getChoiceInt()
{
    return choiceInt;
}

std::string Menu::getChoiceStr()
{
    return choiceStr;
}

/*******************************************************************************
** Function:    reset
** Description: This function resets the choiceInt to zero and prevents the 
**				the screen from jumping too quickly with a simple user input.
*******************************************************************************/
void Menu::reset()
{
	choiceInt = 0;
	std::cout << "\nPress [enter] to continue: ";
	std::cin.ignore();
}

/*******************************************************************************
** Function:    numValidate
** Description: This function gets input from the user and sends it for
**				validation using validateNumChoice function call. It receives 
**				the minimum number permitted and maximum number permitted.
*******************************************************************************/
void Menu::numValidate(int min, int max)
{
	std::getline(std::cin, choiceStr);

    // send string input to validateNumChoice function. the first
    // parameter is the input string, next is the minimum number allowed, 
	// followed by the maximum permitted. the last parameter is the pointer to 
	// the choiceInt variable where it is revised with valid entries. Note: the 
	// validateNumChoice function returns a boolean value
    validInput = validateNumChoice(choiceStr, min, max, ptrChoiceInt);
}

/*******************************************************************************
** Function:    numValidateArray
** Description: This function gets input from the user and sends it for
**				validation using validateNumArray function call. The number is
**				checked against values within array of acceptable entries.
*******************************************************************************/
void Menu::numValidateArray(int* numPermitted, int numAllCards, 
						    std::queue <int> numGuessed)
{
	std::getline(std::cin, choiceStr);

    // send string input to validateNumArray function. the first
    // parameter is the input string, next is the array of values allowed, 
	// followed by the last parameter which is the pointer to 
	// the choiceInt variable where it is revised with valid entries. Note: the 
	// validateNumChoice function returns a boolean value
    validInput = validateNumArray(choiceStr, numPermitted, numAllCards,
								  numGuessed, ptrChoiceInt);
}