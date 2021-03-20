// File: check2.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: assignment 2
// Date: 9/25/20

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int arraySize = 50; // could make variable by reading lines of file first

// prototypes
void PopulateArraysFromFile(string unitArray[], string unitTypeArray[], string fileName);
bool UnitCompatible(string unitArray[], string unityTypeArray[], string unitOne, string unitTwo);
void PrintUnits(string units[]);

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

/*
Open the file supplied from the command line argument and add the comma seperated elements to their
corresponding array. The first string before the comma goes into unitArray and the items after the
comma go into unitTypeArray. Then the file is closed.
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

/* 
loop through all items in array. when user string matches an element in the array its unit type will be assigned.
if either element isn't in the array, false will be returned.
*/
bool UnitCompatible(string unitArray[], string unitTypeArray[], string unitOne, string unitTwo)
{
	int currentIndex = 0;
	string unitOneType, unitTwoType;

	while (currentIndex < arraySize)
	{
		if (unitArray[currentIndex] == unitOne)
		{
			// assign unit type to the first user inputted element, which is matched in the array
			unitOneType = unitTypeArray[currentIndex];
		}

		if (unitArray[currentIndex] == unitTwo)
		{
			// assign unit type to the second user inputted element, which is matched in the array
			unitTwoType = unitTypeArray[currentIndex];
		}

		currentIndex++;
	}

	// user inputted strings are not found in the array, and default to incompatible
	if (unitOneType.length() == 0 || unitTwoType.length() == 0)
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

/*
display to the user all the elements retrieved from the text file so that
they will know what units they can compare.
*/
void PrintUnits(string units[])
{
	cout << right << setw(50) << "[ AVAILABLE UNITS ]" << endl;
	for (int i = 1; i < arraySize + 1; i++) // have to start i at one to keep formatting correct for the first element
	{
		// goto newline on the fifth element
		if (i % 5 == 0 && units[i-1].length() != 0) // have to reduce i by one to prevent going out of range
		{
			cout << setw(15) << units[i] << endl;
		}

		// add seperator between elements that are not the fifth element
		else if (units[i-1].length() != 0)
		{
			cout << setw(15) << units[i] << " | ";
		}
	}
	cout << endl << endl;
}