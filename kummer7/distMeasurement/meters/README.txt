Spencer Meyer
10/23/20
README.txt
Assignment 5
CSIS 252

This program uses input from a keyboard and outputs the other information to the screen. This program is the creation of the class Meter and using this class a test driver shows off it's methods, etc.

Input for the program is from the user. All output is to the screen.

To run the program, use the makefile within the the directory. Type "make" (without the quotes" into the terminal window and the program will be compiled. From here, type in ./prog5 in the terminal window and the program will run.

The program shows off all parts of the class. Everything can be seen from looking at the code directly, or by simply reading all of the output statements provided when running the program. The things showed off in the code/output are the default constructor, a constructor that takes in a float, a copy constructor (overloaded), getters and setters, comparisons between different instances (overloaded operators), the overloaded extraction and insertion operators, and getters for getting the unit names (both abbreviated and non-abbreviated).

The file structure and format is straight forward. I used spacing so it would be easier to follow along. I also used "========" to separate major areas that I was testing. For the most part I used cout on the stuff, but there is one time where cin is used and the user enters a float.

file		function		description
--------------------------------------------------------------
main.cpp	main			main function. This is the test
					driver of the Meter class
meter.cpp	Meter methods, etc.	implementation of the Meter class
meter.h		Meter			Meter class declaration/specification

Testing the program was simply a matter of trying every method created with the Meter class. It was simply compiling the code and making sure the correct output was given.









