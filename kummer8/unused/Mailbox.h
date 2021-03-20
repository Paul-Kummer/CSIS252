// File: Mailbox.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/09/20

#pragma once
#include <string>
#include "Mail.h"
#include "constants.h"

class Mailbox
{
	public:
		Mailbox(); //default mailbox constructor
		Mailbox(std::string); //empty mailbox constructor
		Mailbox(std::string, Mail []); //full mailbox constructor
		Mailbox(const Mailbox&); //copy constructor
		std::string getBoxName(); //return name of the mailbox
		Mail [] dumpMail(); //delete mail stack from box and return to whatever called it
		Mail popMail(); //removes item of mail at the front of array
		pushMail(Mail); //adds singular mail onto mail stack
		pushMail(Mail []); //adds a stack of mail on top of current stack

	private:
		std::string name; //the name of the mailbox
		Mail mail []; //array of mail stored in the mailbox
}