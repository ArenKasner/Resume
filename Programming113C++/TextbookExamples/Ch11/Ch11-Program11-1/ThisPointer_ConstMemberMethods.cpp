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
 * Program: 11-1
 *
 * Solution/Project Name: Ch11-Program11-1
 *             File Name: ThisPointer_ConstMemberMethods.cpp
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
 * File Methods
 * ------------
 *  Name                             Description
 * ------  --------------------------------------------------------------------
 * main    Program entry point method
 * foo     Calls Class invariant method to display object's address and data
 *         member value (at that address).
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include "Example.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program


// Method Prototype
void foo(const Example* obj);  // Note: 

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the use of the non-static "this" pointer, which
* is the address of a Class object's first non-static data member. It is also
* the first, implicit parameter passed to a Class non-static method.
*
* The "this" pointer can only be utilized wthin Class non-static methods.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
* None
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
* Name                           Description
* ----  -----------------------------------------------------------------------
* foo   Calls Class invariant method to display object's address and data
*       member value (at that address).
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Initialized Variable Declarations
	// 1. Create a modifiable "Example" object
	Example obj1(10);
	// 2. Create a constant, "const", "Example" object
	Example const obj2(20);

	cout << "Textbook Example Program 11-1: Use of the \"this\" pointer"
		<< endl << endl;


	cout << "The addresses of the two objects are:\n"
		 << "  \"obj1\": " << &obj1 << "(hex)" << endl
		 << "  \"obj2\": " << &obj2 << "(hex)" << endl << endl;

	// Example #1: Call Class method "printAddressandValue" directly
	cout << "Example #1: Call Class method bound directly to an instance object"
		 << endl
		 << "  \"obj1\": ";
	obj1.printAddressandValue();
	cout << "  \"obj2\": ";
	obj2.printAddressandValue();
	cout << endl;


	// Example #2: Call Class method "printAddressandValue" from a pointer
	cout << "Example #2: Call Class method bound to a pointer to an instance object"
		<< endl
		<< "  \"obj1\": ";
	foo(&obj1);  // Pass a pointer to the object, "obj1"
	cout << "  \"obj2\": ";
	foo(&obj2);  // Pass a pointer to the object, "obj2"
	cout << endl;

	// Example #3: Call Class Mutator Method with allowed value
	obj1.setValue(35);
	cout << "Example #3: Call Class Mutator method, with allowed value: 35"
		<< endl
		<< "  \"obj1\": ";
	obj1.printAddressandValue();
	cout << endl;

	// Example #3: Call Class Mutator Method with invalid value
	obj1.setValue(9);
	cout << "Example #4: Call Class Mutator method, with invalid value: 9"
		<< endl
		<< "  \"obj1\": ";
	obj1.printAddressandValue();
	cout << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return 0;

}	// End Method: main()


// Method: foo(const Example*)
// Note: The method may NOT call a Class method that will modify a Class
//       data member
void foo(const Example* obj)
{
	// NOT allowed, since method receives a "const" object reference
//	obj->setValue(23);

	obj->printAddressandValue();

}	// End Method: foo(const Example*)