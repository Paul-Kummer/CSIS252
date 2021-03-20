// File: Mail.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/09/20

#pragma once

class Mail
{
	public:
		Mail();
		Mail(std::string, std::string);
		Mail(const Mail&);
		friend std::ostream& operator<< (std::ostream&, const Mail&);
		friend std::istream& operator>> (std::istream&, Mail&);
		std::string getSender();
		std::string getDayRecieved();
		void setSender(std::string);
		void setDayRecieved(std::string);
		

	private:
		std::string sender;
		std::string dayRecieved;
}