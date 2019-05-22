/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-14
*
*
* Solution/Project Name: Ch12-Program12-14
*             File Name: stringClassConstructors.cpp
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
* --------  ----------  ------------------------------------------------------
*   1.0     04/18/2015  Initial Release
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
* --------  ------------------------------------------------------------------
* Monitor   1. Greeting using two created "string" objects
*           2. Same greeting with first displayed object the result of a
*              "chained" Assignment to the same C-String as the first object
*              in the first greeting message.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* main          Program entry point method
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>    // Defines Class: string

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates two of the "string" Class Constructors, 1) The
* Default Constructor, and 2) A Conversion Constructor that converts a C-String
* array of "NULL" terminated "char"s to a "string" object.
*
* In addition, the overloaded Assgnemnt Operator for the class is demonstrated
* along with the "string" Class Copy Constructor.
*
* Pre-Conditions
* --------------
* None
*
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

	 string greeting1;               // Default constructor invoked
	 string greeting2;               // Default constructor invoked
	 string name("William Smith");   // Convert constructor invoked


	 cout << "          Textbook Example Program 12-14:\n"
		  << "\"string\" Class Constructors and Assignment Operator" << endl << endl;


	 // Assign the C-String, literal string to the "string" objects "greeting1"
	 // and "greeting2". This one statement demonstrates, 1) The Conversion
	 // Constructor to convert the literal C-String "Hello " to a "string"
	 // object, 2) The overloaded Assignment Operator, and 3) The "string"
	 // Class Copy Constructor to RETurn a "string" object from the Assignment
	 // Operator in order to support Assignment "chaining".
	 cout << "Assigning literal C-String \"Hello \" to \"string\"\n"
		  << "objects \"greeting1\" and \"greeting2\" in one statement" << endl;
	 greeting2 = greeting1 = "Hello ";

	 cout << "\nDisplay full greetings:" << endl;
	 cout << "  Using \"greeting1\": " << greeting1 << name << endl;
	 cout << "  Using \"greeting2\": " << greeting2 << name << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()

