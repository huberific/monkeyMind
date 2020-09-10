/*******************************************************************************
** Program Name: Final Project - Monkey Mind
** Author:       Aaron Huber
** Date:         12-10-2019
*******************************************************************************/

#include "ValidateNum.hpp"

/*******************************************************************************
** Function:     ValidateNumChoice
** Description:  The first parameter is the input string, the next is the 
** 				 minimum number allowed, followed by the maximum permitted. The 
**				 last parameter is the pointer to the choiceInt variable where 
**				 it is revised with valid entries. Note: the validateNumChoice 
**				 function returns a boolean value.
*******************************************************************************/
bool validateNumChoice(std::string choiceStr, int minChoice, int maxChoice, 
					   int* choiceIntPtr)
{
	int  numDigitsMin  = 0;		 // number of digits of minChoice
	int  numDigitsMax  = 0;		 // number of digits of maxChoice
	int  maxLength     = 0;		 
	int  choiceInt     = 0;	     // user's input string converted to integer
	bool validInput    = true;	 // holds whether input is valid or not
	bool negative      = false;  // holds whether input is negative or not
	std::string newNum = "\0";   // holds num w/o '-' for neg numbers

	int stringLength = choiceStr.length();

	numDigitsMin = std::to_string(minChoice).length();
	numDigitsMax = std::to_string(maxChoice).length();

	if (numDigitsMin > numDigitsMax)
		maxLength = numDigitsMin;
	else
		maxLength = numDigitsMax;

	// Invalid input condition: input string is too short or too long
	if (!(stringLength > 0 && stringLength <= maxLength))
		validInput = false;

	// Invalid input condition: non-digit character entered in input string
	for (int count = 0; count < stringLength; count++)
	{
		if ((count == 0) && (minChoice < 0) && (choiceStr[0] == '-'))
		{
			negative = true;				  // set to true if negative
		}
		else if (!isdigit(choiceStr[count]))  // checks for nondigits
		{
			validInput = false;
		}
		else
		{
			newNum += choiceStr[count];       // used to skip '-' if neg #
		}
	}
	
	if (validInput)
	{
		choiceInt = std::stoi(newNum);

		if (negative)						// converts to negative number
		{
			choiceInt = (-1) * choiceInt;
		}

		// Invalid input condition: must fall between minChoice-maxChoice passed
		if (!(choiceInt >= minChoice && choiceInt <= maxChoice))
		{
			*choiceIntPtr = 0;	// reset choiceInt to 0
			validInput    = false;
		}
		else
		{
			*choiceIntPtr = choiceInt;
			validInput    = true;
		}
	}
	return validInput;
}

/*******************************************************************************
** Function:    numValidateArray
** Description: Function receives user input as string. It checks that it is 2
**				characters long. It checks that there are only digits present.
**				It checks that the number is contained within the array of
**				of acceptable values. It checks if the number has already been 
**				guessed successfully. It converts the string to a number and
**				saves it to the choice memory address and returns true if these
**				conditions are met.
*******************************************************************************/
bool validateNumArray(std::string choiceStr, int* arrayValues, int numAllCards,
					  std::queue <int> numGuessed, int* choiceIntPtr)
{
	int  choiceInt  = 0;	     // user's input string converted to integer
	bool validInput = true;	 	 // holds whether input is valid or not
	bool match		= false;	 // holds whether choice is within array or not

	int stringLength = choiceStr.length();

	// Invalid input condition: input string isn't two digits
	if (stringLength != 2)
		validInput = false;

	// Invalid input condition: non-digit character entered in input string
	for (int count = 0; count < stringLength; count++)
	{
		if (!isdigit(choiceStr[count]))  // checks for nondigits
		{
			validInput = false;
		}
	}
	
	if (validInput)
	{
		choiceInt = std::stoi(choiceStr);	// convert to integer

		// Invalid input condition: must be within array passed
		for (int i = 0; i < numAllCards; i++)
		{
			if (choiceInt == arrayValues[i])
			{
				match = true;
				*choiceIntPtr = choiceInt;
			}
		}

		// check if number has already been correctly guessed - invalid entry:
		while(!numGuessed.empty())
		{
			int temp = numGuessed.front();
			numGuessed.pop();
			
			if (choiceInt == temp)
				match = false;
		}

		if (!match)
		{
			validInput = false; // user entry incorrect (already guessed)
			*choiceIntPtr = 0;	// reset choiceInt to 0
		}
	}

	return validInput;
}