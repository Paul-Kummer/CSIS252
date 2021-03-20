// File: mailStack.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/12/20

#include <iostream>
#include "mailStack.h"

/*
Description:
Creates a stack of mail
*/

//default constructor
MailStack::MailStack()
{
	maxStackSize = 100;
	stackTop = 0;
	mail = new std::string [maxStackSize];
};

//parameterized constructor
MailStack::MailStack(int stackSize)
{
	int tempStackSize = stackSize >= 0 ? stackSize : 100;

	maxStackSize = tempStackSize;
	stackTop = 0;
	mail = new std::string [maxStackSize];
};

//copy constructor
MailStack::MailStack(const MailStack& otherStack)
{
	mail = NULL;
	copyMail(otherStack);
};

//destructor
MailStack::~MailStack()
{
	delete [] mail;
};

//set default values
void MailStack::initStack()
{
	stackTop = 0;
};

//check if the stack has any elements
bool MailStack::isEmpty()
{
	return stackTop == 0;
};

//check if the stack is at maximum capacity
bool MailStack::isFull()
{
	return stackTop == maxStackSize;
};

//add a mail item to the top of the stack
void MailStack::push(std::string mailItem)
{
	if (!isFull())
	{
		mail[stackTop] = mailItem;
		stackTop++; //advances index to next insertion point
	}
	
	else
	{
		std::cout << "! Stack is Full !" << std::endl;
	}	
};

//view the top of the stack
std::string MailStack::top()
{
	if (!isEmpty())
	{
		return mail[stackTop -1]; //reduce stacktop by one because that point is null and intended for the next insertion
	}

	else //should not encounter this if isEmpty is checked
	{
		return "Void";
	}	
};

//view and remove the top of the stack
std::string MailStack::pop()
{	
	if (!isEmpty())
	{
		std::string topOfStack = mail[stackTop-1]; //temp copy of the stack top
		stackTop--; //move index down one
		return topOfStack; //return the copied item removed
	}

	else
	{
		return "! Stack is Empty !";
	}	
};

//assignment operator
const MailStack& MailStack::operator=(const MailStack& otherStack)
{
	if (this != &otherStack)
	{	
		copyMail(otherStack);
	}
	
	return *this;
};

//private method for copying stacks
void MailStack::copyMail(const MailStack& otherStack)
{
	delete[] mail; //destroy the array on heap
	this->maxStackSize = otherStack.maxStackSize;
	this->stackTop = otherStack.stackTop;

	this->mail = new std::string[maxStackSize]; //create new array on heap
	
	for(int i = 0; i < stackTop; i++)
	{
		this->mail[i] = otherStack.mail[i];
	}
};

int MailStack::getStackTop()
{
	return this->stackTop;
}

int MailStack::getMaxStackSize()
{
	return this->maxStackSize;
}
		