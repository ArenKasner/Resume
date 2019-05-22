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
* Program: 11-7
*
* Solution/Project Name: Ch11-Program11-7
*             File Name: DefaultConstructorIssue.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
*
* UDTs Utilized
*--------------
*     Name                                 Description
* ------------  ---------------------------------------------------------------
* NumberArray   Example Class that does NOT provides an overridden Copy 
*               Constructor or an overriden Assignment Operator.
*
*
* File Methods
* ------------
*      Name                             Description
* --------------  -------------------------------------------------------------
* main            Program entry point method
* displayObject   Display of a "NumberArray" object's array contents
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "NumberArray.h"   // Class Definition: NumberArray

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program


// Method Prototypes
void displayObject(NumberArray& object, string);


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the issue of relying on the compiler supplied,
* Default Copy Constructor, when the class contains a pointer that has been
* initialized with an address obtained using the "new" Operator to dynamically
* allocate memory for an object or array from the Heap Memory Manager.
*
* The example consists of creatinf two UDT objects, which contain a pointer
* to "double" for an array that is dynmaically allocated when the Class
* Initializing Constructor is invoked. The second object is instantiated by
* invoking the compiler's Default Copy Constructor, which has the first
* object passed, by reference, to the Copy Constructor.
*
* A method of the example Class, "NumberArray" RETurns the address of the
* "double" array data member of the class; the data member being a pointer to
* "double". The address of each object's array will be the same, as the
* compiler's supplied Default Copy Constructor simply copies all non-static
* data members from the source object to the newly instantiated object.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                       *** No Arguments Defined ***
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
*      Name                             Description
* --------------  -------------------------------------------------------------
* displayObject   Display of a "NumberArray" object's array contents
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Create an object
	NumberArray one(3, 10.5);
  
	// Make a copy of the object, using the compiler's Default Copy Constructor
	NumberArray two(one);


	cout << "Textbook Example Program 11-7: Copy Constructor - Part 2\n"
		 << " Default Copy Constructor and Dynamic Memory Allocation\n"
		 << "  Issue: Array pointer copied, NO unique array memory!" << endl << endl;


	cout << setprecision(2) << fixed << showpoint;

	// Display the values of the two objects
	cout << "Objects \"one\" and \"two\" as instantiated:" << endl;
	displayObject(one, "one");
	displayObject(two, "two");
	cout << "And now the addresses of the array within each object:" << endl;
	cout << "  one.arrayPntr: " << one.arrayAddress() << "(hex)" << endl;
	cout << "  two.arrayPntr: " << two.arrayAddress() << "(hex)" << endl;

	// Now change the  value stored in the second object
	cout << "\nOnly the values in object \"second\" will be changed:" << endl;
	two.setValue(20.5);
  
	// Display the values stored in the two objects
	displayObject(one, "one");
	displayObject(two, "two");


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


void displayObject(NumberArray& object, string name)
{
	cout << "  Values stored in object \"" << name << "\":";
	object.print();
	cout << endl;

}	// End Method: displayObject(NumberArray&,string)