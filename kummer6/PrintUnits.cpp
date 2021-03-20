// File: PrintUnits.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog6
// Modified: 10/24/20

#include <string>
#include <iomanip>
#include <iostream>
#include "constants.h"
#include "Measurment.h"

using namespace std;

/*
display to the user all the elements retrieved from the text file so that
they will know what units they can compare.


Preconditons:
Measurment array passed as argument

Postcondtions:
text outputted to screen, showing available units from text file
*/
void PrintUnits(Measurment units[])
{
	cout << right << setw(60) << "[ AVAILABLE UNITS ]" << endl;
	for (int i = 0; i < arraySize; i++) // have to start i at one to keep formatting correct for the first element
	{
		// goto newline on the fifth element
		if ((i+1) % 5 == 0 && (units[i].getName()).length() != 0)
		{
			cout << setw(20) << units[i].getName() << endl;
		}

		// add seperator between elements that are not the fifth element
		else if ((units[i].getName()).length() != 0)
		{
			cout << setw(20) << units[i].getName() << " | ";
		}
	}

	cout << endl << endl;
}