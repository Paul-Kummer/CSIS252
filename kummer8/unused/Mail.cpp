// File: Mail.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/09/20

#pragma once
#include <string>
#include <iostream>
#include "Mail.h"
#include "stringToDay.h"

//default mail constructor
Mail()
{
	std::string sender = "Sender Unknown";
	std::string dayRecieved = "Unknown";
}
//complete mail constructor
Mail(std::string tmpSender, std::string tmpRecievedDay)
{
	std::string sender = tmpSender;
	std::string dayRecieved = tmpRecievedDay;
}

//copy mail constructor
Mail(const Mail& tmpMail)
{
	std::string sender = tmpMail.getSender();
	std::string dayRecieved = tmpMail.getDayRecieved();
}

//output for mail item to stream
friend std::ostream& operator<< (std::ostream& out, const Mail& outMail)
{
	out << "Sender: " << outMail.getSender() << " | Date: " << outMail.getDateRecieved(); //will need to use ctime() somehow
	return out;
}

//create mail item from stream
friend std::istream& operator>> (std::istream& in, Mail& inMail)
{
	std::string tmpSender, tmpDayRecieved;
	std::cin >> tmpSender >> tmpDayRecieved;
	
	inMail.setSender(tmpSender);
	inMail.setDayRecieved(stringToDay(tmpDayRecieved));
	
	std::cin.clear();
	return in;
}

//return who sent the mail
std::string getSender()
{
	return this.sender;
}

//return the time mail was recieved, used for mailbox placement
time_t getDayRecieved()
{
	return this.dateRecieved;
}

//assign a sender to piece of mail
void setSender(std::string tmpSender)
{
	this.sender = tmpSender;
}

//assign a recieved date to piece of mail
void setDayRecieved(std::string tmpDay)
{
	this.dateRecieved = tmpDay;
}

