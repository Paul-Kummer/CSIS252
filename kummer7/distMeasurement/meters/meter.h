//File: meter.h
//Name: Paul Kummer
//Class: CSIS 252
//Program: prog7
//Modified: 11/02/20

/*
Description:
Other students Meter class declaration modified to be a derived class of DistMeasurement
*/

/*
Spencer Meyer
10/23/20
meter.h
Assignment 5
CSIS 252

This is the .h file that contains the Meter class declaration/specification.
*/
#pragma once
#include "../distMeasurement.h"
#include <string>

class Meter : public DistMeasurement
{
    public:
        //constructors
        Meter();
        Meter(const float&);
        Meter(const Meter&);

        std::string getUnitFullName() const; // pure virtual function of DistMeasurement
        
        //overloaded operator
        friend std::ostream& operator<< (std::ostream&, const Meter&); // have derived class override
        friend std::istream& operator>> (std::istream&, Meter&); // have derived class override
        Meter operator = (const Meter&);		
        Meter operator + (const DistMeasurement&) const;
        Meter operator - (const DistMeasurement&) const;
        Meter operator / (const DistMeasurement&) const;
        Meter operator * (const DistMeasurement&) const;
};