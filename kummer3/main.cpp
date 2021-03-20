// File: main.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog3
// Modified: 9/30/20

#include <iostream>
#include <iomanip>
#include "constants.h"
#include "prototypes.h" //<string> is included in prototypes.h

using namespace std;

/* 
run the programs main line of logic.


Precondtiton:
There must be at least two command line arguments including the command to run the program.

The second argument must be a valid text file.

The user must supply input to the program to compare units, or nothing to exit.

Postcondition:
Program closes and displays error if a 2nd command line argument isn't provided.

Units compatibility is displayed to user.

Program exits when no input is provided.
*/

int main(int argc, char *argv[])
{
	// variables
	bool promptUser = true;
	string usrInputOne, usrInputTwo, fileName;
	string unitArray [arraySize];
	string unitTypeArray [arraySize];

	// check for command line argument
	if (argc < 2)
	{
		cerr << "!!! No file selected as command line argument !!!" << endl << "-EXITING-" << endl;
		promptUser = false;
	}

	else
	{
		// get name from command argument
		fileName = argv[1];

		// fill parellel arrays
		PopulateArraysFromFile(unitArray, unitTypeArray, fileName);
		
		// display info to the user about the program
		cout << "************************************************************" << endl;
		cout << endl << "Programmed By: Paul Kummer" << endl << endl;
		cout << "This program will inform you if two user entered measurments" << endl 
			<< "are able to be converted to one another" << endl << endl;
		cout << "************************************************************" << endl << endl;
		// display all available units
		PrintUnits(unitArray);
		
		// main loop
		while (promptUser)
		{
			// ask user for unit inputs
			cout << "Select Two Units to Check Coversion Compatibility (enter nothing to exit)" << endl << "Enter First Unit: ";
			getline(cin, usrInputOne);

			if (usrInputOne.length() != 0) // check if the user wants to quit otherwise goto second prompt
			{
				cout << "Enter Second Unit: ";
				getline(cin, usrInputTwo);

				if (usrInputTwo.length() == 0) // check if the user wants to quit otherwise check unit compatibility
				{
					cout << endl << right << setw(10) << "--Exiting--" << endl;
					promptUser = false;
				}

				else
				{
					if(UnitCompatible(unitArray, unitTypeArray, usrInputOne, usrInputTwo)) // true if the unit types match
					{
						cout << endl << right << setw (20) << usrInputOne << " IS compatible with " << left << setw (20) << usrInputTwo << endl << endl;
					}

					else
					{
						cout << endl << right << setw (20) << usrInputOne << " IS NOT compatible with " << left << setw (20) << usrInputTwo << endl << endl;
					}			
				}		
			}

			// user entered nothing at prompt and triggers program exit
			else
			{
				cout << endl << right << setw(10) << "--Exiting--" << endl;
				promptUser = false;
			}		
		}	
	}

   return 0;
}