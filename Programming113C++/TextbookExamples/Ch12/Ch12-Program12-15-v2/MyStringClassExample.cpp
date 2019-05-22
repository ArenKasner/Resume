/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-15
*
* Solution/Project Name: Ch12-Program12-15-v2
*             File Name: MyStringClassExample.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/26/2015  Initial Release
*
*
* Program Inputs
* --------------
* None
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   1. Several examples of the C-Style "strcmp" method
*           2. Result of the C-Style "strcat" method
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"    // Defines IDE required external definition files
#include <iostream>    // Defines objects and classes used for stream I/O
#include "MyString.h"  // Defines Class: MyString (simulates C++ "string" class)

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the functionality of a Class that encapsulates
* a string of characters along with methods that provide useful operations
* with a string of characters. The Class, "MyStrng", simulates some of the
* features of the built-in, C++ class, "string".
*
* This program will demonstrate the ability to create a "MyString" object
* using three different Constructors and the use of the overloaded shortcut
* Addition/Assignment Operator.
*
* This version of the program displays messages indicating when each of the
* two Constructors, the class Copy Constructor, and the class Destructor are
* called as objects are instantiated and expressions utilizing the overloaded
* Assignment and Addition Operators on the various "MyString" objects are
* invoked in "main()". There is no difference in the code of this file compared
* to the 1st version of the program, as the messages are added to the "MyString"
* class Constructors, Copy Constructor, and Destructor.
*
*
* Pre-Conditions
* --------------
* None
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Vlaue Declarations
	const int NO_ERRORS = 0;

	// Variable, UDT objects
	MyString object1("This");
	MyString object2("is");
    MyString object3("a test.");
    MyString object4 = object1;  // Call copy constructor
    MyString object5("is only a test.");
	MyString object6;   // Call Default Constructor
	MyString object7;   // Call Default Constructor

	// Variable, C-String array
    char string1[] = "a test.";


	cout << "Textbook Example Program 12-15:\n"
		<< "  \"MyString\" Class Example" << endl << endl;


	cout << "The instantiated objects:" << endl;
	cout << "  object1: \"" << object1 << '\"' << endl;
	cout << "  object2: \"" << object2 << '\"' << endl;
	cout << "  object3: \"" << object3 << '\"' << endl;
	cout << "  object4: \"" << object4 << '\"' << endl;
	cout << "  object5: \"" << object5 << '\"' << endl;
	cout << "  object6: \"" << object6 << '\"' << endl;
	cout << "  object7: \"" << object7 << '\"' << endl;
	cout << "  string1: \"" << string1 << '\"' << endl;

	cout << "\nExample #1: Concatenate \" \" to \"object1\"" << endl;
    object1 += " ";
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #2: Concatenate \"object2\" to \"object1\"" << endl;
	object1 += object2;
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #3: Concatenate a 2nd \" \" to \"object1\"" << endl;
	object1 += " ";
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #4: Concatenate a 3rd \" \" to \"object1\"" << endl;
	object1 += " ";
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #5: Concatenate \"object3\" to \"object1\"" << endl;
	object1 += object3;
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #6: Concatenate a 4th \" \" to \"object1\"" << endl;
	object1 += " ";
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #7: Concatenate \"object4\" to \"object1\"" << endl;
	object1 += object4;
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #8: Concatenate a 5th \" \" to \"object1\"" << endl;
	object1 += " ";
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #9: Concatenate \"object5\" to \"object1\"" << endl;
	object1 += object5;
	cout << "  object1: \"" << object1 << "\"" << endl;

	cout << "\nExample #10: Concatenate \"object5\" to \"object4\"" << endl;
	object6 = object4 + object5;
	cout << "  object6: \"" << object6 << "\"" << endl;

	cout << "\nExample #10: Concatenate \"object5\" to \"object4\"" << endl;
	object6 = object4 + object5;
	cout << "  object6: \"" << object6 << "\"" << endl;

	cout << "\nExample #11: Concatenate \"object5\" to \"object4\"" << endl;
	object6 = object4 + " " + object5;
	cout << "  object6: \"" << object6 << "\"" << endl;

	cout << "\nExample #12: Concatenate \"object6\" to \"Don't worry. \"" << endl;
	object7 = "Don't worry. " + object6;
	cout << "  object7: \"" << object7 << "\"" << endl;

	cout << "\nExample #13: Concatenate \"object6\" to \"Don't worry. \""
		 << "\n             (Without assignment)" << endl;
	cout << "Don't worry. " + object6 << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()