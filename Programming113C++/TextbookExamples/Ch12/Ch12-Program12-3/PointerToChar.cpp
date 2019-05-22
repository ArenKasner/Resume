/******************************************************************************
 * Bellevue Class: PROG 113
 *     Instructor: Robert Main
 *
 * Textbook Example Program
 * Chapter: 12
 * Program: 12-3
 *
 * Solution/Project Name: Ch12-Program12-3
 *             File Name: PointerToChar.cpp
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
 *   1.0     04/16/2105  Initial Release
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  User enters a "string" processed by the "istream" method "getline"
 *           that receives a pointer to an array of "char".
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   Display the "char" array with characters entered by the User
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

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates that a dynamically allocated array of type "char"
* elements can receive a "string" from the "istream" method "getline". This
* example demonstrates that the "istream" method "getline" takes an argument
* of type "char*", whether the array is statically allocated (at compile time)
* or whether the "char" array is dynamically allocated at run time.
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
	 // Constant "const" Value Declarations
	 const int NO_ERRORS = 0;     // Program Execution Status: No errors
	 const int NAME_LENGTH = 50;  // Maximum length of name as a "string"

	 // Initialized Variable Declaration
	 char* pntrToName = NULL;  // Pointer: Not initialized yet (dynamic allocation)
	 char name[NAME_LENGTH];   // Statically declared array
	 char* pntr = name;


	 cout << "Textbook Example Program 12-3:\n"
		 << "      Pointer to \"char\"" << endl << endl;


	 // Dynamically allocate the array, "pntrToName"
	 cout << "Dynamically allocate the array of \"char\" values" << endl;
	 pntrToName = new char[NAME_LENGTH + 1];  // Allow for the required '\0', "char"
	 cout << "  Array allocated, size: " << NAME_LENGTH + 1 << " \"char\"s" << endl;

	 cout << "\nExample 1A: Enter a sequence of \"char\"s into a dynamically allocated array"
		  << "\n  Enter your full name: ";
	 cin.getline(pntrToName, NAME_LENGTH);
	 cout << "Example 1B: Display the contents of the \"char\" array" << endl;
	 cout << "  Hello " << pntrToName << endl;

	 cout << "\nExample 2A: Enter a sequence of \"char\"s into a static array"
		 << "\n  Enter another name: ";
	 cin.getline(name, NAME_LENGTH);
	 cout << "Example 2B: Display \"char\" array, specifying name of array" << endl;
	 cout << "  Hello " << name << endl;
	 cout << "Example 2C: Display \"char\" array, specifying a pointer to the array" << endl;
	 cout << "  Hello " << pntr << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

