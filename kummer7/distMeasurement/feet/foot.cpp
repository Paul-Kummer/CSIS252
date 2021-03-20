//File: foot.h
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

/*
Description:
Other students Foot class definition modified to be a derived class of DistMeasurement
*/

/*
Kai Yodoya
10/23/20
foot.cpp
Assignment 5
CSIS 252

This is the file containing the foot file implementation.
*/
#include "foot.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// default foot constructor
Foot::Foot() : DistMeasurement(0, .3048, "Feet", "ft") {}

// parameterized foot constructor
Foot::Foot(const float& num) : DistMeasurement(num, .3048, "Feet", "ft") {}

// foot copy constructor
Foot::Foot(const Foot& mVal) : DistMeasurement(mVal) {}

// determines what the units pluarl name is
string Foot::getUnitFullName() const
{
    if(std::abs(getNumber()) <= 1)
    {
        return "foot";
    }
    else
    {
        return "feet";
    }
}

// assignment operator, will not allow assingment DistMeasurments that are not feet
Foot Foot::operator = (const Foot& f)
{
	// prevent self referencing
	if (this != &f)
	{
		this->number = f.getNumber();
		this->unitType = f.getType();
		this->unitName = f.getName();
		this->unitAbbr = f.getAbbr();
		this->conversionRatio = f.getRatio();
	}
	
	return *this;
}

// add foot with other DistMeasurment
Foot Foot::operator + (const DistMeasurement& secondOperand) const
{   
    Foot newFoot = Foot();
    float newBaseNum = this->getBaseUnit() + secondOperand.getBaseUnit();
    newFoot.setNumberFromBase(newBaseNum);
    return newFoot;
};

// subtract foot with other DistMeasurment
Foot Foot::operator - (const DistMeasurement& secondOperand) const
{
    Foot newFoot = Foot();
    float newBaseNum = this->getBaseUnit() - secondOperand.getBaseUnit();
    newFoot.setNumberFromBase(newBaseNum);
    return newFoot;
};

// divide foot with other DistMeasurment
Foot Foot::operator / (const DistMeasurement& secondOperand) const
{
    Foot newFoot = Foot();
    if (secondOperand.getBaseUnit() != 0)
    {
        float newBaseNum = this->getBaseUnit() / secondOperand.getBaseUnit();
        newFoot.setNumberFromBase(newBaseNum);
    }
    
    return newFoot;
};

// multiply foot with other DistMeasurment
Foot Foot::operator * (const DistMeasurement& secondOperand) const
{
    Foot newFoot = Foot();
    float newBaseNum = this->getBaseUnit() * secondOperand.getBaseUnit();
    newFoot.setNumberFromBase(newBaseNum);
    return newFoot;
};

// output of foot object
ostream& operator << (ostream& os, const Foot& f)
{
    os << f.getNumber() << " " << f.getUnitFullName();
    return os;
}

// input of foot object
istream& operator >> (istream& input, Foot& f) // should check for spelling of before creation
{
    string num, unitType;
	cout << "Enter Value With Type (IE: 55 ft): ";
	cin >> num >> unitType; // first user input will be a float and second user input checks unit validity

	// check all unit types names from an array // need to update
	if (unitType == "feet" || 
		unitType == "foot" ||
		unitType == "ft")
	{
		f.setNumber(stof(num));
	}

	// clear tne input stream  if bad user input is entered
	else
	{
		cerr << "-An unrecognized unit type was used-" << endl;
		cin.clear();
	}	
	
	return input;
}