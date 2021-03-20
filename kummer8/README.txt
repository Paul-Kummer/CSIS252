// File: README.txt
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog8
// Modified: 11/24/20

*** [UPDATE] ***
The last version of this program had one curly brace facing the wrong direction, that somehow
got saved and pushed to the server after I had compiled successfully. I changed the curly brace
to what it should be, and now it works fine.


	-[Description]-
prog8.exc uses stacks and queues to manage a virtual mail quarentine system. The user will be
prompted to take an action of adding mail to driveway mailbox, adding items to queue and cycling
the queue, viewing an item out of the queue, or extracing all data from everything. All mail will
be represented as a string. A stack will be multiple mail items on top of each other. The queue 
will be a representation of six quarentine boxes. Before and after quarentine will be stacks that
mail items are added to until they are popped off.


	-[Inputs]- (input method : input type : description)
1.) keyboard : int : choice of action to preform

2.) keyboard : string : enter mail into mailbox at driveway

	*repeat 1 unless #2 is selected then repeat 1 and 2


	-[Outputs]- (output method : output type : description)
1.) display : string : text displayed on monitor to prompt user and show output of the unit tests


	-[Design]-
This program will give choices to do the morning routine, which cycles and adds stacks to the queue;
mailperson, which adds a string to the driveway stack; whenever, which extracts strings from the home
stack; dump, which shows the contents of all stacks, even in the queue; and exit, which close the
program. The main queue will be initialzied with 6 empty stacks that cycle over each other using the
modulo operator. Each of the stacks will be populated with strings by copying a stack with the addQueue
method. There is a possibility that some problems could occur if the stacks reach their maximum size,
which defaults to 100.


	-[Files] (file : function : description)-
main.cpp : main : executes the main line of logic, performing actions with stacks and queues

mainFunctions.cpp : definition : group of functions used in the main function

prototypes.h : declaration : declare what the main functions are

mailStack.cpp : definition : define what is required for a stack of mail, which are strings

mailStack.h : declaration : declare what a mail stack is

mailQueue.cpp : definition : define the a mail queue is and how to add stacks to it

mailQueue.h : declarations : declare what a mail queue is

constants.h : constants : constant value for declaring array size, may be unneccesary

unused : folder : files for inital way that I wanted to design the program before reviewing more material

README.txt : information : gives detailed information about prog8


	-[Testing]-
The program has been tested with empty conditions, but has not been tested with stacks exceeding their maximum values


	-[Bugs]-
1.) If a queue count somehow progresses far enough the front and rear could become the same index because of the used
	of the modulo operator. Also, if the program is ran for a very long time, the count could exceed the value allowed
	by an int.

