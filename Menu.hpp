/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Menu class. This class
**				 outputs user interface with the game, receives inputs, and
**				 validates them against acceptable criteria.
*******************************************************************************/

#include "ValidateNum.hpp"
#include <queue>
#include <iostream>
#include <string>

#ifndef MENU_HPP
#define MENU_HPP
class Menu
{
    private:
        std::string  choiceStr;                    // user input as string
        int          choiceInt;                    // converted int from string
        int*         ptrChoiceInt;                 // pointer to choiceInt
        bool         validInput;                   // holds T/F for valid input
    	void 	     printGameMenu();    		   // prints game play menu
		void		 printMain();				   // prints main menu
		void		 printPlayAgain();			   // prints play again menu
		void	     numValidate(int, int);	       // gets input and validates
		void		 reset();					   // resets before menu return

		// print main room menu:
		void 		 printMainRoomMenu(std::string);	 
		
		// get input and check against numbers permitted or numbers guessed:
		void		 numValidateArray(int*, int, std::queue <int>);

    public:
        Menu();                                    // default constructor		
		void 		runMain();					   // runs main menu before game
		void 		runMainRoomMenu(std::string);  // runs main room menu
		void		runFailMenu(std::string);	   // runs if monkey fails rm
        int         getChoiceInt();                // returns choice as int
		std::string getChoiceStr();				   // returns input as string
		void		runPlayAgain();				   // runs play again menu
		void 		runHintMenu();
		
		// run game play menu:
        void        runGameMenu(int*, int, std::queue <int>);

		// run if monkey unlocks room:
		void		runSuccessMenu(std::string);
};
#endif