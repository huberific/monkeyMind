/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
** Description:  This is the specification file for the Space class. It is
**				 an abstract base class and therefore no Space objects may
**				 be instantiated.
*******************************************************************************/

#include <iostream>
#include <queue>			// used for queue containers holding hidden items
#include <cstdlib>			// used for random number generation
#include <ctime>			// used to ensure random number generated
#include <thread>			// used for pausing screen
#include <chrono>			// used for pausing screen
#include "Menu.hpp"
using namespace std::this_thread;		// needed for time functions
using namespace std::chrono;			// needed for time functions

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:
		Menu menu;			// menu object for running menu functions
		int roomNum;		// holds room number
		std::string name;	// holds name of room
		char** table;		// ptr to array of ptrs to hold 2D array of chars
		int numCards;		// holds number number of cards per row and col
		int numAllCards;	// holds number of all cards
		int numGuesses;		// holds number of guesses permitted within room
		unsigned int numHidden;		// holds number of hidden dots
		int hintTime;		// holds time alotted for hint view
		int rowDiv;			// holds num of divisions of table for layout
		int colDiv;			// holds num of divisions of table for layout
		int* numPermitted;	// holds numbers of possible guesses
		int timeElapse;		// holds number of seconds of elapsed time
		std::queue <int> hiddenItems; // holds hidden item locations e.g. 11
		std::queue <int> correctGuesses; // holds correct guesses e.g. 11
		static const int tableRows = 42; // constructs room array
		static const int tableCols = 96; // constructs room array

	public:
		Space();			// default constructor
		virtual ~Space();	// virtual destructor
		virtual void printRoomInfo() = 0; // pure virtual function
		Space* next;		// used to link Space derived class objects
		Space* prev;		// used to link Space derived class objects
		Space* up;			// unused Space pointer
		Space* down;		// unused Space pointer
		virtual void reload() = 0;		  // pure virtual function
		virtual void newTable();	// creates new table with dims above

		// function to place hidden items in their positions:
		virtual void buildHintTable(std::queue <int>);

		virtual void buildTable();  // place characters in table
		virtual void buildCardTable(); // place numbers on cards
		virtual int  randomItemNum();  // function returns random #
		virtual void createHiddenItems(); // creates hidden Item #s
		virtual void updateTable(int); // updates table after user guess
		virtual void printTable(); // prints room table
		static  void printKeyBag(std::string*); // prints unlocked rooms
		virtual void run(std::string*, int);	// runs gameplay for room
		virtual void printTimeRem(int);	// prints time remaining
		virtual int  getHintTime() 		{return this->hintTime;};
		virtual int  getNumHidden() 	{return this->hiddenItems.size();};
		virtual int* getNumPermitted() 	{return this->numPermitted;};
		virtual int  getNumGuesses()	{return this->numGuesses;};
		virtual int  getRoomNum()		{return this->roomNum;};
		virtual std::string getName()	{ return this->name;};
		virtual int  getTimeElapse()	{ return this->timeElapse;};

		virtual std::queue <int> getCorrectGuesses() 
										{return this->correctGuesses;};
};
#endif