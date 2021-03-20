// File: README.txt
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog9
// Modified: 11/17/20


	-[Example]-
The test file can be ran by using make test (IE: dir/$ make test)
input:
	Moderate Climb 5.10  (root)
	Easiest Climb 5.0    (n1)
	Semi Easy Climb 5.4  (n4)
	Scrambling 4.0       (n3)
	Difficult Hiking 3.0 (n5)
	Hardest Climb 5.15   (n2)
	Easy Hiking 2.0      (n6)

                               [Route Tree]
                                  5.10(root)
                               /       \
                             5.0(n1)    5.15(n2)
                           /    \       /  \
                    (n3)4.0 (n4)5.4   *    *
                       /  \     /  \
                 (n5)3.0   *   *    *
                     / \
               (n6)2.0  *
                   / \
                  *   *

Terminology: 	Explored- both the right and left branch have been traversed.
				Completely Explored- all descendants have been explored.

(PreOrder Traversal): 5.10, 5.0, 4.0, 3.0, 2.0, 5.4, 5.15
visit the left node first of every node, starting with root. Then from the last node visited goto it's right node
then visit all it's left nodes. Repeat this until every node has been traversed. A node is added upon first visit.
	1.) start at Root: add 5.10
	2.) visit Root's left node, root->n1: add 5.0
	3.) visit n1's left node, n1->n3: add 4.0
	4.) visit n3's left node, n3->n5: add 3.0
	5.) visit n5's left node, n5->n6: add 2.0
	6.) n6 is a leaf go back, n6->n5: <n6 completely explored>
	7.) n5 doesn't have a right node go back, n5->n3: <n5 completely explored>
	8.) n3 doesn't have a right node go back, n3->n1: <n3 completely explored>
	9.) visit n1's right node, n1->n4: add 5.4 <n1 explored>
	10.) n4 is a leaf go back, n4->n1: <n4 completely explored>
	11.) n1 is completely explored go back, n1->root: <n1 completely explored>
	12.) visit root's right node, root->n2: add 5.15 <root explored>
	13.) n2 is a leaf and all nodes completely explored <all nodex completely explored>

(PostOrder Traversal): 2.0, 3.0 4.0, 5.4, 5.0, 5.15, 5.10
Start traversing down the left branch of every node from root, then traverse the right brach after reaching the higest level. 
Once all of a nodes descendants are explored, it can be added.
	1.) start at root:
	2.) visit root's left node, root->n1:
	3.) visit n1's left node, n1->n3:
	4.) visit n3's left node, n3->n5:
	5.) visit n5's left node, n5->n6:
	6.) visit n6 is a leaf go back, n6->n5: add 2.0 <n6 completely explored>
	7.) n5 doesn't have a right node go back, n5->n3: add 3.0 <n5 completely explored>
	8.) n3 doesn't have a right node go back, n3->n1: add 4.0 <n3 completely explored>
	9.) visit n1's right node, n1->n4: <n1 explored>
	10.) n4 is a leaf go back, n4->n1: add 5.4 <n4 completely explored>
	11.) n1's children are explored go back, n1->root: add 5.0 <n1 completely explored>
	12.) visit root's right node, root->n2: <root explored>
	13.) n2 is a leaf go back, n2->root: add 5.15 <n2 completely explored>
	14.) root's children are explored and so are all other nodes: add 5.10 <all nodex completely explored>

(InOrder Traversal:) 2.0, 3.0, 4.0, 5.0, 5.4, 5.10, 5.15
Start traversind down the left branch from the root. When a node is explored it can be added.
	1.) start at Root:
	2.) visit Root's left node, root->n1:
	3.) visit n1's left node, n1->n3:
	4.) visit n3's left node, n3->n5:
	5.) visit n5's left node, n5->n6:
	6.) n6 is a leaf go back, n6->n5: add 2.0 <n6 completely explored>
	7.) n5 doesn't have a right node go back, n5->n3: add 3.0 <n5 completely explored>
	8.) n3 doesn't have a right node go back, n3->n1: add 4.0 <n3completely explored>
	9.) visit n1's right node, n1->n4: add 5.0 <n1 explored>
	10.) n4 is a leaf go back, n4->n1: add 5.4 <n4 completely explored>
	11.) n1 is completely explored go back, n1->root: add 5.10 <n1 completely explored>
	12.) visit root's right node, root->n2: add 5.15 <root explored>
	13.) n2 is a leaf and <all nodex completely explored>



	-[Description]-
prog9 creates route objects from user input and inserts them into a binary tree. Once the user is done
entering new routes, the program will do tree traversals and output the results.


	-[Inputs]- (input method : input type : description)
1.) keyboard : string : string entered by the user in the command prompt to create a route object.
2.) keyboard : string : declare whether or not the user wants to make more routes.
	repeat 1 and 2.


	-[Outputs]- (output method : output type : description)
1.) display : string : text displayed on monitor showing routes being created
2.) display : string : text displaying the tree traversals that were performed


	-[Design]-
This program will continously loop, prompting the user to enter a route object. After creating an object,
the user will be prompted if they want to make another and the object will be inserted into a binary tree.
At the prompt if the user enters 'Y' or 'y' the loop will continue. If they enter anything else, the loop 
will stop and the three tree traversals, PreOrder, PostOrdr, and InOrder, will be outputted to the display.


	-[Files] (file : function : description)-
main.cpp : main : executes the main line of logic

Route.cpp : Route definition : Creates the values, methods, and constructors for Route objects

userInChecks.cpp : check user input : ensure the user input is good for route creation with the
	insertion operator

prototypes.h : declarations : declares the functions to be used in Route.cpp

Route.h : declaration of Class : declares what a Route object is

binarySearchTree.h : template for child of binaryTree : declares and defines a binary tree of a specified type,
	providing additional methods to binaryTree

binaryTree.h : template for a binary tree : declares and defines a binary tree of a specified type

makefile : compilation & linking : creates and executable of prog9

README.txt : information : gives detailed information about prog9

testRoutes.txt : test user input : creates user input from a text file


	-[Testing]-
Routes have been created in the program with proper numbers within and outside the number ranges allowed by the 
Yosemite Decimal Scale. Also, routes have been made without route names and only a class and grade, which works.
Additionally, routes have been made without a class and just a grade. When that occurs, the route name is assinged
to "Void" and the class is defaulted to '5'. These values should be noted as invalid.


	-[Bugs]-
1.) the user can input bad values for grade, and get erroneous results (IE: user enters 5.55.) the extra period
	will get converted to a value not recognizable.
2.) the getFullGrade() method will output a float that doesn't necessarilly represent the real route grade based
	on the Yosemite Decimal Scale.
3.) the increment and decrement operators can be used to change route grade to values that are not
	real values based on the Yosemite Decimal Scale
4.) the setRtClass() method can set the route class to a value not real on the Yosemite Decimal Scale.

