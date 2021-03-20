/*
Kai Yodoya
10/23/20
main.cpp
Assignment 5
CSIS 252

This is the main program that is the test driver for the Foot class.

Preconditions: None.
Postconditions: None. The program outputs everything.
*/
#include "foot.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    //default constructor
    Foot f1;
    cout << "Default constructer: Foot f1;" << endl;
    cout << "f1.foot is zero by default using the above default constructer" << endl;
    cout << " " << endl;
    //method to set value
    f1.setFoot(1);
    cout << "f1.setFoot(1) sets the value of f1.foot to 1" << endl;
    //constructor that sets value to number in parantheses (float)
    Foot f2(5);
    cout << "Foot f2(5) declares a new foot object with a f2.foot value of 5" << endl;
    cout << " " << endl;
    
    cout << "Testing overloaded operators on between f1 and f2" << endl;
    cout << "f1.foot has the value 1" << endl;
    cout << "f2.foot has the value 5" << endl;
    cout << " " << endl;
    cout << "Testing overloaded equals operator" << endl;
    
    cout << "f1 == f2?" << endl;
    if(f1 == f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded does not equal operator" << endl;
    cout << "f1 != f2?" << endl;
    if(f1 != f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded greater than operator" << endl;
    cout << "f1 > f2?" << endl;
    if(f1 > f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded less than operator" << endl;
    cout << "f1 < f2?" << endl;
    if(f1 < f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded greater than or equal to operator" << endl;
    cout << "f1 >= f2?" << endl;
    if(f1 >= f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded less than or equal to operator" << endl;
    cout << "f1 <= f2?" << endl;
    if(f1 <= f2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    cout << " " << endl;
    cout << "===========================" << endl;
    
    
    cout << "Testing overloaded insertion << and extraction >> operators" << endl;
    cout << " " << endl;
    cout << "Testing extraction operator" << endl;
    
    cout << "Enter an amount of meters" << endl;
    //new Foot object f3
    Foot f3;
    //f3 extracted from keyboard
    cin >> f3;
    
    cout << "Testing insertion operator on previously entered number" << endl;
    //outputting f3 using insertion operator
    cout << f3 << endl;
    
    cout << "===========================" << endl;
    
    //default constructor
    //value is zero by default
    Foot f4;
    cout << "Testing getFoot method on newly created f4 object with value of zero" << endl;
    cout << "The code: f4.getFoot();" << endl;
    cout << f4.getFoot() << endl;
    cout << " " << endl;
    
    cout << "Testing setFoot method on f4 with a value of 20" << endl;
    cout << "The code: f4.setFoot(20);" << endl;
    f4.setFoot(20);
    cout << " " << endl;
    
    cout << "Testing getFoot method again with update valued" << endl;
    cout << "The code: f4.getFoot();" << endl;
    cout << f4.getFoot() << endl;
    cout << " " << endl;
    
    //new foot object f5 for testing with f5.foot value of 1
    Foot f5(1);
    cout << "Testing getUnitAbbreviation method on newly created f5 with value of 1" << endl;
    cout << "The code: f5.getUnitAbbreviation();" << endl;
    cout << f5.getUnitAbbreviation() << endl;
    cout << " " << endl;
    
    cout << "Testing getUnitFullName method on f5" << endl;
    cout << "The code: f5.getUnitFullName();" << endl;
    cout << f5.getUnitFullName() << endl;
    cout << " " << endl;
    
    cout << "Testing getUnitFullName method on f4" << endl;
    cout << "The code: f4.getUnitFullName();" << endl;
    cout << f4.getUnitFullName() << endl;
    cout << " " << endl;
    
    cout << "===========================" << endl;
    //constructing two more foot objects
    Foot f6(500);
    Foot f7(20);
    cout << "f6 and f7 foot objects are created" << endl;
    cout << "f6.foot has the value 500" << endl;
    cout << "f7.foot has the value 20" << endl;
    cout << " " << endl;
    
    //assigning f7 the value of f6 using overloaded assignment operator
    f7 = f6;
    
    cout << "Outputting the value of f7 after using overloaded assignment operator (f7 = f6)" << endl;
    //returns 500 and not 20 because f7 was assigned to f6
    cout << f7;
    cout << " " << endl;

    //overloaded copy constructer copying the information from the f8 object
    //into the f9 object
    Foot f8(f7);
    cout << "Outputting the value of f8 which was created by using an overloaded copy constructer and having the parameter of f6. 500 should be returned." << endl;
    cout << "The code: Meter f8(f7);" << endl;
    cout << f8;
    
    return 0;
}
