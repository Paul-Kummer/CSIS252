// File: mainFunctions.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/12/20

#include "prototypes.h"
#include <string>
#include <iostream>
using namespace std;

/*
Description:
Definitions of functions used in the main program
*/

//remove a stack of mail from the queue and place the contents in the box in home
//Also, take the mail from the outside mailbox in place it in the queue
void morningRoutine(MailQueue& mailBox, MailStack& home, MailStack& driveway)
{
	std::string tempStr;
	MailStack stackToGoInHome;
	MailStack stackToEnterQuarentine;

	if(!mailBox.isFullQueue()) //if the queue isn't full continue adding items
	{
		while(!driveway.isEmpty())
		{
			tempStr = driveway.pop();
			stackToEnterQuarentine.push(tempStr);
		};
		mailBox.addQueue(stackToEnterQuarentine);
	}

	else //queue is full start sending items into home that have been quarentined
	{
		stackToGoInHome = mailBox.front();
		stackToEnterQuarentine = mailBox.back();
		mailBox.removeFront();

		while(!driveway.isEmpty())
		{
			tempStr = driveway.pop();
			stackToEnterQuarentine.push(tempStr);
		};

		while (!stackToGoInHome.isEmpty())
		{
			tempStr = stackToGoInHome.pop();
			home.push(tempStr);
		};
	}
}

//take a piece of mail off the stack inside the home
std::string whenever(MailStack& home)
{
	std::string tempString = home.pop();
	return tempString;
}

//places a mail item in the outside mailbox
void mailPerson(MailStack& driveway)
{
	std::string mailItem;
	cout << "Please Enter Your Mail: ";
	cin.ignore();
	std::getline(std::cin, mailItem);
	driveway.push(mailItem);
}

//display the entire queue and all the mailboxes
void dump(MailQueue& mailBox, MailStack& drivewayBox, MailStack& homeBox)
{
	std::string tmpStackTop;
	std::string tmpString;
	MailStack curStack;

	cout << "[ Current Mailbox Queue ]" << endl;
	while(!mailBox.isEmptyQueue())
	{
		cout << string(75, '#') << endl;
		cout << "--Queue Item--" << endl;
		cout << "Queue Count: " << to_string(mailBox.getCount()) << endl;
		cout << "Queue Front: " << to_string(mailBox.getQueueFront()) << endl;
		cout << "Queue Rear: " << to_string(mailBox.getQueueRear()) << endl;
		
		cout << "--Mail Stack--" << endl;
		curStack = mailBox.front();

		while(!curStack.isEmpty())
		{
			tmpString = curStack.pop();
			tmpStackTop = to_string(curStack.getStackTop());
			
			cout << "mail item at stack position [" << tmpStackTop << "]: " << tmpString << endl;
		};
		mailBox.removeFront();
		cout << string(75, '#') << endl;
	};

	cout << "[ Mail at Driveway ]" << endl;
	while(!drivewayBox.isEmpty())
	{
		tmpString = drivewayBox.pop();
		tmpStackTop = to_string(drivewayBox.getStackTop());
		
		cout << "mail item at stack position [" << tmpStackTop << "]: " << tmpString << endl;
	}
	
	cout << "[ Mail at Home ]" << endl;
	while(!homeBox.isEmpty())
	{
		tmpString = homeBox.pop();
		tmpStackTop = to_string(homeBox.getStackTop());
		
		cout << "mail item at stack position [" << tmpStackTop << "]: " << tmpString << endl;
	}

	cout << endl << "[ Dump Complete ]" << endl << endl;
}
