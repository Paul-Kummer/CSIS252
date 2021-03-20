//File: distMeasurement.cpp
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20


/*
The third class is the class that you will write. It will be a parent class. For example, if one class you chose was for yards and one was for meters, 
then the parent class would be a LengthMeasurement class. The parent class will be an abstract class - you will not be able to create concrete instances of it,
because it will have pure virtual methods (virtual methods which are declared but not defined in that class - they were covered in the Chapter 13 lecture).

All of the concrete classes must satisfy the Assignment 5 requirements.

    a default constructor, that sets the initial value to zero
    a constructor that takes in a number (your choice of int, float, double, and so on) and sets the initial value to that
    copy constructor
    overloaded assignment operator
    a way to set and get that value (the quantity of the unit)
    comparisons between different instances of your class (just compares the values) (overloaded operators)
    ways to input and output your unit (input reads in a number and a string and makes sure that the string matches the unit name or abbreviation, and output writes out the number and then a string that is either the unit name or plural or abbreviation) (overloaded and/or friend insertion and extraction operators)
    ways to get the name of the unit (for example, returns a string "meter" if this is for meters), the abbreviation of the unit (for example, returns the string "m" if this is for meteres), and the plural of the name of the unit (for example, returns the string "meters" if this is for meters). Note that for unit names, support both American and British spellings.

*/

#include "distMeasurement.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
Description:
DistMeasurement is defined. It is and abstract base class for the Meter and Foot classes.
*/

// regualar param constructor
DistMeasurement::DistMeasurement(const float& num, const float& ratio, const std::string& name, const std::string& abbr)
{
	number = num;
    conversionRatio = ratio;
	unitName = name;
	unitType = "Distance"; // all DistMeasurements are all of type distance unless other classes are created later on
	unitAbbr = abbr;
}

// copy constructor
DistMeasurement::DistMeasurement(const DistMeasurement& mVal)
{
	number = mVal.number;
	conversionRatio = mVal.conversionRatio;
	unitName = mVal.unitName;
	unitType = mVal.unitType;
	unitAbbr = mVal.unitAbbr;
}

// gets the number of meters of the unit. Meters is the base unit for all distance units, which is used to convert the values of other types
float DistMeasurement::getBaseUnit() const
{
    return this->getNumber() * this->getRatio(); // convert from the unit it is to meters by using it's conversion ratio
}

// get the objects conversion ratio to meters
float DistMeasurement::getRatio() const
{
	return this->conversionRatio;
}

// take a number, presumed to be meters, and change the objects number to what the meter equivilant is
void DistMeasurement::setNumberFromBase(float meters)
{
    float newNum = meters / this->getRatio(); // converts from meters to the current unit
    this->setNumber(newNum); // change the number to the conversion
}

// get the objects value
float DistMeasurement::getNumber() const
{
	return this->number;
}

// change the objects value
void DistMeasurement::setNumber(const float& newNum)
{
	this->number = newNum;
}

// get the units name
string DistMeasurement::getName() const
{
	return this->unitName;
}

// get the type of unit that a DistMeasurement is
string DistMeasurement::getType() const
{
	return this->unitType;
}

// get the abbreviated form of a DistMeasurement
string DistMeasurement::getAbbr() const
{
	return this->unitAbbr;
}

// preincrement a DistMeasurement's value
void DistMeasurement::operator++ ()
{
    float tempNum = this->getNumber();
    ++tempNum;
    this->setNumber(tempNum);
}

// predecrement a DistMeasurement's value
void DistMeasurement::operator-- ()
{
    float tempNum = this->getNumber();
    --tempNum;
    this->setNumber(tempNum);
}

// postincrement a DistMeasurement's value
void DistMeasurement::operator++ (int dummyVar)
{
	float tempNum = this->getNumber();
    tempNum++;
    this->setNumber(tempNum);
}

// postdecrement a DistMeasurement's value
void DistMeasurement::operator-- (int dummyVar)
{
	float tempNum = this->getNumber();
    tempNum--;
    this->setNumber(tempNum);
}

// determine if a one DistMeasurement is greater than another
bool DistMeasurement::operator> (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() > secondDistMeasurement.getBaseUnit();
	return truth;
}

// determine if a one DistMeasurement is less than another
bool DistMeasurement::operator< (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() < secondDistMeasurement.getBaseUnit();
	return truth;
}

// determine if a one DistMeasurement is equal to another
bool DistMeasurement::operator== (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() == secondDistMeasurement.getBaseUnit();
	return truth;
}

// determine if a one DistMeasurement is not equal to another
bool DistMeasurement::operator!= (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() != secondDistMeasurement.getBaseUnit();
	return truth;
}

// determine if a one DistMeasurement is less than or equal to another
bool DistMeasurement::operator<= (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() <= secondDistMeasurement.getBaseUnit();
	return truth;
}

// determine if a one DistMeasurement is greater than or equal to another
bool DistMeasurement::operator>= (const DistMeasurement& secondDistMeasurement) const
{
	bool truth;
	truth = this->getBaseUnit() >= secondDistMeasurement.getBaseUnit();
	return truth;
}