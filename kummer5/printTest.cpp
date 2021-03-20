// File: main.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog5
// Modified: 10/20/20

#include <iostream>
#include <iomanip>
#include <string>
#include "LightYear.h"
#include "prototypes.h"

using namespace std;

void printOperations (string testName, string operationVal, LightYear varVal1, LightYear varVal2)
{
	cout << showpoint << fixed << setprecision(4);
	cout << string(100, '*') << endl;
	cout << setw(15) << "" << "-Test- (" << testName << ")" << endl;
	cout << setw(20) << varVal1 << setw(8) << right << operationVal << setw(20) << varVal2 << " = ";
}

void printResult(LightYear newVal, bool boolVar=false)
{
	cout << newVal << " : " << boolVar << endl;
	cout << setw(50) << "" << "[Complete]" << endl;
	cout << string(100, '*') << endl << endl;
}

void printTest (string testName, LightYear lightYrVar)
{
	cout << showpoint << fixed << setprecision(4);
	cout << string(100, '*') << endl;
	cout << setw(15) << "" << "-Test- (" << testName << ")" << endl;
	cout << setw(25) << "" << lightYrVar << endl;
	cout << setw(50) << "" << "[Complete]" << endl;
	cout << string(100, '*') << endl << endl;
}