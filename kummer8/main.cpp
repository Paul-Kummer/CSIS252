// File: main.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/12/20

#include "mailQueue.h"
#include "mailStack.h"
#include "prototypes.h"
#include <string>
#include <iostream>
using namespace std;

/*
Description:
Prompt users to perform actions and then perform that action
*/

// main function 
int main()
{
	// variables
	MailQueue mailBoxes = MailQueue(6); //6 number of quarentine boxes
	MailStack homeBox = MailStack();
	MailStack driveBox = MailStack();
	string userSelection, tempMail;
	string tempString;

	cout << "[ Mail Quarentine System ]" << endl << endl;

	do
	{
		cout << std::string(100, '*') << endl;
		cout << "Choose an action to perform" << endl
			<< "1 : morning routine, complete tasks of collecting mail and moving mail to appropriate spot" << endl 
			<< "2 : mailperson, deposit a mail item in the mailbox" << endl 
			<< "3 : whenever, take an item of mail out of the home box" << endl
			<< "4 : dump, show contents of queue and mail stacks" << endl
			<< "0 : exit" << endl;
		cout << "Enter Selection: ";
		cin >> userSelection;

		switch (std::stoi(userSelection))
		{
		case 1:
			morningRoutine(mailBoxes, homeBox, driveBox);
			break;

		case 2:
			mailPerson(driveBox);
			break;

		case 3:
			tempMail = whenever(homeBox);
			cout << "Mail from top of box is: " << tempMail << endl;
			break;

		case 4:
			cout << "*** Outputting all boxes and queues ***" << endl << endl;
			dump(mailBoxes, driveBox, homeBox);
			break;
		
		default:
			break;
		}

	} while (userSelection != "0");
}
