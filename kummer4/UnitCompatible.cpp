// File: UnitCompatible.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog4
// Modified: 10/12/20

#include <string>
#include "constants.h"
#include "structs.h"

using namespace std;

/* 
loop through all items in  struct array. when user string matches an element in the array its unit type will be assigned.
if either element isn't in the array, false will be returned.


Precondtiton:
struct array is passed as the first argument

Two strings of user inputted data must be the last two arguments.

Postcondition:
If two user inputted units are in the unit array and have the same unit type, bool true is returned.
If either of the two user inputs are not in the unit array, bool false is returned.
If two user inputted units are in the unit array and have different unit type, bool false is returned.
*/
bool UnitCompatible(unitMeasurement unitArray[], string unitOne, string unitTwo)
{
	int currentIndex = 0;
	string unitOneType, unitTwoType; // become the unit types if the values are found in the struct array
	bool foundOne = false, foundTwo = false; // flags to trigger an early exit of the loop when values are found

	while (currentIndex < arraySize && !(foundOne && foundTwo)) // go through entire index looking for units, but stop if both are found
	{
		if (unitArray[currentIndex].name == unitOne)
		{
			// assign unit type to the first user inputted element, which is matched in the array
			unitOneType = unitArray[currentIndex].type;
			foundOne = true;
		}

		if (unitArray[currentIndex].name == unitTwo)
		{
			// assign unit type to the second user inputted element, which is matched in the array
			unitTwoType = unitArray[currentIndex].type;
			foundTwo = true;
		}

		currentIndex++;
	}

	// user inputted strings are not found in the array, and default to incompatible
	if (!foundOne || !foundTwo)
	{
		return false;
	}

	// user inputted strings have matching unit types and are compatible
	else if (unitOneType == unitTwoType)
	{
		return true;
	}

	// user inputted strings do NOT have matching unit types and are not compatible
	else
	{
		return false;
	}
}