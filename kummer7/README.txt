// File: README.txt
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog7
//Modified: 11/02/20


	-[Description]-
prog7.exe uses object orientated programming to have a base abstract class of DistMeasurement and
derived classes of Foot and Meter defined, declared, and tested. First, the user will be prompted
to choose between running a predefined test on predefined Foot and Meter objects, or defining their
own objects through a series of prompts. If the user chooses to create their own objects, after two
objects are created, they will be tested. The first object will have all its methods and operators 
tested. The second object created will be the second operand when operations of the first object are
tested.


	-[Inputs]- (input method : input type : description)
1.) keyboard : int : choice of predefined objects or user defined objects

2.) keyboard : char : type of unit the user wants to define, or exit

3.) keyboard : float then string : value of the unit followed by its name or abbreviation

	*repeat 2 and 3 until user exits


	-[Outputs]- (output method : output type : description)
1.) display : string : text displayed on monitor to prompt user and show output of the unit tests


	-[Design]-
This program will have give a choice between using predefined objects or making user defined objects.
If the user chooses to create their own objects, they will be prompted for what kind of object they
want to make. Then they will enter the value and unit name of that object to create it. Next they will
be prompted for kind of object the second object will be. Then they will enter the value and unit name
to create it. Throughout the creation of both objects, if the user enters a bad unit or chooses to exit,
the program will exit. Otherwise a unit test will be ran on the first object with the second object only
being used as the second operand in the operation tests. When the user chooses the unit type at the
prompts, that information is stored in to char variables. Those values will determine what objects will
be used in the unit test. It's possible that null pointers could be used to check for instantiation of
the objects to determine what test to use as an alternative, but that is not how this program works.
If the user decides to run the predefined tests, Foot and Meter objects will be automatically instantiated
and tested against each other.


	-[Files] (file : function : description)-
main.cpp : main : executes the main line of logic, testing derived classes

DistMeasurement.cpp : definition : Abstract base class of distance object

DistMeasurement.h : declaration : declare what the base class contains

Foot.cpp : definition : define the derived Foot class of DistMeasurement and define the virtual functions

Foot.h : declaration : declare what the derived Foot class contains

Meter.cpp : definition : define the drived Meter class of DistMeasurement and define the virtual functions

Meter.h : declarations : declare what the derived Meter class contains

unitTestTemplate.cpp : template : determines what test to run depending on whether the parameters are types
	(Meter, Meter), (Meter, Foot), (Foot, Meter), or (Foot, Foot)

makefile : compilation & linking : creates and executable of prog7

README.txt : information : gives detailed information about prog7


	-[Testing]-
Test every method, constructor, operator, and function


	-[Bugs]-
1.) When the user enters and invalid input when defining a new object, the program will return what the objects initial
	value was, which is zero if the default constructor was used.

2.) When the user is prompted to enter a unit type for object creation or 0 to exit, the user can enter any char that isn'template
	'm' or 'f' and the program will exit.

