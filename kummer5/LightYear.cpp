// File: LightYear.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog5
// Modified: 10/21/20

#include "LightYear.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//default constructor
LightYear::LightYear()
{
	number = 0;
}

// regualar param constructor
LightYear::LightYear(const float& num)
{
	number = num;
}

// copy constructor
LightYear::LightYear(const LightYear& liYr)
{
	number = liYr.number;
}

// output stream when object called
ostream& operator<< (ostream& out, const LightYear& liYr)
{
	// use singular form of word if value is between or equal to -1 and 1
	if(std::abs(liYr.getNumber()) <= 1 )
	{
		out << liYr.getNumber() << " Light-Year";	
	}

	// use plural form of word for values greater than 1 or less than -1
	else
	{
		out << liYr.getNumber() << " Light-Years";
	}

	return out;
}

// input stream
istream& operator>> (istream& userIn, LightYear& liYr)
{
	string num, unitType;
	cout << "Enter Value With Type (IE: 55 light-years): ";
	cin >> num >> unitType; // first user input will be a float and second user input checks unit validity

	// possible names for the Light-year unit
	if (unitType == "light-year" || 
		unitType == "ly" ||
		unitType == "Light-year" ||
		unitType == "Light-years" ||
		unitType == "light-years")
	{
		liYr.setNumber(stof(num));
	}

	// clear tne input stream  if bad user input is entered
	else
	{
		cerr << "-The wrong unit type was specified. Try (light-year, ly, or Light-Year)-" << endl;
		cin.clear();
	}	
	
	return userIn;
}

// get the objects value
float LightYear::getNumber() const
{
	return number;
}

// change the objects value
void LightYear::setNumber(const float& newNum)
{
	number = newNum;
}

// get the units name
string LightYear::getName() const
{
	return unitName;
}

// get the type of unit that Light-year is, which is distance
string LightYear::getType() const
{
	return unitType;
}

// get the abbreviated form of Light-year, which is ly
string LightYear::getAbbr() const
{
	return unitAbbr;
}

// assign a light-year the value of different light-year
LightYear LightYear::operator= (const LightYear& secondLightYear)
{
	// prevent self referencing
	if (this != &secondLightYear)
	{
		number = secondLightYear.number;
	}
	
	return *this;
}

// add two light-years to make a new light-year
LightYear LightYear::operator+ (const LightYear& secondLightYear) const // read only function
{
	LightYear newLightYr;
	newLightYr.number = number + secondLightYear.number;
	return newLightYr;
}

// subtract two light-years to make a new light-year
LightYear LightYear::operator- (const LightYear& secondLightYear) const // read only function
{
	LightYear newLightYr;
	newLightYr.number = number - secondLightYear.number;
	return newLightYr;
}

// divide two light-years to make a new light-year
LightYear LightYear::operator/ (const LightYear& secondLightYear) const // read only function
{
	LightYear newLightYr;
	if (secondLightYear.number != 0)
	{
		newLightYr.number = number / secondLightYear.number;
		return newLightYr;
	}

	// output error and return first operand because of division by zero
	else
	{
		cerr << "!!! cannot divide by zero, value unchanged !!! ";
		return *this;
	}
}

// multiply two light-years to make a new light-year
LightYear LightYear::operator* (const LightYear& secondLightYear) const // read only function
{
	LightYear newLightYr;
	newLightYr.number = number * secondLightYear.number;
	return newLightYr;
}

// preincrement a light-year's value
LightYear LightYear::operator++ ()
{
	++number;
	return *this;
}

// predecrement a light-year's value
LightYear LightYear::operator-- ()
{
	--number;
	return *this;
}

// postincrement a light-year's value
LightYear LightYear::operator++ (int dummyVar)
{
	LightYear temp = *this;
	number++;
	return temp;
}

// postdecrement a light-year's value
LightYear LightYear::operator-- (int dummyVar)
{
	LightYear temp = *this;
	number--;
	return temp;
}

// determine if a one light-year is greater than another
bool LightYear::operator> (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number > secondLightYear.number;
	return truth;
}

// determine if a one light-year is less than another
bool LightYear::operator< (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number < secondLightYear.number;
	return truth;
}

// determine if a one light-year is equal to another
bool LightYear::operator== (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number == secondLightYear.number;
	return truth;
}

// determine if a one light-year is not equal to another
bool LightYear::operator!= (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number != secondLightYear.number;
	return truth;
}

// determine if a one light-year is less than or equal to another
bool LightYear::operator<= (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number <= secondLightYear.number;
	return truth;
}

// determine if a one light-year is greater than or equal to another
bool LightYear::operator>= (const LightYear& secondLightYear) const
{
	bool truth;
	truth = number >= secondLightYear.number;
	return truth;
}