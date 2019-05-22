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
* Program: 11-20
*
* Solution/Project Name: Ch11-Program11-20
*             File Name: SequenceConstructorsDestructors.cpp
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
*   1.0     04/10/2015  Initial Release
*
* UDTs Utilized
*--------------
*    Name                                     Description
* ----------  -------------------------------------------------------------------
* BaseDemo    Base Class, containing just a Constructor and a Destructor
* ChildDemo   Child Class, containing just a Constructor and a Destructor
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
#include "ChildDemo.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the sequence of invocation of Class Constructors
* when an object of a derived, "Child", Class is instantiated. It will
* demonstrate that the Base Class Constructor is invoked before ANY of the
* code in the "Child" Class Constructor is executed. This is accomplshed by
* having just a display statement in each class' Default Constructor. This
* sequence will ensure that the Base Class data members are (should be)
* initialized first, thus allowing them to be used, if need be, during the
* initialization of the "Child" class' non-static data members.
*
* In addition, using the same technique of display statements, the sequence of
* the invocation of the Class Destructors is demonstrated, showing that the
* "Child" Class Destructor code executes first, followed by the code in the
* "Base" Class Destructor.
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


	cout << "     Textbook Example Program 11-20:\n"
		<< "Order of Constructor/Destructor invocations" << endl << endl;


	cout << "We will now create a \"ChildDemo\" object.\n";
	ChildDemo object;

    cout << "\nThe program is now going to end.\n";


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()