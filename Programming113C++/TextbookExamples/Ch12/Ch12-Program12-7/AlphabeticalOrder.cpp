/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-7
*
*
* Solution/Project Name: Ch12-Program12-7
*             File Name: AlphabeticalOrder.cpp
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
*   1.0     04/17/2015  Initial Release
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  ------------------------------------------------------------------
* Keyboard  User to enter two "names", stored in C-Style, "char" arrays
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor   Result of comparing the contents of the two C-Style, "char" arrays
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
#include <cstring>   // Defines C-Style methods
#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates the use of the C-Style method "strcmp" to determine
* if one C-Style string array is less than, greater than, or equal to another
* C-Style string array. The result of the comparison will allow the display of
* the two C-Style strings in alphabetical order. The algorithm will also detect
* if the User enters the same, indentical word twice.
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
*     Name                             Description
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 const int NAME_LENGTH = 30;

	 // Two arrays to hold two strings
	 char name1[NAME_LENGTH], name2[NAME_LENGTH];


	 cout << "Textbook Example Program 12-7:\n"
		 << "    Sorting C-Style strings" << endl << endl;


	 // Read two strings from the Console keyboard into C-Style, "char" arrays
	 cout << "Enter a name (last name first): ";
	 cin.getline(name1, NAME_LENGTH);
	 cout << "Enter another name: ";
	 cin.getline(name2, NAME_LENGTH);

	 // Print the two strings in alphabetical order
	 cout << "Here are the names sorted alphabetically:\n";
	 if (strcmp(name1, name2) < 0)
	 {	// "name1" is lexicographically smaller than "name2"
		// Display "name1" first, then "name2"
		cout << name1 << endl << name2 << endl;
	 }
	 else if (strcmp(name1, name2) > 0)
	 {	// "name2" is lexicographically smaller than "name1"
		 // Display "name2" first, then "name1"
		 cout << name2 << endl << name1 << endl;
	 }
	 else
		cout << "You entered the same name twice!\n";



	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

