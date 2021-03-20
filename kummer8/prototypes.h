// File: prototypes.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/12/20

#pragma once
#include "mailQueue.h"
#include "mailStack.h"

/*
Description:
Declarations of functions used in the main program
*/

void morningRoutine(MailQueue&, MailStack&, MailStack&);
std::string whenever(MailStack&);
void mailPerson(MailStack&);
void dump(MailQueue&, MailStack&, MailStack&);