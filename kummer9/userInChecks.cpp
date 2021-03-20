// File: userInChecks.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog9
// Modified: 11/17/20

#include <iostream>
#include <string>
#include <cmath>
#include "prototypes.h"

/*
Description:
Two functions used by the extraction operator for routes are defined. These functions will ensure that routes are
entered and parsed correctly so that the objects have the most correct values based upon what the user inputs.
*/

// takes in a reference to a string array and a string to parse as input into that array
void splitStrByNum(std::string* tmpArr, std::string strToSplit)
{
	// variables
	std::string rtName = ""; // blank string to be concatendated to
	std::string rtClass = "5"; // route class, class 5 is set to default because that is the level of technical climbing
	int strLength = strToSplit.length();

	// ensures that the user input is of some value
	if(strLength > 0)
	{
		// go through the user inputted string and concatenate characters to make a route name. Stop at just before the
		// the last index, which should be the class of the routes. This could be a bug if the user doesn't enter a route
		// class value
		for(int indexNum=0; indexNum < strLength-1; indexNum++)
		{
			rtName += (char)strToSplit[indexNum];
		}

		// if no route name is entered an only a route class and grade is entred instead, the first char will be the class
		// iff the first char is between 1 and 5
		if (strToSplit[0] >= '1' && strToSplit[0] <= '5')
		{
			rtClass = (char)strToSplit[0];
		}
	}

	// the user input nothing and defaults the name to "Void"
	else
	{
		rtName = "Void";
	};

	// get the last index of the user entered string and use it as the class of the route iff the value is between 1 and 5; and the
	// string lenght is greater than 1
	if (strLength > 1 && strToSplit[strLength-1] >= '1' && strToSplit[strLength-1] <= '5')
	{
		rtClass = (char)strToSplit[strLength-1];
	};
	
	// assign the values to the string array in the extraction operator of the route 
	tmpArr[0] = rtName;
	tmpArr[1] = rtClass;
};

// takes in a string, which is checked to ensure it is withing a valid range of routes between 0 and 19, currently nothing above 15 exists
int checkGrade(std::string userNum)
{
	int intToReturn;

	// check that route grade is within range
	for(int i = 0; i < userNum.length(); i++)
	{
		// checks if the number is double digits, anything over two digits is ignored
		if(userNum.length() > 1)
		{
			if ((int)userNum[0] == 49 && //the string is over two chars long, and the first char must be a 1 to be a valid climbing route
				((int)userNum[1] >= 48 && (int)userNum[1] <= 57)) //the second character must be between 0-9, even though anything above 5 doesn't exist yet
			{
				intToReturn = (std::stoi(userNum));
			}
		}

		// the number is single digit
		else
		{
			if ((int)userNum[0] >= 48 && (int)userNum[0] <= 57) //check if value is between 0-9
			{
				intToReturn = (std::stoi(userNum));
			}

			// default values
			else
			{
				intToReturn = 0; //the grade didn't pass any of the checks
			}
		}
	}

	return intToReturn;
};