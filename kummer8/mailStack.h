// File: mailStack.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/11/20

#pragma once
#include <iostream>
#include <string>

class MailStack
{
	public:
		MailStack(); //default constructor
		MailStack(int); //parameter constructor
		MailStack(const MailStack&); //copy constructor
		~MailStack(); //destructor
		void initStack(); //set default values
		bool isEmpty(); //check if stack is empty
		bool isFull(); //check if stack is full
		void push(std::string); //put an item onto the top of stack
		std::string top(); //see the item on the top of stack
		std::string pop(); //remove the item from the top of stack
		const MailStack& operator=(const MailStack&); //assignment operator
		int getStackTop();
		int getMaxStackSize();

	private:
		int maxStackSize; //how big the stack can be
		int stackTop; //position of the the top of the stack
		std::string* mail; //array of string items

		void copyMail(const MailStack&); //private method for copying items
};