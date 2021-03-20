// File: Measurment.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog6
// Modified: 10/24/20

#include "Measurment.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//default constructor
Measurment::Measurment()
{
	float number = 0;
	float baseRatio = 0;
	std::string unitName = "name";
	std::string unitType = "unit";
	std::string unitAbbr = "abbr";
}

// regualar param constructor
Measurment::Measurment(std::string name, std::string unit, std::string abbr, const float& ratio)
{
	number = 0;
	baseRatio = ratio;
	unitName = name;
	unitType = unit;
	unitAbbr = abbr;
}

// copy constructor
Measurment::Measurment(const Measurment& mVal)
{
	number = mVal.number;
	baseRatio = mVal.baseRatio;
	unitName = mVal.unitName;
	unitType = mVal.unitType;
	unitAbbr = mVal.unitAbbr;
}

// output stream when object called
ostream& operator<< (ostream& out, const Measurment& mVal)
{
	// use singular form of word if value is between or equal to -1 and 1
	if(std::abs(mVal.getNumber()) <= 1 )
	{
		out << mVal.getNumber() << mVal.getName();	
	}

	// use plural form of word for values greater than 1 or less than -1
	else
	{
		out << mVal.getNumber() << mVal.getName() << "s";
	}

	return out;
}

// input stream
istream& operator>> (istream& userIn, Measurment& mVal)
{
	string num, unitType;
	cout << "Enter Value With Type (IE: 55 measurmentss): ";
	cin >> num >> unitType; // first user input will be a float and second user input checks unit validity

	// check all unit types names from an array // need to update
	if (unitType == mVal.getName() || 
		unitType == mVal.getName() + "s" ||
		unitType == mVal.getAbbr() ||
		unitType == mVal.getAbbr() + "s")
	{
		
		mVal.setNumber(stof(num));
	}

	// clear tne input stream  if bad user input is entered
	else
	{
		cerr << "-An unrecognized unit type was used-" << endl;
		cin.clear();
	}	
	
	return userIn;
}

// get the objects value
float Measurment::getNumber() const
{
	return number;
}

// change the objects value
void Measurment::setNumber(const float& newNum)
{
	number = newNum;
}

// get the units name
string Measurment::getName() const
{
	return unitName;
}

// get the type of unit that a measurment is
string Measurment::getType() const
{
	return unitType;
}

// get the abbreviated form of a measurment
string Measurment::getAbbr() const
{
	return unitAbbr;
}

float Measurment::getRatio() const
{
	return baseRatio;
}

// assign a measurment the value of different measurment
Measurment Measurment::operator= (const Measurment& secondMeasurment)
{
	// prevent self referencing
	if (this != &secondMeasurment)
	{
		number = secondMeasurment.getNumber();
		unitType = secondMeasurment.getType();
		unitName = secondMeasurment.getName();
		unitAbbr = secondMeasurment.getAbbr();
		baseRatio = secondMeasurment.getRatio();
	}
	
	return *this;
}

// add two measurments to make a new measurment
Measurment Measurment::operator+ (const Measurment& secondMeasurment) const // read only function
{
	Measurment newVal;
	newVal.number = number + secondMeasurment.number;
	return newVal;
}

// subtract two measurments to make a new measurment
Measurment Measurment::operator- (const Measurment& secondMeasurment) const // read only function
{
	Measurment newVal;
	newVal.number = number - secondMeasurment.number;
	return newVal;
}

// divide two measurments to make a new measurment
Measurment Measurment::operator/ (const Measurment& secondMeasurment) const // read only function
{
	Measurment newVal;
	if (secondMeasurment.number != 0)
	{
		newVal.number = number / secondMeasurment.number;
		return newVal;
	}

	// output error and return first operand because of division by zero
	else
	{
		cerr << "!!! cannot divide by zero, value unchanged !!! ";
		return *this;
	}
}

// multiply two measurments to make a new measurment
Measurment Measurment::operator* (const Measurment& secondMeasurment) const // read only function
{
	Measurment newVal;
	newVal.number = number * secondMeasurment.number;
	return newVal;
}

// preincrement a measurment's value
Measurment Measurment::operator++ ()
{
	++number;
	return *this;
}

// predecrement a measurment's value
Measurment Measurment::operator-- ()
{
	--number;
	return *this;
}

// postincrement a measurment's value
Measurment Measurment::operator++ (int dummyVar)
{
	Measurment temp = *this;
	number++;
	return temp;
}

// postdecrement a measurment's value
Measurment Measurment::operator-- (int dummyVar)
{
	Measurment temp = *this;
	number--;
	return temp;
}

// determine if a one measurment is greater than another
bool Measurment::operator> (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number > secondMeasurment.number;
	return truth;
}

// determine if a one measurment is less than another
bool Measurment::operator< (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number < secondMeasurment.number;
	return truth;
}

// determine if a one measurment is equal to another
bool Measurment::operator== (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number == secondMeasurment.number;
	return truth;
}

// determine if a one measurment is not equal to another
bool Measurment::operator!= (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number != secondMeasurment.number;
	return truth;
}

// determine if a one measurment is less than or equal to another
bool Measurment::operator<= (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number <= secondMeasurment.number;
	return truth;
}

// determine if a one measurment is greater than or equal to another
bool Measurment::operator>= (const Measurment& secondMeasurment) const
{
	bool truth;
	truth = number >= secondMeasurment.number;
	return truth;
}