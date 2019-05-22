/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-12
*
*
* Solution/Project Name: Ch12-Program12-12
*             File Name: C_StringLengthChange.cpp
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
*   1.0     04/18/2015  Initial Release
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  User enters first and last name as one "string" value, separated
*           by specified "delimiter" character
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   The C-Style input array showing just the User's first name
*
*
* File Methods
* ------------
*  Name                             Description
* ------  ---------------------------------------------------------------------
* main    Program entry point method
* slice   Eliminates C-String characters beyound first specified delimiter char
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
void nameSlice(char[],char);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
*
* Pre-Conditions
* --------------
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
*  Name                             Description
* ------  ---------------------------------------------------------------------
* slice   Eliminates C-String characters beyound first specified delimiter char
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 const int NAME_LENGTH = 40;
	 const char DELIMITER = ' ';  // Delimiter: "Space" character

	 // Define array of char to hold name
	 char name[NAME_LENGTH + 1];  // Include room for "NULL" terminator


	 cout << "Textbook Example Program 12-12:\n"
		  << "   Modifying C-String length" << endl << endl;


	 // Get user's first and last names
	 cout << "Enter your first and last names, separated by a space: ";
	 cin.getline(name, NAME_LENGTH);

	 // Slice off the last name and print what is left
	 nameSlice(name, DELIMITER);
	 cout << "Your first name is: " << name << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


 /******************************************************************************
 * Method: nameSlice(char[],char)
 *
 * Method Description
 * ------------------
 * This method searches the supplied C-String array for the specified delimiter
 * character and subsitutes it with the C-String "NULL" character, thus
 * effectively eliminating the remainder of the original C-String array
 * contents.
 *
 *
 * Pre-Conditions
 * --------------
 * 1. The array pointer argument is not a NULL pointer
 * 2. The array has a terminating C-String "NULL" character
 *
 *
 * Method Arguments
 * ----------------
 *  Type      Name                        Description
 * ------  ----------  --------------------------------------------------------
 * char[]  userName     C-String array with User's first and last name
 * char    delimiter    Delimiter character between first and last name
 *
 * Return Value
 * ------------
 * Type                              Description
 * ----  ----------------------------------------------------------------------
 * void  Method RETurns no value
 *
 *
 * Invoked Methods
 * ---------------
 * None
 *
 *******************************************************************************
 */
 void nameSlice(char userName[], char delimiter)
 {
	 const char NULL_CHAR = '\0';

	 // Look for the end of the first name, indicated either the specified
	 // delimiter character OR the C-String NULL terminator character

	 int k = 0;  // Start search at first character in the C-String array

	 while (userName[k] != delimiter && userName[k] != NULL_CHAR)
	 {
		 // Keep looking for the first delimiter character...
		 k++;  // Advance to the next character in the C-String array
	 }

	 // Insert null terminator if NOT at the end of the array	
	 if (userName[k] == delimiter)
	 {
		 // Substitute the delimiter character with the "NULL" character,
		 // effectively eliminating the remainder of the original C-String
		 userName[k] = NULL_CHAR;
	 }

 }	// End Method: nameSlice(char[],char)