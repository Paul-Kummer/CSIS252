// File: Route.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog9
// Modified: 11/17/20

#include "Route.h"
#include "prototypes.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
Description:
Constructors and methods are defined for route objects. The operators of +, -, /, and * are not defined because
these operations do not make much sense from a traditional viewpoint.
*/

//default constructor
Route::Route()
{
	rtName = "VOID";
	rtClass = 5;
	rtGrade = 0;
}

// regualar param constructor
Route::Route(std::string tmpName, int tmpClass, int tmpGrade)
{
	rtName = tmpName;
	rtClass = tmpClass;
	rtGrade = tmpGrade;
}

// copy constructor
Route::Route(const Route& route)
{
	rtName = route.rtName;
	rtClass = route.rtClass;
	rtGrade = route.rtGrade;
}

// output stream when object called
ostream& operator<< (ostream& out, const Route& route)
{

	out << route.getRtName() << " | " << route.getRtClass() << "." << route.getRtGrade();	

	return out;
}

// input stream
istream& operator>> (istream& userIn, Route& route)
{
	// variables
	std::string lineToPeriod, tmpName, tmpClass, tmpGrade;
	int intGrade, intClass;
	std::string nameClassArr [2] = {"", ""}; //{"route name", "route class"}

	// prompt user for a route
	cout << "Do not include parenthesis (Route Name)(Route Class).(Route Grade) IE: Cool Route Name 5.11" << endl << "Enter Route: ";
	std::getline(cin, lineToPeriod, '.'); // get the string up to the period
	splitStrByNum(nameClassArr, lineToPeriod); // parse the split string into route name and route class
	route.setRtName(nameClassArr[0]); // set the route name as the first part of the split string
	intClass = stoi(nameClassArr[1]); // change the second part of the string to an integer
	route.setRtClass(intClass); // set the route name as the second part of the split string
	std::getline(cin, tmpGrade, '\n'); //this is a bug. if the user enters something after the decimal that isn't a number, the value is bad
	intGrade = stoi(tmpGrade); // convert to int
	route.setRtGrade(intGrade); // set the grade, which gets verified by other method
	
	return userIn;
}

// get the objects value
string Route::getRtName() const
{
	return rtName;
}

// get the comparison value of the route, DO NOT USE FOR DISPLAYING! use getRtGrade() and getRtClass() individually
float Route::getFullGrade()	const
{
	float tmpGrade = (float)getRtGrade()/100; // turn the grade into hundreths
	int tmpClass = getRtClass();

	tmpGrade = (float)tmpClass + tmpGrade; // add the class and grade together to get an accurate ranking for comparisons

	return tmpGrade;
}

// get the units name
int Route::getRtClass() const
{
	return rtClass;
}

// get the type of unit that route is, which is distance
int Route::getRtGrade() const
{
	return rtGrade;
}

//
void Route::setRtName(std::string newName)
{
	rtName = newName;
}

// get the abbreviated form of route, which is ly
void Route::setRtClass(int newClass)
{
	rtClass = newClass;
}

// set the grade of the route
void Route::setRtGrade(int newGrade)
{
	string tmpGrade = to_string(newGrade);
	rtGrade = checkGrade(tmpGrade); // check the grade before assigning it
}

// assign a route the value of different route
Route Route::operator= (const Route& secondRoute)
{
	// prevent self referencing
	if (this != &secondRoute)
	{
		rtName = secondRoute.getRtName();
		rtClass = secondRoute.getRtClass();
		rtGrade = secondRoute.getRtGrade();
	}
	
	return *this;
}

// preincrement a route's value
Route Route::operator++ ()
{
	++rtGrade;
	return *this;
}

// predecrement a route's value
Route Route::operator-- ()
{
	--rtGrade;
	return *this;
}

// postincrement a route's value
Route Route::operator++ (int dummyVar)
{
	Route temp = *this;
	rtGrade++;
	return temp;
}

// postdecrement a route's value
Route Route::operator-- (int dummyVar)
{
	Route temp = *this;
	rtGrade--;
	return temp;
}

// determine if a one route is greater than another
bool Route::operator> (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() > secondRoute.getFullGrade();
	return truth;
}

// determine if a one route is less than another
bool Route::operator< (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() < secondRoute.getFullGrade();
	return truth;
}

// determine if a one route is equal to another
bool Route::operator== (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() == secondRoute.getFullGrade();
	return truth;
}

// determine if a one route is not equal to another
bool Route::operator!= (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() != secondRoute.getFullGrade();
	return truth;
}

// determine if a one route is less than or equal to another
bool Route::operator<= (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() <= secondRoute.getFullGrade();
	return truth;
}

// determine if a one route is greater than or equal to another
bool Route::operator>= (const Route& secondRoute) const
{
	bool truth;
	truth = getFullGrade() >= secondRoute.getFullGrade();
	return truth;
}