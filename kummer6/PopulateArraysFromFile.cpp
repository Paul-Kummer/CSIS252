// File: PopulateArraysFromFile.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog6
// Modified: 10/24/20

#include <fstream>
#include <string>
#include "Measurment.h"

using namespace std;

/*
Open the file supplied from the command line argument and add the comma seperated elements to a
class array.


Precondition:
Measurement array must be past as first argument

Second argument must be a text file and must have a unit of measurement followed by a comma; Then 
the unit type is after the comma. Next the abbreviated form of the unit name followed by a comma.
Finally the value of one unit compared to the base unit. No commas can exist per line until after
the abbreviated value has been set.

There cannot exceed 74 units unless the arraysize is changed.

Postcondition:
Measurment array will be populated with unit objects.
*/

void PopulateArraysFromFile(Measurment unitArray[], string fileName) // arrays are passed by reference
{
	int indexLocation = 0;
	ifstream unitFile;
	unitFile.open(fileName);

	// loop until all 79 lines have been read
	while(!unitFile.eof())
	{
		std::string name, type, abbr, convertRatio; // should use a formula instead of ratio for accurate conversions

		// get the unit name
		getline(unitFile, name, ',');
		// get the unit type
		getline(unitFile, type, ',');
		// get the unit abbreviation
		getline(unitFile, abbr, ',');
		// get the ratio of the base unit
		getline(unitFile, convertRatio);

		unitArray[indexLocation] = Measurment(name, type, abbr, stof(convertRatio));
		++indexLocation;
	}
	unitFile.close();
}