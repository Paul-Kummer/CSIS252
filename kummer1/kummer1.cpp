// File: kummer1.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: assignment 1
// Date: 8/29/20

#include <iostream>
#include <iomanip>

using namespace std;

// This program will convert cubic cubits to pints or vice versa
// Conversion Info
// 1 cubic cubit to pint [US, liquid] = 304.3262 pint [US, liquid]

int main()
{
	// variables
	bool continueConversion = true;
	float pint;
	float cubicCubit;
	int usrInput;

	// main loop
	while (continueConversion)
	{
		// conversion options
		cout << "Select an Option:" << endl
			<< "(1) cubic Cubit to Pint" << endl
			<< "(2) Pint to cubic Cubit" << endl
			<< "Enter 1 or 2 to select that option" << endl;
		cin >> usrInput;

		// Verify valid option is entered, does not verify integer.
		while (usrInput != 1 && usrInput != 2)
		{
			cout << "Invalid Option: Enter 1 or 2, [ (1) cubit to pint, (2) pint to cubit ]" << endl;
			cin >> usrInput;
		}

		if (usrInput == 1) // User wants to convert cubit to pint
		{
			cout << "[ cubic cubit to pint selected ] " << endl
				<< "Enter the number of cubic cubits: " << endl;
			cin >> cubicCubit;

			// convert cubicCubit to pint
			pint = cubicCubit*(float)304.3262;

			cout << fixed << showpoint << setprecision(2);
			cout << cubicCubit << " cubic Cubits equals " << pint << " Pints" << endl;
		}

		else // User wants to convert pint to cubit
		{
			cout << "[ pint to cubic cubit selected ]" << endl
				<< "Enter the number of pints: " << endl;
			cin >> pint;

			// convert pint to cubicCubit
			cubicCubit = pint/(float)304.3262;

			cout << fixed << showpoint << setprecision(2);
			cout << pint << " Pints equals " << cubicCubit << " cubic Cubits" << endl;
		}
		
		// ask if user wants to continue
		cout << "do another conversion (0) no / (any integer) yes?" << endl;
		cin >> usrInput;

		// exit on zero otherwise default value is to continue
		if(usrInput == 0)
		{
			continueConversion = false;
		}
	}	
   return 0;
}