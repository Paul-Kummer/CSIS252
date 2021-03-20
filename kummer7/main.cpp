//File: main.cpp
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

#include "distMeasurement/distMeasurement.h"
#include "distMeasurement/feet/foot.h"
#include "distMeasurement/meters/meter.h"
#include "unitTestTemplate.cpp"
#include <string>
#include <iostream>
using namespace std;

/*
Description:
The main function will create objects with a base class of DistMeasuement and either be a Meter or Foot object.
The user may choose to create their own objects through a series of prompts, which will then run a unit test on
the newly created objects. The first object created will be the first operand in any operations, and will also
be the unit type of any returned objects. This is accomplished by using unitTestTemplate. If the user doesn't 
want to create their own objects, the predefined objects will be used in a predetermined unit test, and at the
end, two pointers of an abstract type will have their pure virtual functions called with the -> arrow operator.
*/

// main function to test the abstract class DistMeasurement and the concrete classes Meter and Foot.

int main()
{
	// variables for user prompts
	char firstChoice, secondChoice; // choice of unit types that user selects, used to pick the unit test to use.
	Meter mIn1, mIn2; // meter objects for use in the user selection
	Foot fIn1, fIn2; // feet objects for use in the user selection
	int userChoice;
	bool askUser = true;

	// variables for predefined tests
	Meter m1; // Meter object that uses default constructor
	Meter m2 = Meter(10); // Meter object set to 10 meters
	Foot f1; // Foot object that uses default constructor
	Foot f2 = Foot(10); // Foot object set to 10 feet
	DistMeasurement *abstractPtr1 =  new Meter(55); // pointer of abstract class to a new Meter object
	DistMeasurement  *abstractPtr2 = new Foot(55); // pointer of abstract class to a new Foot object
	

	// prompt user to determine if they want to create their own units
	cout << "Would you like to test your own units? (0:No, 1:Yes)" << endl;
	cout << "Enter Choice: ";
	cin >> userChoice;

	// user chose to enter their own units
	if (userChoice == 1)
	{
		// continue createing and testing new units until user chooses to exit
		do
		{
			cout << endl << "Select first Unit: (m for meters, f for feet, 0 to exit)" << endl;
			cout << "Enter Choice: ";
			cin >> firstChoice;

			// check what the first unit will be
			switch (firstChoice)
			{
				case 'm' : // meters
					cout << endl << "Enter first Unit: ";
					cin >> mIn1;
					break;

				case 'f' : // feet
					cout << endl << "Enter first Unit: ";
					cin >> fIn1;
					break;
				default :
					userChoice = 0;
					break;
			}
			
			// check if user decided to exit
			if (userChoice != 0)
			{
				cout << endl << "Select second Unit: (m for meters, f for feet, 0 to exit)" << endl;
				cout << "Enter Choice: ";
				cin >> secondChoice;

				// check what the second unit will be
				switch (secondChoice)
				{
					case 'm' : // meters
						cout << endl << "Enter first Unit: ";
						cin >> mIn2;
						break;

					case 'f' : // feet
						cout << endl << "Enter first Unit: ";
						cin >> fIn2;
						break;
					default :
						userChoice = 0;
						break;
				}
			}

			// user decided to exit or entered a bad choice
			if (userChoice == 0)
			{
				askUser = false;
			}

			// user entered good data and the correct unit test will be selected
			else
			{
				// the first unit is feet
				if (firstChoice == 'f')
				{
					// the first unit is feet and second unit is feet
					if (secondChoice == 'f')
					{
						cout << string(100, '#') << endl;
						unitTest(fIn1, fIn2);
						cout << string(100, '#') << endl;
					}

					// the first unit is fee and the second unit is meters
					if (secondChoice == 'm')
					{
						cout << string(100, '#') << endl;
						unitTest(fIn1, mIn2);
						cout << string(100, '#') << endl;
					}
				}

				// the first unit is meters
				if (firstChoice == 'm')
				{
					// the first unit is meters and the second unit is feet
					if (secondChoice == 'f')
					{
						cout << string(100, '#') << endl;
						unitTest(mIn1, fIn2);
						cout << string(100, '#') << endl;
					}

					// the firest unit is meters and the second unit is meters
					if (secondChoice == 'm')
					{
						cout << string(100, '#') << endl;
						unitTest(mIn1, mIn2);
						cout << string(100, '#') << endl;
					}
				}
			}	
		} while (askUser);
	}

	// user does not want to enter their own units so predefined units will be tested
	else
	{
		cout << string(100, '#') << endl;
		unitTest(m1, m2); // test two different Meter objects
		cout << string(100, '#') << endl;
		unitTest(f1, f2); // test two different Feet objects
		cout << string(100, '#') << endl;
		unitTest(m1, f2); // test a Meter object and a Foot object. Meter is the first operand
		cout << string(100, '#') << endl;
		unitTest(f1, m2); // test a Foot object and a Meter Object. Feet is the first operand
		cout << string(100, '#') << endl;
		unitTest(f1, f1); // test two of the same Foot objects
		cout << string(100, '#') << endl;
		unitTest(m1, m1); // test two of the same Meter objects
		cout << string(100, '#') << endl;

		cout << "Testing abstract pointer to call pure virtual method" << endl;
		cout << "abstractPtr1->getUnitFullName(): " << abstractPtr1->getUnitFullName() << endl;
		cout << "abstractPtr2->getUnitFullName(): " << abstractPtr2->getUnitFullName() << endl;
		cout << setw(15) << "" << "--End Test--" << endl;
		delete abstractPtr1; // delete object
		delete abstractPtr2; // delete object
	}
}


