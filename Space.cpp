/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the implementation file for the Space class. It is
**				 an abstract base class and therefore no Space objects may
**				 be instantiated.
*******************************************************************************/
#include "Space.hpp"

/*******************************************************************************
** Function:    Space
** Description: This is the constructor.
*******************************************************************************/
Space::Space()
{
	roomNum = 0;
	name = "TBD";
	table = nullptr;
	timeElapse = 0;
	numCards = 0;
	numAllCards = 0;
	numGuesses = 0;
	numHidden = 0;
	hintTime = 0;
	rowDiv = 0;
	colDiv = 0;
	numPermitted = nullptr;
	next = nullptr;
	prev = nullptr;
	up = nullptr;
	down = nullptr;
}

/*******************************************************************************
** Function:    Space
** Description: This is the destructor. It deletes any dyn all memory.
*******************************************************************************/
// delete dynamically allocated multidemnsional array of pointers
// ref: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
Space::~Space()
{
	if (this->table != nullptr)
	{
		for (int count = 0; count < tableRows; ++count)
			delete[] this->table[count];
		delete[] this->table;
	}

	if (this->numPermitted != nullptr)
		delete[] this->numPermitted;
}

/*******************************************************************************
** Function:    buildTable
** Description: This function determines the numbers that a user can guess
**				based on the number of cards. It also assigns characters for
**				the table border and card borders. The function uses variables
**				to allow different number of cards to be used for various
**				rooms.
*******************************************************************************/
void Space::buildTable()
{
	// variables used divide board evenly for 2D array layout:
	this->rowDiv = tableRows / (this->numCards + 1);
	this->colDiv = tableCols / (this->numCards + 1);

	// create array that holds numbers that can be guessed by user:
	int index = 0;
	
	this->numPermitted = new int [this->numAllCards];
	for (int i = 0; i < this->numCards; i++)
	{
		for (int j = 0; j < this->numCards; j++)
			{
				this->numPermitted[index++] = (i + 1) * 10 + (j + 1);
			}
	}

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
		for (int n = 1; n < (numCards + 1); n++)
		{
			// assign top and bottom of card:
			for (int i = -3; i < 4; i++)
			{
				this->table[n * this->rowDiv - 2][m * this->colDiv + i] = '-';
				this->table[n * this->rowDiv + 2][m * this->colDiv + i] = '-';
			}

			// assign sides of card:
			for (int i = -1; i < 2; i++)
			{
				this->table[n * this->rowDiv + i][m * this->colDiv - 3] = '|';
				this->table[n * this->rowDiv + i][m * this->colDiv + 3] = '|';
			}
		}
	}
}

/*******************************************************************************
** Function:    buildHintTable
** Description: This function accepts a queue of ints which contain the hidden
**				numbers, e.g. 11, that a user needs to guess. A copy of the
**				queue is used so as not to interfere with the class member. A
**				# character is placed in the locations of the hidden items.
*******************************************************************************/
void Space::buildHintTable(std::queue <int> hiddenItems)
{
	while(!hiddenItems.empty())
	{
		int temp = hiddenItems.front();
		int n = temp / 10;			// gives row of hidden item location
		int m = temp % 10;			// gives col of hidden item location
		hiddenItems.pop();

		// assign # indicator on cards:
		this->table[n * this->rowDiv][m * this->colDiv] = '#';
	}
}

/*******************************************************************************
** Function:    newTable
** Description: This function dynamically creates a new array when called for
**				printing a new table.
*******************************************************************************/
// ref: https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
void Space::newTable()
{
	this->table = new char*[tableRows];
	for (int count = 0; count < tableRows; ++count)
		table[count] = new char[tableCols];
}

/*******************************************************************************
** Function:    buildCardTable
** Description: This function assigns the card numbers in their positions.
*******************************************************************************/
void Space::buildCardTable()
{
	// assigns all card properties (including numbers):
	for (int m = 1; m < (numCards + 1); m++)
	{
		for (int n = 1; n < (numCards + 1); n++)
		{
			char rowChar = '0' + n;		// converts n to char
			char colChar = '0' + m;		// converts m to char

			// assign numbers on cards:
			this->table[n * this->rowDiv][m * this->colDiv - 1] = rowChar;
			this->table[n * this->rowDiv][m * this->colDiv] = 32;  // blank
			this->table[n * this->rowDiv][m * this->colDiv + 1] = colChar;
		}
	}
}

/*******************************************************************************
** Function:    updateTable
** Description: This function recieves the user's input, checks if is one of 
**				the hidden items. If it is, the hidden item is removed from
**				the queue and the space is assigned #. If it is not, the space
**				is assigned blank.
*******************************************************************************/
void Space::updateTable(int input)
{
	int n = input / 10;			// gives row of input item location
	int m = input % 10;			// gives col of input item location

	std::queue <int> tempQueue = this->hiddenItems;
	bool match = false;

	// cycle through each hidden item to see if input matches one:
	while (!tempQueue.empty() && !match)
	{
		int temp = tempQueue.front(); // get front of the queue
		tempQueue.pop();	// remove front of the queue
		
		if (temp == input)
		{
			match = true;
		}
	}

	// if there is a match, remove it from hidden items list:
	if (match)
	{
		while (match)
		{
			int temp = this->hiddenItems.front();

			if (temp == input)
			{
				this->hiddenItems.pop();
				this->correctGuesses.push(temp);
				match = false;				// change match to F to exit loop
			}
			else
			{
				this->hiddenItems.push(temp);
				this->hiddenItems.pop();
			}
		}

		// assign # indicator on cards:
		this->table[n * this->rowDiv][m * this->colDiv - 1] = 32;
		this->table[n * this->rowDiv][m * this->colDiv] = '#';
		this->table[n * this->rowDiv][m * this->colDiv + 1] = 32;

	}

	else // there isn't a match, therefore, print blank card
	{
		for (int i = -2; i < 3; i++)
			this->table[n * this->rowDiv][m * this->colDiv + i] = 32; // blank
	}
	
	this->numGuesses -= 1;	// number of guesses are decremented every "turn"
}

/*******************************************************************************
** Function:    printTable
** Description: This function prints whatever is currently assigned to the table
*******************************************************************************/
void Space::printTable()
{
	for (int i = 0; i < tableRows; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < tableCols; j++)
		{
			if (this->table[i][j] == '#')
			{
				// font color change:
				std::cout << "\033[1;31m" << this->table[i][j] << "\033[0m";
			}
			else
				std::cout << this->table[i][j];
		}

	}
	std::cout << std::endl;

	std::cout << "|\t\t\t\t    Hidden Items Remaining: "
				<< this->hiddenItems.size()
				<< "\t\t\t\t       |" << std::endl;
	std::cout << "|\t\t\t\t       Guesses Remaining: "
				<< this->numGuesses
				<< "\t\t\t\t       |" << std::endl << "+";
	
	for (int i = 0; i < 94; i++)
		std::cout << "-";
	
	std::cout << "+" << std::endl;
}

/*******************************************************************************
** Function:    randomItemNum
** Description: returns a random number from 1 to numCards which represents the
**				number of cards in each row and column.
*******************************************************************************/
int Space::randomItemNum()
{
	return rand() % this->numCards + 1;
}

/*******************************************************************************
** Function:    createHiddenItems
** Description: This function creates random numbers in the form of 11, 12, 21,
**				22, etc. It saves these numbers in the class's hiddenItems
**				queue. It has a check to make sure that there are no repeating
**				hidden items.
*******************************************************************************/
void Space::createHiddenItems()
{
	srand((unsigned) time(0)); 			// used to ensure random number

	do
	{
		// create number with random first and second digits between 1
		// and numCards:
		int num = randomItemNum() * 10 + randomItemNum();

		bool match = false;	

		if (this->hiddenItems.empty())
			this->hiddenItems.push(num);

		else
		{
			std::queue <int> tempQueue = this->hiddenItems;

			while (!tempQueue.empty())
			{
				int temp = tempQueue.front(); // get front of the queue

				tempQueue.pop();	// remove front of the queue

				// check if front of queue is equal to randomNum (repeated)
				if (temp == num)	
				{
					match = true;
				}
			}

			if (!match)
				this->hiddenItems.push(num);		
		}

	}while (this->hiddenItems.size() < this->numHidden);
}

/*******************************************************************************
** Function:    printKeyBag
** Description: This function receives the keyBag string array and prints its
**			   	contents.
*******************************************************************************/
void Space::printKeyBag(std::string* keyBag)
{
	std::cout << "\t\t    Unlocked Rooms: ";
	
	for (int i = 0; i < 5; i++)
	{
		if (keyBag[i] != "empty")
		{
			// with color change incorporated (yellow)
			std::cout << "[" << "\033[33m" << keyBag[i] << "\033[0m" << "] ";
		}
		else
			std::cout << "[" << keyBag[i] << "] ";
	}
}

/*******************************************************************************
** Function:    printTimeRem
** Description: This function receives the current elapsed time during game play
**				and calculates the time remaining from 90 seconds. It prints
**				the results. Negative numbers are set to 0.
*******************************************************************************/
void Space::printTimeRem(int timeElapse)
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
**				is clocked. The user has a brief moment of viewing the hidden
**				items, then they have as much time as they'd like to make a
**				guess, but time is ticking! The function receives the keyBag
**				string array to print which rooms are unlocked. It also receives
**				the current elapsed time of the program to update the time
**				remaining printout.
*******************************************************************************/
void Space::run(std::string* keyBag, int timeElapse)
{
	auto start = high_resolution_clock::now();	// clock the time
	std::system ("clear");
	printRoomInfo();
	printKeyBag(keyBag);
	printTimeRem(timeElapse);
	newTable();
	createHiddenItems();
	buildTable();
	buildHintTable(hiddenItems);
	printTable();
	menu.runHintMenu();
	sleep_for(seconds(this->hintTime));		// pause to show hints
	buildCardTable();

	std::system ("clear");					// update room w/ card nums
	printRoomInfo();
	printKeyBag(keyBag);
	printTimeRem(timeElapse);
	printTable();

	// loop allows table to be updated with user guesses until they get all
	// the hidden items or run out of guesses permitted
	while (this->hiddenItems.size() > 0 && this->numGuesses > 0)
	{
		menu.runGameMenu(this->numPermitted, this->numAllCards,
						 this->correctGuesses);
		updateTable(menu.getChoiceInt());
		std::system("clear");
		printRoomInfo();
		printKeyBag(keyBag);
		printTimeRem(timeElapse);
		printTable();
	}
	auto stop = high_resolution_clock::now();	// clock time again
	auto duration = duration_cast<seconds>(stop - start); // take diff in time
	this->timeElapse = duration.count(); // timeElapse is updated
}