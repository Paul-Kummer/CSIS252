/*
Spencer Meyer
10/23/20
main.cpp
Assignment 5
CSIS 252

This is the main program that is the test driver for the Meter class.

Preconditions: None.
Postconditions: None. The program outputs everything.
*/
#include "meter.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    //default constructor
    Meter m1;
    cout << "Default constructer: Meter m1;" << endl;
    cout << "m1.meter is zero by default using the above default constructer" << endl;
    cout << " " << endl;
    //method to set value
    m1.setMeter(1);
    cout << "m1.setMeter(1) sets the value of m1.meter to 1" << endl;
    //constructor that sets value to number in parantheses (float)
    Meter m2(5);
    cout << "Meter m2(5) declares a new meter object with a m2.meter value of 5" << endl;
    cout << " " << endl;
    
    cout << "Testing overloaded operators on between m1 and m2" << endl;
    cout << "m1.meter has the value 1" << endl;
    cout << "m2.meter has the value 5" << endl;
    cout << " " << endl;
    cout << "Testing overloaded equals operator" << endl;
    
    cout << "m1 != m2?" << endl;
    if(m1 == m2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded does not equal operator" << endl;
    cout << "m1 != m2?" << endl;
    if(m1 != m2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded greater than operator" << endl;
    cout << "m1 > m2?" << endl;
    if(m1 > m2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded less than operator" << endl;
    cout << "m1 < m2?" << endl;
    if(m1 < m2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded greater than or equal to operator" << endl;
    cout << "m1 >= m2?" << endl;
    if(m1 >= m2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    cout << "Testing overloaded less than or equal to operator" << endl;
    cout << "m1 <= m2?" << endl;
    if(m1 <= m2){
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
    //new Meter object m3
    Meter m3;
    //m3 extracted from keyboard
    cin >> m3;
    
    cout << "Testing insertion operator on previously entered number" << endl;
    //outputting m3 using insertion operator
    cout << m3 << endl;
    
    cout << "===========================" << endl;
    
    //default constructor
    //value is zero by default
    Meter m4;
    cout << "Testing getMeter method on newly created m4 object with value of zero" << endl;
    cout << "The code: m4.getMeter();" << endl;
    cout << m4.getMeter() << endl;
    cout << " " << endl;
    
    cout << "Testing setMeter method on m4 with a value of 20" << endl;
    cout << "The code: m4.setMeter(20);" << endl;
    m4.setMeter(20);
    cout << " " << endl;
    
    cout << "Testing getMeter method again with update valued" << endl;
    cout << "The code: m4.getMeter();" << endl;
    cout << m4.getMeter() << endl;
    cout << " " << endl;
    
    //new meter object m5 for testing with m5.meter value of 1
    Meter m5(1);
    cout << "Testing getUnitAbbreviation method on newly created m5 with value of 1" << endl;
    cout << "The code: m5.getUnitAbbreviation();" << endl;
    cout << m5.getUnitAbbreviation() << endl;
    cout << " " << endl;
    
    cout << "Testing getUnitFullName method on m5" << endl;
    cout << "The code: m5.getUnitFullName();" << endl;
    cout << m5.getUnitFullName() << endl;
    cout << " " << endl;
    
    cout << "Testing getUnitFullName method on m4" << endl;
    cout << "The code: m4.getUnitFullName();" << endl;
    cout << m4.getUnitFullName() << endl;
    cout << " " << endl;
    
    cout << "===========================" << endl;
    //constructing two more meter objects
    Meter m6(500);
    Meter m7(20);
    cout << "m6 and m8 meter objects are created" << endl;
    cout << "m6.meter has the value 500" << endl;
    cout << "m7.meter has the value 20" << endl;
    cout << " " << endl;
    
    //assigning m7 the value of m6 using overloaded assignment operator
    m7 = m6;
    
    cout << "Outputting the value of m7 after using overloaded assignment operator (m7 = m6)" << endl;
    //returns 500 and not 20 because m7 was assigned to m6
    cout << m7;
    cout << " " << endl;

    //overloaded copy constructer copying the information from the m8 object
    //into the m9 object
    Meter m8(m7);
    cout << "Outputting the value of m8 which was created by using an overloaded copy constructer and having the parameter of m6. 500 should be returned." << endl;
    cout << "The code: Meter m8(m7);" << endl;
    cout << m8;
    
    return 0;
}
