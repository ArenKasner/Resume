/******************************************************************************
 * Bellevue Class: PROG 113
 *     Instructor: Robert Main
 *
 * Solution/Project Name: Ch12-Program12-2
 *             File Name: CharacterArray.cpp
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Textbook Program Example
 * Chapter: 12
 * Program: 12-2
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     04/15/2015  Initial Release
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 *                          *** No Program Inputs **
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   1. Display of an array of "char"s, one element at a time
 *           2. Display of an entire "char" array using the stream insertion
 *              Operator
 *           3. Display of an array of "char's obtained from the "istream"
 *              Extraction Operator, ">>"
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
* This program demonstrates several ways that "string"s of "char"s are stored
* in an array of "char" elements. The examples utilize the stream Insertion and'
* Extraction Operators and methods of the "istream" class to extract "char"
* input from the Console Keyboard, an object of Class "istream"
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
*     Name                             Description
* ------------  --------------------------------------------------------------
*                    *** No methods invoked from "main" ***
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;      // Program Status: No errors
	 const int LENGTH = 80;        // Maximum length for string
	 const char ARRAY_END = '\0';  // "string" terminator character: 0

	 // Variable Array Declaration
	 char line[LENGTH + 1];       // Array of "char"s to receive User's input


	 cout << "                    Textbook Example Program 12-2:\n"
		 << "                           Array of \"char\"s" << endl << endl;


	 // Example #1: Read a string of characters from the keyboard into the
	 //             "char" array
	 cout << "Example #1A: Extract \"char\"s from the Keyboard into a \"char\" array, \"line\""
		 << endl;
	 cout << "  Enter a sentence of no more than " << LENGTH << " characters: ";
	 // Method "getline" extracts characters from the Console Keyboard into the
	 // specified "char" array, limiting the number of characters allowed to the
	 // specified number, Usually specified as the length of the array.
	 cin.getline(line, LENGTH);

	 // Example #2: Display the contents of the "char" array, one element at a time
	 cout << "Example #1B: Display the contents of the \"char\" array, one element at a time"
		  << endl;
	 cout << "  The sentence you entered is: ";
	 // Loop through the array printing each character
	 for (int index = 0; line[index] != ARRAY_END; index++)
	 {
		 cout << line[index];
	 }
	 cout << endl;

	 // Example #2: Display the array via the stream insertion Operator
	 cout << "\nExample #2: Display the array via the stream insertion Operator"
		  << endl;
	 cout << "  cout << line: " << line << endl;

	 // Example #3: Utilize the stream Extraction Operator to input "char"s from
	 //             Console Keyboard into an array of "char"s, until the "Enter"
	 //             key is detected
	 cout << "\nExample #3: Use the stream Extraction Operator to store in a \"char\" array"
		  << "\n            Note: Extraction stops at the first \"white space\" character!"
		  << endl;
	 cout << "  Enter your First Name: ";
	 cin >> line;
	 cout << "  You entered: " << line << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

