//File: foot.h
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

/*
Description:
Other students Foot class declaration modified to be a derived class of DistMeasurement
*/

/*
Kai Yodoya
10/23/20
foot.h
Assignment 5
CSIS 252

This is the .h file that contains the Foot class declaration/specification.
*/
#pragma once
#include <string>
#include "../distMeasurement.h"

class Foot : public DistMeasurement
{
    public:
        // constructors
        Foot();
        Foot(const float&);
        Foot(const Foot&);

        std::string getUnitFullName() const; // pure virtual function of DistMeasurement

        // operator overrides
		friend std::ostream& operator<< (std::ostream&, const Foot&); // have derived class override
		friend std::istream& operator>> (std::istream&, Foot&); // have derived class override
        Foot operator = (const Foot&);		
		Foot operator + (const DistMeasurement&) const;
		Foot operator - (const DistMeasurement&) const;
		Foot operator / (const DistMeasurement&) const;
		Foot operator * (const DistMeasurement&) const;
};