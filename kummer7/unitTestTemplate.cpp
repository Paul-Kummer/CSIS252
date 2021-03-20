//File: unitTestTemplate.cpp
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

#include <iostream>
#include <string>
#include <iomanip>
#include "distMeasurement/feet/foot.h"
#include "distMeasurement/meters/meter.h"
using namespace std;

/*
Description:
This template is used to test Meter and Foot objects. It will test all methods and operations of the
first operand. The second operand is used to prove that the first operand is compatible with its operators
Both paramters used in the template will not have their values changed, instead a Meter and Foot object 
will be created and have their values changed. All tests will be output to the command prompt.
*/

// takes in two DistMeasurement objects of potentially different derived classes
template<typename A, typename B>
void unitTest(A valOne, B valTwo)
{
	// variables
	float testVal = 10; // value to change test objects to
    Meter testMeter = Meter(testVal); // Meter object for tests
	Foot testFoot = Foot(testVal); // Foot object for tests
    string border = string(75, '*'); // output border for seperating different parts of the test
	string tempStr; // store text from different parts of the tests, could be eliminated
	float tempNum; // store float from different parts of the tests, could be eliminated
	bool tempBool; // store bool from different parts of the tests, could be eliminated

	// format ouput for better ouput to user
    cout << showpoint << fixed << setprecision(4);

    cout << right << setw(5) << "" << "-- Begin Unit Test --" << endl << endl;
	cout << "valOne = " << valOne << endl; // show the user what the first parameter is
	cout << "valTwo = " << valTwo << endl << endl; // show the user waht the second parameter is

	// only tests the methods of the first parameter
    cout << border << endl;
    cout << right << setw(20) << "" << "[ Testing Methods ]" << endl; 
    cout << border << endl;
    cout << right << setw(5) << ">>> " << " Get unit in base unit of meters" << endl;
	tempNum = valOne.getBaseUnit();
    cout << "valOne.getBaseUnit(): " << tempNum << endl;
    cout << right << setw(5) << ">>> " << " Get unit ratio for converting to meters" << endl;
	tempNum = valOne.getRatio();
    cout << "valOne.getRatio(): " << tempNum << endl;
    cout << right << setw(5) << ">>> " << " Change unit number based on meters" << endl;
    testMeter.setNumberFromBase(testVal);
	testFoot.setNumberFromBase(testVal);
    cout << "testMeter.setNumberFromBase(testVal): " << testMeter << endl;
	cout << "testFoot.setNumberFromBase(testVal): " << testFoot << endl;
    cout << right << setw(5) << ">>> " << " Get the value number of unit" << endl;
	tempNum = valOne.getNumber();
    cout << "valOne.getNumber(): " << tempNum << endl;
    cout << right << setw(5) << ">>> " << " Set unit in base unit of meters" << endl;
    testMeter.setNumber(testVal);
	testFoot.setNumber(testVal);
    cout << "testMeter.setNumber(testVal): " << testMeter << endl;
	cout << "testFoot.setNumber(testVal): " << testFoot << endl;
    cout << right << setw(5) << ">>> " << " Get the name of the unit" << endl;
	tempStr = valOne.getName();
    cout << "valOne.getName() : " << tempStr << endl;
    cout << right << setw(5) << ">>> " << " Get the type of unit" << endl;
	tempStr = valOne.getType();
    cout << "valOne.getType() : " << tempStr << endl;
    cout << right << setw(5) << ">>> " << " Get the unit name abbreviation" << endl;
	tempStr = valOne.getAbbr();
    cout << "f3.getAbbr() : " << tempStr << endl;
    cout << right << setw(5) << ">>> " << " Get the units name, singular or plural" << endl;
	tempStr = valOne.getUnitFullName();
    cout << "valOne.getUnitFullName() 'meters': " << tempStr << endl;

	// the first parameter will be the first operand and the second parameter will be the second operand in all operations
    cout << border << endl;
    cout << right << setw(20) << "" << "[ Testing Arithmetic Operations ]" << endl;
    cout << border << endl;
    cout << right << setw(5) << ">>> " << " Assignment Operator" << endl;
    A newVal = valOne; // newVal will be the same derived class of DistMeasurement that the first parameter is
    cout << "<type> newVal = valOne: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " + Operator" << endl;
    newVal = valOne + valTwo;
    cout << "newVal = valOne + valTwo: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " - Operator" << endl;
    newVal = valOne - valTwo;
    cout << "newVal = valOne - valTwo: " << newVal << endl;
    cout << right << setw(5) << ">>> " <<  " / Operator" << endl;
    newVal = valOne / valTwo;
    cout << "newVal = valOne / valTwo: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " * Operator" << endl;
    newVal = valOne * valTwo;
    cout << "newVal = valOne * valTwo: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " ++val Operator" << endl;
    ++newVal;
    cout << "++newVal: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " val++ Operator" << endl;
    newVal++;
    cout << "newVal++: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " --val Operator" << endl;
    --newVal;
    cout << "--newVal: " << newVal << endl;
    cout << right << setw(5) << ">>> " << " newVal-- Operator" << endl;
    newVal--;
    cout << "newVal--: " << newVal << endl;

	// the first parameter will be the first operand and the second parameter will be the second operand in all operations
    cout << border << endl;
    cout << right << setw(20) << "" << "[ Testing Boolean Operations ]" << endl;
    cout << border << endl;
    cout << right << setw(5) << ">>> " << " less Than Operator" << endl;
	tempBool = valOne < valTwo;
    cout << "valOne < valTwo: " << tempBool << endl;
    cout << right << setw(5) << ">>> " << " greater Than Operator" << endl;
	tempBool = valOne > valTwo;
    cout << "valOne > valTwo: " << tempBool << endl;
    cout << right << setw(5) << ">>> " << " equal to Operator" << endl;
	tempBool = valOne == valTwo;
    cout << "valOne == valTwo: " << tempBool << endl;
    cout << right << setw(5) << ">>> " << " not equal to Operator" << endl;
	tempBool = valOne != valTwo;
    cout << "valOne != valTwo: " << tempBool << endl;
    cout << right << setw(5) << ">>> " << " less than or equal to Operator" << endl;
	tempBool = valOne <= valTwo;
    cout << "valOne <= valTwo: " << tempBool << endl;
    cout << right << setw(5) << ">>> " << " greater than or equal to Operator" << endl;
	tempBool = valOne >= valTwo;
    cout << "valOne >= valTwo: " << tempBool << endl;

    cout << endl << setw(5) << "" << "-- End Unit Test --" << endl << endl;
}