// File: Meaurement.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog6
// Modified: 10/24/20

#pragma once
#include <string>


class Measurment
{
	private : 
		float number = 0;
		float baseRatio = 0; // update this
		std::string unitName; // update this
		std::string unitType; // update this
		std::string unitAbbr; // update this

	public :
		Measurment(); // default constructor
		Measurment(std::string, std::string, std::string, const float&); // main constructor // update this
		Measurment(const Measurment&); // copy constructor
		friend std::ostream& operator<< (std::ostream&, const Measurment&);
		friend std::istream& operator>> (std::istream&, Measurment&);
		float getNumber() const;
		void setNumber(const float&);
		std::string getName() const;
		std::string getType() const;
		std::string getAbbr() const;
		float getRatio() const;
		Measurment operator = (const Measurment&);		
		Measurment operator + (const Measurment&) const;
		Measurment operator - (const Measurment&) const;
		Measurment operator / (const Measurment&) const;
		Measurment operator * (const Measurment&) const;
		Measurment operator ++ (); // pre increment
		Measurment operator -- (); // pre decrement
		Measurment operator ++ (int); // post increment
		Measurment operator -- (int);  // post decrement
		bool operator < (const Measurment&) const;
		bool operator > (const Measurment&) const;
		bool operator == (const Measurment&) const;
		bool operator != (const Measurment&) const;
		bool operator <= (const Measurment&) const;
		bool operator >= (const Measurment&) const;
};

		