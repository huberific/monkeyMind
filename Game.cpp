/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the impelementation file for the Game class. This class
**				 controls the game flow.
*******************************************************************************/

#include "Game.hpp"

/*******************************************************************************
** Function:    Game
** Description: This is the constructor.
*******************************************************************************/
Game::Game()
{
	keyBag[0] 		= "Room 1"; 
	keyBag[1] 		= "empty";  
	keyBag[2] 		= "empty";
	keyBag[3] 		= "empty";
	keyBag[4] 		= "empty";
	gameWon			= false;
	outOfTime		= false;
	timeElapse		= 0;
	currentRoomNum  = 0;
	currentRoom 	= &mainRoom;		// note: monkey always returns to
	mainRoom.next   = &room1;			// 		 main room after visiting
	room1.next 	 	= &room2;			//       another room
	room1.prev 	 	= &mainRoom;
	room2.next 	 	= &room3;
	room2.prev 	 	= &mainRoom;
	room3.next 	 	= &room4;
	room3.prev 	 	= &mainRoom;
	room4.next 	 	= &bananaRoom;
	room4.prev 	 	= &mainRoom;
	bananaRoom.next = &mainRoom;
	bananaRoom.prev = &mainRoom;
}

/*******************************************************************************
** Function:    printWelcomePage
** Description: This function prints a warning to enter full screen and then
**				prints the welcome page info.
*******************************************************************************/
void Game::printWelcomePage()
{
	std::system("clear");

	std::cout << "This game is best viewed in fullscreen mode.\n"
			  << "Please enter fullscreen mode now.\n"
			  << "Press [enter] to continue: ";
	
	std::cin.ignore();

	std::system("clear");

	std::cout << "\033[1;33m"

	<< "##     ##  #######  ##    ## ##    ## ######## ##    ##    ##     ##"
	<< " #### ##    ## ########  \n"
	<< "###   ### ##     ## ###   ## ##   ##  ##        ##  ##     ###   ###"
	<< "  ##  ###   ## ##     ## \n"
	<< "#### #### ##     ## ####  ## ##  ##   ##         ####      #### ####"
	<< "  ##  ####  ## ##     ## \n"
	<< "## ### ## ##     ## ## ## ## #####    ######      ##       ## ### ##"
	<< "  ##  ## ## ## ##     ## \n"
	<< "##     ## ##     ## ##  #### ##  ##   ##          ##       ##     ##"
	<< "  ##  ##  #### ##     ## \n"
	<< "##     ## ##     ## ##   ### ##   ##  ##          ##       ##     ##"
	<< "  ##  ##   ### ##     ## \n"
	<< "##     ##  #######  ##    ## ##    ## ########    ##       ##     ##"
	<< " #### ##    ## ########\n\n"

	<< "\033[0m";

	// ref: https://www.asciiart.eu/animals/monkeys

	std::cout

	<< "\t\t\t   	          ',                     \n"
	<< "\t\t\t               .-`-,\"__              \n"
	<< "\t\t\t                 .""`   `,            \n"
	<< "\t\t\t               .'_.  ._  `;.          \n"
	<< "\t\t\t           __ / `      `  `.\" .--.   \n"
	<< "\t\t\t          /--,| 0)   0)     )`_.-,)   \n"
	<< "\t\t\t         |    ;.-----.__ _-');   /    \n"
	<< "\t\t\t          '--./         `.`/  `""`    \n"
	<< "\t\t\t             :""   '`      |.         \n"
	<< "\t\t\t             |          //            \n"
	<< "\t\t\t              \" -----  /'            \n"
	<< "\t\t\t               `------' \"            \n"
	<< "\t\t\t               _/       `--...        \n\n\n";

	std::cout << "\033[33m";

	std::cout << "\t\t\t\t   Created by:\tAaron Huber\n";
	std::cout << "\t\t\t\t   Date:\t12/10/2019\n\n\n";

	std::cout << "\033[0m";
}

/*******************************************************************************
** Function:    printInstructions
** Description: This function prints the instructions of the game.
*******************************************************************************/
void Game::printInstructions()
{
	std::system("clear");

	std::cout << "Meet Henry.\n\n";

	std::cout << "Hi my name is Henry, but the scientists call "
			  << "me Monkey517. Each day, they task me to unlock\nrooms "
			  << "which contain memory puzzles. In order to unlock the "
			  << "next room, I must remember which\ncards have red dots "
			  << "after briefly shown their positions. I "
			  << "have 90 seconds to pass the tests\nin all 4 rooms. If I "
			  << "fail a test in a room, I have to exit and try again. "
			  << "If I don’t pass\nall 4 tests in time, I have to wait "
			  << "till tomorrow to try again. If I succeed though, I "
			  << "unlock\nmy favorite room, the Banana Room!\n\n"

			  << "I need your help. Please help me pass the tests and "
			  << "get a banana!\n\n\n";

	// ref: https://www.asciiart.eu/animals/monkeys

	std::cout

	<< "\t\t\t   	          ',                     \n"
	<< "\t\t\t               .-`-,\"__              \n"
	<< "\t\t\t                 .""`   `,            \n"
	<< "\t\t\t               .'_.  ._  `;.          \n"
	<< "\t\t\t           __ / `      `  `.\" .--.   \n"
	<< "\t\t\t          /--,| 0)   0)     )`_.-,)   \n"
	<< "\t\t\t         |    ;.-----.__ _-');   /    \n"
	<< "\t\t\t          '--./         `.`/  `""`    \n"
	<< "\t\t\t             :""   '`      |.         \n"
	<< "\t\t\t             |          //            \n"
	<< "\t\t\t              \" -----  /'            \n"
	<< "\t\t\t               `------' \"            \n"
	<< "\t\t\t               _/       `--...        \n\n\n";

	std::cout << "Press [enter] to start the game and 90-sec timer: ";
	std::cin.ignore();

}

/*******************************************************************************
** Function:    reload
** Description: This function reloads the linked rooms using the derived class
**				Space pointers.
*******************************************************************************/
void Game::reload()
{	
	keyBag[0] 		= "Room 1"; 
	keyBag[1] 		= "empty";  
	keyBag[2] 		= "empty";
	keyBag[3] 		= "empty";
	keyBag[4] 		= "empty";
	gameWon			= false;
	outOfTime		= false;			// reset for clock purposes
	currentRoomNum  = 0;
	timeElapse		= 0;				// reset for clock purposes
	currentRoom 	= &mainRoom;		// note: monkey always returns to
	mainRoom.next   = &room1;			// 		 main room after visiting
	room1.next 	 	= &room2;			//       another room
	room1.prev 	 	= &mainRoom;
	room2.next 	 	= &room3;
	room2.prev 	 	= &mainRoom;
	room3.next 	 	= &room4;
	room3.prev 	 	= &mainRoom;
	room4.next 	 	= &bananaRoom;
	room4.prev 	 	= &mainRoom;
	bananaRoom.next = &mainRoom;
	bananaRoom.prev = &mainRoom;
	room1.reload();
	room2.reload();
	room3.reload();
	room4.reload();
}

/*******************************************************************************
** Function:    printLosePage
** Description: Prints if the user loses the game.
*******************************************************************************/
void Game::printLosePage()
{
	system ("clear");
	std::cout << "Oops! You ran out of time! Henry didn't get "
				<< "his banana.\n";
	std::cout << R"(
		         .-"-.
		       _/.-.-.\_
		      ( ( o o ) )
		       |/  "  \|
		        \ .-. /
		        /`"""`\
		       /       \
					)" << '\n';
	std::cout << std::endl;
}

/*******************************************************************************
** Function:    run
** Description: This function controls the entire program flow.
*******************************************************************************/
void Game::run()
{
	printWelcomePage();
	menu.runMain();

	if (menu.getChoiceInt() == 1)
	{
		printInstructions();

		// loop until Banana Room is unlocked
		while (!gameWon && menu.getChoiceInt() != 2
			   && !outOfTime)
		{
			auto start = high_resolution_clock::now();	// clock time
			currentRoom->run(keyBag, timeElapse);		
			menu.runMainRoomMenu(currentRoom->next->getName());
			auto stop = high_resolution_clock::now();	// clock time
			auto duration = duration_cast<seconds>(stop - start); // calc time
			timeElapse += duration.count();		// add time to elapse time var

			if (menu.getChoiceInt() == 1)
			{
				currentRoom->reload();		// reload mainRoom delete dyn mem

				currentRoom = currentRoom->next;

				currentRoomNum = currentRoom->getRoomNum();

				if (currentRoomNum == 5 && !(timeElapse >= 90))
					gameWon = true;

				if (timeElapse < 90)
					currentRoom->run(keyBag, timeElapse);
				else
					outOfTime = true;					

				// get time while space was running
				timeElapse += currentRoom->getTimeElapse();

				if (timeElapse >= 90)
					outOfTime = true;

				if (!gameWon && !outOfTime)
				{
					// if all hidden objects found, update key bag info
					if (currentRoom->getNumHidden() != 0)
					{
						auto start = high_resolution_clock::now();
						menu.runFailMenu(currentRoom->getName());
						auto stop = high_resolution_clock::now();
						auto duration = duration_cast<seconds>(stop - start);
						timeElapse += duration.count();

						currentRoom->reload();
						currentRoom->prev->next = currentRoom;
						currentRoom = currentRoom->prev;
					}

					else
					{
						keyBag[currentRoomNum] = currentRoom->next->getName();
						currentRoomNum++;

						if (currentRoomNum == 5 && timeElapse < 90)
							{timeElapse = -999;}	// ensures time doesnt run

						auto start = high_resolution_clock::now();		
						menu.runSuccessMenu(currentRoom->next->getName());
						auto stop = high_resolution_clock::now();
						auto duration = duration_cast<seconds>(stop - start);
						timeElapse += duration.count();

						currentRoom->reload();
						currentRoom->prev->next = currentRoom->next;
						currentRoom = currentRoom->prev;
					}
				}

				if (gameWon && !outOfTime)
				{
					menu.runPlayAgain();

					if (menu.getChoiceInt() == 1)
					{
						reload();
					}
				}

				if (timeElapse >= 90)
					outOfTime = true;
			}

			if (outOfTime)
			{
				printLosePage();

				menu.runPlayAgain();

				if (menu.getChoiceInt() == 1)
				{
					reload();
				}
			}
		}
	}
}