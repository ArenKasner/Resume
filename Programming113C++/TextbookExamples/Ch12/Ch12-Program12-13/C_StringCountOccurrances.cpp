/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-13
*
*
* Solution/Project Name: Ch12-Program12-13
*             File Name: C_StringCountOccurrances.cpp
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
*  Device                              Description
* --------  ------------------------------------------------------------------
* Keyboard  1. User enters a sentence, which is stored in a C-String array
*           2. User enter a single "char" to search for in the array
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor   The number of occurances of the selected search "char" in the
*           C-String array filled with the User's supplied sentence.
*
*
* File Methods
* ------------
*    Name                             Description
* ----------  -----------------------------------------------------------------
* main        Program entry point method
* countChars  Counts occurrance of specified "char" in specified C-String array
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

// Method Prototypes
int countChars(const char*,char);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates searching a C-String array for a specified "char",
* counting the number of times it occurs in the C-String array.
*
* Pre-Conditions
* --------------
* 1. User will enter only one character when prompted for the search character
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
*    Name                             Description
* ----------  -----------------------------------------------------------------
* countChars  Counts occurrance of specified "char" in specified C-String array 
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 const int S_LENGTH = 50;

	 // Define array to hold the string
	 char userString[S_LENGTH + 1];  // Allow for the C-String "NULL character

	 char letter; // User input


	 cout << "   Textbook Example Program 12-13:\n"
		  << "C-String: Count \"char\" occurances" << endl << endl;


	 // Read the string and the letter to count
	 cout << "Enter a string (up to " << S_LENGTH << " characters): ";
	 cin.getline(userString, S_LENGTH);

	 cout << "Enter the search character: ";
	 cin >> letter;

	 // Output the results of the letter count
	 cout << letter << " appears ";
	 cout << countChars(userString, letter) << " times.\n";


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


 /******************************************************************************
 * Method: countChars(const char*,char)
 *
 * Method Description
 * ------------------
 * This method searches the supplied C-String array for the specified "char"
 * and RETurns the number of occrrances to the invoking method.
 *
 * The search will be case sensitive; alphabetic characters n the C-String array
 * must macth the case of the search character in order to be counted.
 *
 * Pre-Conditions
 * --------------
 * 1. C-String array pointer is not NULL
 * 2. C-String array is terminated with the "NULL_CHAR" character
 *
 *
 * Method Arguments
 * ----------------
 *  Type       Name                        Description
 * ------  -----------  -------------------------------------------------------
 * char*   stringPntr   Pointetr to C-String array for the search
 * char    searchChar   Character to find and count occurrances of
 *
 * Return Value
 * ------------
 *   Type                              Description
 * --------  -------------------------------------------------------------------
 * int       Number of times specified search "char" occurs in the C-String
 *
 *
 * Invoked Methods
 * ---------------
 * None
 *
 *******************************************************************************
 */
 int countChars(const char* stringPntr, char searchChar)
 {
	 // Constant "const" Value Declaration
	 const char NULL_CHAR = '\0';  // C-String "NULL" terminator character

	 int count = 0;  // Initialize the occurrance counter: 0

	 while (*stringPntr != NULL_CHAR)
	 {
		 // Still more characters in the C-String array...
		 if (*stringPntr == searchChar)
		 {
			 // Found another search character. Increment number of occurrances
			 count++;
		 }
		 // Advance to the next character in the C-String array
		 stringPntr++;
	 }

	 // RETurn the number of occurrances, if any
	 return count;

 }	// End Method: countChars(const char*,char)
