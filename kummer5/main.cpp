// File: main.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog5
// Modified: 10/21/20

#include <iostream>
#include <iomanip>
#include <string>
#include "LightYear.h"
#include "prototypes.h"

using namespace std;

int main(int argc, char *argv[])
{
	// var for assignments
	LightYear newVal;
	bool boolVal, continueInput=true;

	LightYear defaultLY = LightYear();
	printTest("Default Constructor", defaultLY);

	LightYear tenLY = LightYear(10);
	printTest("Main Constructor : value 10", tenLY);

	LightYear negTenLY = LightYear(-10);
	printTest("Negative Value : value -10", negTenLY);

	LightYear twentyFiveAndHalfLY = LightYear(25.5);
	printTest("Positive Fraction : 25.5", twentyFiveAndHalfLY);

	LightYear halfLY = LightYear(.5);
	printTest("Half Value : value .5", halfLY);

	LightYear copyConstruct = LightYear(tenLY);
	printTest("Copy Constructor : LightYear(tenLY) = 10", copyConstruct);

	// get method tests
	float getNum = tenLY.getNumber();
	string getName = tenLY.getName();
	string getType = tenLY.getType();
	string getAbbr = tenLY.getAbbr();

	// set method tests
	tenLY.setNumber(100.101);

	cout << showpoint << fixed << setprecision(4);
	cout << string(100, '*') << endl;
	cout << setw(15) << "" << "-Test- (get methods of tenLY var)" << endl;
	cout << "getNum() of var tenLY: "<< getNum << endl;
	cout << "getName() of var tenLY: "<< getName << endl;
	cout << "getType() of var tenLY: "<< getType << endl;
	cout << "getAbbr() of var tenLY: "<< getAbbr << endl;
	cout << setw(15) << "" << "-Test- (set method of tenLY var)" << endl;
	cout << "setNumber(100.101) of var tenLY: "<< tenLY.getNumber() << endl;

	tenLY.setNumber(10); // restore tenLY back to 10

	cout << setw(15) << "" << "TenLY restored to 10" << endl;
	cout << setw(50) << "" << "[Complete]" << endl;
	cout << string(100, '*') << endl << endl;

	// test operations
	printOperations("operator=", "=", newVal, tenLY);
	newVal = tenLY;
	printResult(newVal, boolVal);

	printOperations("operator+", "+", tenLY, twentyFiveAndHalfLY);
	newVal = tenLY + twentyFiveAndHalfLY;
	printResult(newVal, boolVal);

	printOperations("operatior-", "-", tenLY, twentyFiveAndHalfLY);
	newVal = tenLY - twentyFiveAndHalfLY;
	printResult(newVal, boolVal);

	printOperations("operator/", "/", tenLY, twentyFiveAndHalfLY);
	newVal = tenLY / twentyFiveAndHalfLY;
	printResult(newVal, boolVal);

	printOperations("divide by zero", "/", tenLY, defaultLY);
	newVal = tenLY / defaultLY;
	printResult(newVal, boolVal);

	printOperations("operator*", "*", tenLY, twentyFiveAndHalfLY);
	newVal = tenLY * twentyFiveAndHalfLY;
	printResult(newVal, boolVal);

	printOperations("operator++", "++val", tenLY, tenLY);
	++tenLY;
	printResult(tenLY, boolVal);

	printOperations("operator--", "--val", tenLY, tenLY);
	--tenLY;
	printResult(tenLY, boolVal);

	printOperations("operator++", "val++", tenLY, tenLY);
	tenLY++;
	printResult(tenLY, boolVal);

	printOperations("operator--", "val--", tenLY, tenLY);
	tenLY--;
	printResult(tenLY, boolVal);

	printOperations("operator<", "<", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY < twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	printOperations("operator>", ">", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY > twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	printOperations("operator==", "==", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY == twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	printOperations("operator!=", "!=", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY != twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	printOperations("operator<=", "<=", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY <= twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	printOperations("operator>=", ">=", tenLY, twentyFiveAndHalfLY);
	boolVal = tenLY >= twentyFiveAndHalfLY;
	printResult(tenLY, boolVal);

	// test extraction operator
	do
	{
		LightYear userInput;
		LightYear *ptToNull = &userInput;
		ptToNull = NULL;
		cout << endl << "-Test extraction Operator-" << endl;
		cin >> userInput;
		if (userInput != NULL)
		{
			continueInput = false;
			cout << endl << "the light year created is: " << userInput << endl;
		}
	} while (continueInput);
	

   return 0;
}


