// File: LightYear.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog5
// Modified: 10/20/20

#pragma once
#include <string>


class LightYear
{
	private : 
		float number = 0;
		std::string unitName = "Light-Year";
		std::string unitType = "Distance";
		std::string unitAbbr = "ly";

	public :
		LightYear(); // default constructor
		LightYear(const float&); // main constructor
		LightYear(const LightYear&); // copy constructor
		friend std::ostream& operator<< (std::ostream&, const LightYear&);
		friend std::istream& operator>> (std::istream&, LightYear&);
		float getNumber() const;
		void setNumber(const float&);
		std::string getName() const;
		std::string getType() const;
		std::string getAbbr() const;
		LightYear operator = (const LightYear&);		
		LightYear operator + (const LightYear&) const;
		LightYear operator - (const LightYear&) const;
		LightYear operator / (const LightYear&) const;
		LightYear operator * (const LightYear&) const;
		LightYear operator ++ (); // pre increment
		LightYear operator -- (); // pre decrement
		LightYear operator ++ (int); // post increment
		LightYear operator -- (int);  // post decrement
		bool operator < (const LightYear&) const;
		bool operator > (const LightYear&) const;
		bool operator == (const LightYear&) const;
		bool operator != (const LightYear&) const;
		bool operator <= (const LightYear&) const;
		bool operator >= (const LightYear&) const;
};

		