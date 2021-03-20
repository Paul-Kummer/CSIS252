// File: README.txt
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog3
// Modified: 9/30/20


	-[Description]-
prog3.exe takes information of units and their types from a text file and then allows the user to
enter the units from the text file in a command prompt to figure out if they are compatabile with 
each other.


	-[Inputs]- (input method : input type : description)
1.) command line argument arg[1] : text file : file containing strings that will be used at units
	and their type of measurment.

2.) keyboard : string : string entered by the user in the command prompt to select a unit or exit 


	-[Outputs]- (output method : output type : description)
1.) display : string : text displayed on monitor to let the user know if their units are compatible


	-[Design]-
This program will go line by line in a text file and place the first element before a comma into a 
string array of units. Then the item after the comma will be placed into a string array of unit types.
These two arrays will be parallel arrays. When the user types in string data for determining compatibility
of two units, the program will do one linear search through the unit array to determine the unit type for
each value. Once each unit has had it's unit type set by the value in the index or to nothing, the two 
values are compared. If the values are the same, excluding no value, they will be said to be compatible.


	-[Files] (file : function : description)-
main.cpp : main : executes the main line of logic

PopulateArraysFromFile.cpp : PopulateArraysFromFile : extracts strings of units and types and puts 
	them into corresponding parallel arrays

PrintUnits.cpp : PrintUnits : displays the current units available in the unit array

UnitCompatible.cpp : UnitCompatible : determines if two units can be converted to one another

constants.h : declarations : declares the const of array size for parallel arrays

prototypes.h : declarations : declares the functions to be used in the program

makefile : compalation & linking : creates and executable of prog3

units.txt : unit values : determines the units that are available for comparison in prog3

README.txt : information : gives detailed information about prog3


	-[Testing]-
Test with file of no strings
Test with file with multiple commas per line
Test with many command line arguments
Test with no command line arguments
Test capitalization of user inputs
Test user inputs not in array
Test user inputs in array
Test both user inputs being the same
Test user inputs being different units of same type
Test user inputs being different units of different type


	-[Bugs]-
1.) When two units that are not part of the text file are entered, the program will say they are incompatible
	no matter what.

