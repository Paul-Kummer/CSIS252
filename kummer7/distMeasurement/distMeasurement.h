//File: distMeasurement.cpp
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

/*
Description:
Base class of distance measurments, which is used for the instantiation of derived classes Meters and Foot.
*/

#pragma once
#include <string>

class DistMeasurement
{
	protected : // accessible to derived classes
		float number; // the value of the unit
		float conversionRatio; // ratio to convert the unit to meters
		std::string unitName; // what the unit name is, IE meters or feet
		std::string unitType; // always set to "Distance"
		std::string unitAbbr; // how the unit is abbreviated

	public :
		// since DistMeasurement isn't a concrete class, you can not instantiate it independently, but derived classes can call base constructors
		DistMeasurement(const float&, const float&, const std::string&, const std::string&); // main constructor
		DistMeasurement(const DistMeasurement&); // copy constructor
		float getBaseUnit() const; // the value converted to meters
		float getRatio() const; // the ratio for converting to meters
		void setNumberFromBase(float); // change the value based on meters passed as parameter
		float getNumber() const; // get the value of object
		void setNumber(const float&); // change the value of object
		std::string getName() const; // get the name of the type of object
		std::string getType() const; // show that object is "Distance"
		std::string getAbbr() const; // show the abbreviated name
		virtual std::string getUnitFullName() const = 0; // get the units name, plural or singular

		// all operations will work with the base unit meters and the first operand will be the return type		
		void operator ++ (); // pre increment
		void operator -- (); // pre decrement
		void operator ++ (int); // post increment
		void operator -- (int);  // post decrement
		bool operator < (const DistMeasurement&) const;
		bool operator > (const DistMeasurement&) const;
		bool operator == (const DistMeasurement&) const;
		bool operator != (const DistMeasurement&) const;
		bool operator <= (const DistMeasurement&) const;
		bool operator >= (const DistMeasurement&) const;
};