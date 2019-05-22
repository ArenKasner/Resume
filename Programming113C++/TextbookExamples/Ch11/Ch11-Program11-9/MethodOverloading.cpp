/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook: Starting Out With C++: Early Objects
*  Authors: Tony Gaddis, Judy Walters, and Godfrey Muganda
*  Edition: 8th
*
* Textbook Example Program
* Chapter: 11
* Program: 11-9
*
* Solution/Project Name: Ch11-Program11-9
*             File Name: MethodOverloading.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     04/01/2015  Initial Release
*
* UDTs Utilized
*--------------
*     Name                                     Description
* ------------  ---------------------------------------------------------------
* NumberArray   Example Class that provides an overridden Copy Constructor and
*               an overriden Assignment Operator.
*
*
* File Methods
* ------------
*  Name                             Description
* ------  --------------------------------------------------------------------
* main    Program entry point method
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "NumberArray.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates overloading the compiler supplied default Copy
* Constructor and the Assignmentt Operator. Overloading these methods is
* MANDATORY if the Class contains non-static data members that are pointers
* to dynamically allocated Class objects or arrays, since a "deep" copy of the
* Class members or the array elements are necessary in both cases, 1) A Class
* object is instantiated as a copy of another Class object, or 2) A Class
* object is assigned to another Class object.
*
* It should be noted that the Copy Constructor MUST be overloaded even if no
* no objects are created as a copy of another object. The reason is that a
* Cilent may pass a Class object to a method by VALUE, and the Assignment
* Operator RETurns a copy of its "lValue" object in order to support Assignment
* chaining.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ------------------------------------------------
*                       *** No Arguments Defined ***
*
*
* Return Value
* ------------
* Type                              Description
* ----  ---------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
* None
*
***************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Declare and initialize 5 Class objects
	NumberArray first(3, 10.5);   // Call Initializing Constructor
	NumberArray second(5, 20.5);  // Call Initializing Constructor
	NumberArray third(second);    // Call Copy Constructor
	NumberArray fourth;           // Call Default Constructor (No array allocated)
	NumberArray fifth(4, 91.23);  // Call Initializing Constructor

	// Declare, but do not initialize, 3 class objects to demonstrate
	// Assignment "chaining".
	NumberArray six;
	NumberArray seven;
	NumberArray eight;


	cout << "           Textbook Example Program 11-9:\n"
		 << "Overridden Copy Constructor and Assignment Operator" << endl << endl;


	// Display the values of the three objects
	cout << setprecision(2) << fixed << showpoint;
	cout << " First object's data is ";
	first.print();
	cout << endl << "Second object's data: ";
	second.print();
	cout << endl << " Third object's data: ";
	third.print();
	cout << endl << "Fourth object's data: ";
	fourth.print();
	cout << endl << " Fifth object's data: ";
	fifth.print();
	cout << endl;

	// Invoke the overloaded Assignment Operator: Assign to an existing array
	cout << "\nNow assign object \"second\" to object \"first\"." << endl;
	first = second;          
	// Invoke the overloaded Assignment Operator: Assign to an "empty" array
	cout << "And assign object \"fifth\" to object \"fourth\"." << endl;
	fourth = fifth;

	// Display the new values of the two objects
	cout << " First object's data: ";
	first.print();
	cout << endl << "Second object's data: ";
	second.print();
	cout << endl << "Fourth object's data: ";
	fourth.print();
	cout << endl;

	// Now set all of object "first" elements to the original value
	cout << "\nFinally, set all of object \"first\" elements to the original value, 10.5"
		 << endl;
	first.setValue(10.5);

	// Now display the elements in both objects
	cout << "Displaying array elements in objects \"first\" and \"second\".\n"
		 << "Note that the array in object \"second\" is NOT modified!" << endl;
	cout << " First object's data: ";
	first.print();
	cout << endl << "Second object's data: ";
	second.print();
	cout << endl;

	// Demonstrate Assignment "Chaining"
	cout << "\nDemonstration of Assignment \"chaining\"" << endl;
	cout <<   "   Object \"six\": ";
	six.print();
	cout << "\n Object \"seven\": ";
	seven.print();
	cout << "\n Object \"eight\": ";
	eight.print();
	cout << "\nObject \"second\": ";
	second.print();
	cout << endl;
	cout << "\nAssignment statement: six = seven = eigtht = second;\n" << endl;
	six = seven = eight = second;
	cout << "   Object \"six\": ";
	six.print();
	cout << "\n Object \"seven\": ";
	seven.print();
	cout << "\n Object \"eight\": ";
	eight.print();
	cout << "\nObject \"second\": ";
	second.print();
	cout << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()