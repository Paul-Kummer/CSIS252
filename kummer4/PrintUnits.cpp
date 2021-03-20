// File: PrintUnits.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog4
// Modified: 10/12/20

#include <string>
#include <iomanip>
#include <iostream>
#include "constants.h"
#include "structs.h"

using namespace std;

/*
display to the user all the elements retrieved from the text file so that
they will know what units they can compare.


Preconditons:
unitMeasurment array passed as argument

Postcondtions:
text outputted to screen, showing available units from text file
*/
void PrintUnits(unitMeasurement units[])
{
	cout << right << setw(50) << "[ AVAILABLE UNITS ]" << endl;
	for (int i = 0; i < arraySize; i++) // have to start i at one to keep formatting correct for the first element
	{
		// goto newline on the fifth element
		if ((i+1) % 5 == 0 && units[i].name.length() != 0) // have to reduce i by one to prevent going out of range
		{
			cout << setw(15) << units[i].name << endl;
		}

		// add seperator between elements that are not the fifth element
		else if (units[i].name.length() != 0)
		{
			cout << setw(15) << units[i].name << " | ";
		}
	}
	cout << endl << endl;
}