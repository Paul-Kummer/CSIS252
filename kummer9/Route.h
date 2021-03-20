// File: Route.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog9
// Modified: 11/15/20

#pragma once
#include <string>


class Route
{
	private : 
		std::string rtName;
		int rtClass; //all technical free climbs are class 5
		int rtGrade; //grades go from 0-15, maybe 16 in the future

		//These are currently unimplemented, potentially for used in future projects
		//std::string subGrade;
		//std::string protectionRating;
		//int rtQuality;

	public :
		Route(); // default constructor
		Route(std::string, int, int); // main constructor
		Route(const Route&); // copy constructor
		friend std::ostream& operator<< (std::ostream&, const Route&);
		friend std::istream& operator>> (std::istream&, Route&);
		std::string getRtName() const;
		float getFullGrade() const;
		int getRtClass() const;
		int getRtGrade() const;
		void setRtName(std::string);
		void setRtClass(int);
		void setRtGrade(int);
		Route operator = (const Route&);

		// Mathematical operators do not make much sense with routes and are not included		
		//Route operator + (const Route&) const;
		//Route operator - (const Route&) const;
		//Route operator / (const Route&) const;
		//Route operator * (const Route&) const;
		
		Route operator ++ (); // pre increment the grade
		Route operator -- (); // pre decrement the grade
		Route operator ++ (int); // post increment the grade
		Route operator -- (int);  // post decrement the grade
		bool operator < (const Route&) const;
		bool operator > (const Route&) const;
		bool operator == (const Route&) const;
		bool operator != (const Route&) const;
		bool operator <= (const Route&) const;
		bool operator >= (const Route&) const;
};

		