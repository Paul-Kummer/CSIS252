// File: main.cpp
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog9
// Modified: 11/17/20

#include <iostream>
#include <iomanip>
#include <string>
#include "Route.h"
#include "binarySearchTree.h"
#include "binaryTree.h"

/*
Description:
This is the main line of logic for the program, it will ask the user to input information for new routes
and exit if the user doesn't say they want to make more routes. Upon the exit condition, three tree
traversals will be performed PreOrder, PostOrder, and InOrder.
*/

using namespace std;

int main()
{
	// variables
	Route userInput;
	string another = "Y";
	bool continueInput = true;
	bSearchTreeType<Route> routeTree;

	// program description
	cout << string(100, '*') << endl;
	cout << "                          -- Binary Tree of Climbing Routes --                        " << endl;
	cout << string(100, '*') << endl;
	cout << "This program will create a binary tree of class Route, which represnts climbing routes" << endl;
	cout << "Each route created will be assigned a value based on the Yosemite Decimal Scale (YDS) " << endl;
	cout << "The YDS has two key components of class and grade. First the class is listed, then a  " << endl;
	cout << "period followed by the grade behind the period. For technical climbing, the class will" << endl;
	cout << "always be five, which is considered technical climbing on a steep enough face where   " << endl;
	cout << "serious injury or death is likely should a climber fall wihout appropriate            " << endl;
	cout << "protective equipment                                                                  " << endl;
	cout << endl;
	cout << "The program will rank routes based upon a combination of class and grade. A 5.1 route " << endl;
	cout << "is considered less than a 5.10 and a 4.14, if possible, would be considered less than " << endl;
	cout << "5.1 and 5.10. To accomplish this, the program will divide the grade by 100 and add it " << endl;
	cout << "to the integer value of the class. Therefore, for comparison, a 5.1 would be considerd" << endl;
	cout << "5.01 and 5.10 would be 5.1.                                                           " << endl;
	cout << string(100, '*') << endl << endl;
	cout << "Example input: 5.10, 5.1, 5.4, 4.0, 3.0, 5.11, 2.0                                    " << endl;
	cout << endl;
	cout << "                               [Route Tree]                                           " << endl;
	cout << "                                  5.10                                                " << endl;
	cout << "                               /       \\                                             " << endl;
	cout << "                             5.1        5.11                                          " << endl;
	cout << "                           /  \\        /  \\                                         " << endl;
	cout << "                        4.0     5.4   *    *                                          " << endl;
	cout << "                       /  \\    /  \\                                                 " << endl;
	cout << "                     3.0   *  *     *                                                 " << endl;
	cout << "                     / \\                                                             " << endl;
	cout << "                   2.0  *                                                             " << endl;
	cout << "                   / \\                                                               " << endl;
	cout << "                  *   *                                                               " << endl;
	cout << "  PreOrder Traversal: 5.10, 5.1, 4.0, 3.0, 2.0, 5.4, 5.11                             " << endl;
	cout << "  PostOrder Traversal: 2.0, 3.0 4.0, 5.4, 5.1, 5.11, 5.10                             " << endl;
	cout << "  InOrder Traversal: 2.0, 3.0, 4.0, 5.1, 5.4, 5.10, 5.11                              " << endl;
	cout << endl << endl << endl;


	// ask the user to input information for routes to be added to tree
	cout << "\t-Enter Routes to Add to Tree-" << endl;
	do
	{
		cin.clear(); // clear the input stream
		cin >> userInput; // get the route information inputted
		routeTree.insert(userInput); // put the route into the tree
		cout << "the route created is: " << userInput << " ----> Do Another (Y/y = yes): "; // ask if they want to add more routes
		cin.clear();
		std::getline(std::cin, another);
		cout << endl;

		// exit route creation if the user doesn't explicitly say they want to do more
		if (!(another[0] == 'Y' || another[0] == 'y') || another.empty()) //
		{
			continueInput = false;
		}
	} while (continueInput);
	
	cout << endl << "[inorder traversal]" << endl;
	routeTree.inorderTraversal();
	cout << endl << "[preorder traversal]" << endl;
	routeTree.preorderTraversal();
	cout << endl << "[postorder traversal]" << endl;
	routeTree.postorderTraversal();


   return 0;
}


