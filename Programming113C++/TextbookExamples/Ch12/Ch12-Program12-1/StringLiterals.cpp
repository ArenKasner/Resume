/******************************************************************************
 * Bellevue Class: PROG 113
 *     Instructor: Robert Main
 *
 * Textbook Example Program
 * Chapter: 12
 * Program: 12-1
 *
 * Solution/Project Name: Ch12-Program12-1
 *             File Name: StringLiterals.cpp
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: **Your Name**
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
 *                      *** No Program Inputs ***
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   Literal strings and their memory addresses
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
* This program demonstrates that C++ literal "string"s are actually stored in
* memory as an array of "char"s. The program will assign literal stings to
* pointers of type "char", the display the array of "char"s and the address
* of the first character.
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
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Value Declarations
	 const int NO_ERRORS = 0;

	 // The "char" pointers MUST be declared as "const" pointers, since literal
	 // "strings" are assigned to the pointers. Being literal "string"s, they
	 // are immutable and hence cannot be changed once defined.
	 const char* word1;
	 const char* word2;

	 // Define a non-const pointer to "char"
	 // Used to demostrate
	 char* word3;


	 cout << "Textbook Example Program 12-1:\n"
		 << "       String Literals" << endl << endl;


	 // Assign literal "string" words to each pointer
	 // The characters of the literal string are stored in contiguous memory
	 // locations, i.e. in an array, with a trailing "0" value after the last
	 // character in the string.
	 // The literal string itself is assigned the address of the first character
	 // in the string.
	 word1 = "Hello ";
	 word2 = "Bailey";

	 // Example #1: Display the two literal words, one right after the other.
	 // The compiler generates code for "char" pointers to insert each character,
	 // starting at the address of the pointer, into the output stream until a 
	 // "char" with value of "0" is reached, which terminates the insertion into
	 // the output stream.
	 cout << "Example #1: Display the two literal words, one right after the other"
		 << endl;
	 cout << "  The words are: " << word1 << word2 << endl;

	 // Example #2: Display the addresses of the two literal "string"s
	 cout << "\nExample #2: Display the addresses of the two literal \"string\"s"
		 << endl;
	 cout << word1 << " is located at address " << int(word1) << endl;
	 cout << word2 << " is located at address " << int(word2) << endl;

	 // This demonstrates that a literal "string" in an expression is stored
	 // by the compiler in memory and that the literal itself is a pointer
	 // "char".
	 cout << "\nExample #3: Define a literal string in a statement."
		  << "\n            (i.e. NOT assigned to a pointer)" << endl;
	 cout << "  The literal string, \"literal\", is located at address "
		  << int("literal") << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
	
}	// End Method: main()

