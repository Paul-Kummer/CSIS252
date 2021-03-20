// File: README.txt
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog5
// Modified: 10/21/20


	-[Description]-
prog5 will test methods and instantiation of objects of class LightYear.


	-[Inputs]- (input method : input type : description)
1.) keyboard : string : string entered by the user in the command prompt to create a LightYear object.


	-[Outputs]- (output method : output type : description)
1.) display : string : text displayed on monitor showing tests being ran on objects


	-[Design]-
This program will instantiate a LightYear object with
	*default constructor
	*parameter constructor with various values
	*copy constructor
Then it will test the object methods
	*getNumber(), retrieves float value
	*getName(), retrieves name of unit
	*getType(), retrieves the kind of measurment
	*getAbbr(), retrieves the abbreviated label
	*setNumber(), changes the number value of the object
Next, operators on LightYear objects will be tested. They include
	*assignment operator =
	*addition operator +
	*subtraction operator -
	*division operator /, including division by zero
	*preincrement operator ++value
	*predecrement operator --value
	*postincrement operator value++
	*postdecrement operator value--
	*less than operator <
	*greater than operator >
	*equal to operator ==
	*not equal to operator !=
	*less than or equal to operator <=
	*greater than or equal to operator >=
Finally, the LightYear's extraction operator will be tested by prompting
the user to create a new light year object. Throughout this program the
insertion operator will be used to display results.


	-[Files] (file : function : description)-
main.cpp : main : executes the main line of logic

LightYear.cpp : LightYear definition : Creates the values, methods, and constructors for LightYear objects

printTest.cpp : printOperations, printResult, and printTest : show what test is being
	ran, and the results of the test.

prototypes.h : declarations : declares the functions to be used in the program

LightYear.h : declaration of Class : declares what a LightYear object is

makefile : compilation & linking : creates and executable of prog3

README.txt : information : gives detailed information about prog3


	-[Testing]-
*see design


	-[Bugs]-
1.) During compilation, there is a warning about a null pointer to a LightYear object.

