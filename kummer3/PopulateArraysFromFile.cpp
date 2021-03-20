// File: PopulateArraysFromFile.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog3
// Modified: 9/30/20

#include <fstream>
#include <string>

using namespace std;

/*
Open the file supplied from the command line argument and add the comma seperated elements to their
corresponding array. The first string before the comma goes into unitArray and the items after the
comma go into unitTypeArray. Then the file is closed.


Precondition:
Two string arrays must be passed into fuction as first to arguments

Third argument must be a text file and must have a unit of measurement followed by a comma; Then 
the unit type is after the comma. No commas can exist per line until after the unit of measurment 
has been declared, and there can be no commas in the unit of measurment.

There cannot exceed 50 units unless the arraysize is changed.

Postcondition:
Two parallel arrays of strings are created. One as units of measurements and the other is the unit type.
*/
void PopulateArraysFromFile(string unitArray[], string unitTypeArray[], string fileName) // arrays are passed by reference
{
	int indexLocation = 0;
	ifstream unitFile;
	string stringFromFile;
	unitFile.open(fileName);

	while(!unitFile.eof())
	{		
		// get the first string before the comma in the file from argument 1 and put into unitArray
		getline(unitFile, stringFromFile, ',');
		unitArray[indexLocation] = stringFromFile;
		// get the second string after the comma in the file from argument 1 and put into unitArrayType
		getline(unitFile, stringFromFile);
		unitTypeArray[indexLocation] = stringFromFile;
		++indexLocation;
	}
	unitFile.close();
}