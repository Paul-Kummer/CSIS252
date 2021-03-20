//File: meter.cpp
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

/*
Description:
Other students Meter class definition modified to be a derived class of DistMeasurement
*/

/*
Spencer Meyer
10/23/20
meter.cpp
Assignment 5
CSIS 252

This is the file containing the Meter file implementation.
*/
#include "meter.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//default constructor
//preconditions: None.
//postcondition: .meter is set to zero and is a float
Meter::Meter() : DistMeasurement(0, 1, "Meter", "m"){}

//constructor that takes in a number
//precondition: The number is a float value
//postcondition .meter is set to the number in the parantheses
Meter::Meter(const float& m) : DistMeasurement(m, 1, "Meter", "m"){}

//copy constructor that copies the information to a newly created Meter object
//precondition: The parameter is of type Meter
//postcondition: The new Meter object is copied from the Meter object in the parantheses
Meter::Meter(const Meter& mVal) : DistMeasurement(mVal){}

//method that returns the full name of the .meter within the Meter object
//It will change depending on the .meter value
//precondition: None.
//postcondition: None. The unit full name is returned
string Meter::getUnitFullName() const // defines the pure virstual function
{
    if(abs(this->getNumber())<=1)
    {
        return "meter";
    }
    else
    {
        return "meters";
    }
}

//overloaded assignment operator
//precondition: the value in the parantheses is of type Meter
//postcondition: The Meter object is now assigned to the inputted Meter object
Meter Meter::operator = (const Meter& m)
{
	// prevent self referencing
	if (this != &m)
	{
		this->number = m.getNumber();
		this->unitType = m.getType();
		this->unitName = m.getName();
		this->unitAbbr = m.getAbbr();
		this->conversionRatio = m.getRatio();
	}
	
	return *this;
}

// add meter with other DistMeasurment
Meter Meter::operator + (const DistMeasurement& secondOperand) const
{   
    Meter newMeter = Meter();
    float newBaseNum = this->getBaseUnit() + secondOperand.getBaseUnit();
    newMeter.setNumberFromBase(newBaseNum);
    return newMeter;
};

// subtract meter with other DistMeasurment
Meter Meter::operator - (const DistMeasurement& secondOperand) const
{
    Meter newMeter = Meter();
    float newBaseNum = this->getBaseUnit() - secondOperand.getBaseUnit();
    newMeter.setNumberFromBase(newBaseNum);
    return newMeter;
};

// divide meter with other DistMeasurment
Meter Meter::operator / (const DistMeasurement& secondOperand) const
{
    Meter newMeter = Meter();
    if (secondOperand.getBaseUnit() != 0)
    {
        float newBaseNum = this->getBaseUnit() / secondOperand.getBaseUnit();
        newMeter.setNumberFromBase(newBaseNum);
    }
    
    return newMeter;
};

// multiply meter with other DistMeasurment
Meter Meter::operator * (const DistMeasurement& secondOperand) const
{
    Meter newMeter = Meter();
    float newBaseNum = this->getBaseUnit() * secondOperand.getBaseUnit();
    newMeter.setNumberFromBase(newBaseNum);
    return newMeter;
};

//overloaded insertion operator
//precondition: the value is of type Meter
//postcondition: returns the .getMeter method along with a string outputting the meter full name.
ostream& operator << (ostream& o, const Meter& m)
{
    o << m.getNumber() << " " << m.getUnitFullName();
    return o;
}

//overloaded extraction operator
//keyboard enters a number and inputs it into the .meter instance of the Meter object.
//precondition: input must be a float
//postcondition: none.
istream& operator >> (istream& input, Meter& m) // should check for spelling of before creation
{
    string num, unitType;
	cout << "Enter Value With Type (IE: 55 m): ";
	cin >> num >> unitType; // first user input will be a float and second user input checks unit validity

	// check all unit types names from an array // need to update
	if (unitType == "meter" || 
        unitType == "metre" || 
		unitType == "meters" ||
        unitType == "metres" ||
		unitType == "m")
	{
		m.setNumber(stof(num));
	}

	// clear tne input stream  if bad user input is entered
	else
	{
		cerr << "-An unrecognized unit type was used-" << endl;
		cin.clear();
	}	
	
	return input;
}