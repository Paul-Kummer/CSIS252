// File: PopulateArraysFromFile.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog4
// Modified: 10/12/20

#include <fstream>
#include <string>
#include "structs.h"

using namespace std;

/*
Open the file supplied from the command line argument and add the comma seperated elements to a
struct array.


Precondition:
unitMeasurment array must be past as first argument

Second argument must be a text file and must have a unit of measurement followed by a comma; Then 
the unit type is after the comma. No commas can exist per line until after the unit of measurment 
has been declared, and there can be no commas in the unit of measurment.

There cannot exceed 79 units unless the arraysize is changed.

Postcondition:
unitMeasurment array will have it's values name and type populated.
*/

void PopulateArraysFromFile(unitMeasurement unitArray[], string fileName) // arrays are passed by reference
{
	int indexLocation = 0;
	ifstream unitFile;
	unitFile.open(fileName);

	// loop until all 79 lines have been read
	while(!unitFile.eof())
	{		
		// get the first string before the comma in the file from argument 1 and assign value to name in struct
		getline(unitFile, unitArray[indexLocation].name, ',');
		// get the second string after the comma in the file from argument 1 and assign value to type in struct
		getline(unitFile, unitArray[indexLocation].type);
		++indexLocation;
	}
	unitFile.close();
}