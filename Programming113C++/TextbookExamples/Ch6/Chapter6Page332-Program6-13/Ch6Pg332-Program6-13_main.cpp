/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg332-Program6-13
 * File Name:             Ch6Pg332-Program6-13_main.cpp
 *
 * This file defines the entry point ( main() ) for the Console application.
 *
 * Programmer: Robert Main
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     11/03/2012  Initial Release
 *
 * File Desciption
 * ---------------
 * This program demonstrates the definition and use of a function (method) that
 * RETurns a "bool" value.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines the output stream manipulators
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototype
bool isEven(int value);


/******************************************************************************
 * Function: main                                                             *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 *   None                                                                     *
 *                                                                            *
 * RETurn Value                                                               *
 * ------------                                                               *
 * Type  Value                           Description                          *
 * ----  -----  --------------------------------------------------------------*
 * int   0      No error(s) status to Operating System                        *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * RETurn   Name   Params                      Description                    *
 * ------  ------  ------  ---------------------------------------------------*
 * bool    isEven  int     RETurns "true" if parameter is an even number      *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, then calls a function, "isEven", passing a parameter,   *
 * by VALUE. The function called will determine if the value passed to it is  *
 * an even number.                                                            *
 *                                                                            *
 * The function "isEven" has one, and only one, RETurn (return) statement,    *
 * which is the instructor's prefered style for exiting a function, i.e. there*
 * should NOT be multiple exit points from a function.                        *
 *                                                                            *
 * The display statement demonstrates the use of the ternary Conditional      *
 * Operator to decide on a literal string for display.                        *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
	// Variable Declarations
	int  value;          // User's value

    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 332 - Program 6-13:\n"
		 << "Call to a function that RETurns a \"bool\" value\n\n";


	// Solicit an integer number from the User
	cout << "Please enter an integer number:  ";
	cin >> value;

	/* Call the function "isEven", passing the variable "value"
	 * within the stream output statement, i.e. no need to store
	 * the result of the method call.
	 * Notice that the ternary Conditional Operator may be used to RETurn a
	 * literal string, which the extraction Operator can insert into the
	 * Console output stream. Because of Operator precedence rules, the
	 * entire ternary operator MUST be enclosed in parentheses to assure it
	 * is evaluated first to produce the literal string result.
	*/
	cout << "The integer number " << value << (isEven(value) ? " IS " : " is NOT ")
         << "an Even number." << endl;


	// This prevents the Visual Studio 2010 Console Window from closing during
	// debug mode.
	// This next statement purges any characters, if any, remaining in the
	// Console input buffer, BEFORE "cin.get()" looks for the "new line" character
	cin.ignore(cin.rdbuf()->in_avail(), '\n');
	cout << endl << "Press only the 'Enter' key to exit program: ";
	cin.get();

	return 0;
}

/******************************************************************************
 * Function: isEven                                                           *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Type   Name                           Description                          *
 * ----  -----  --------------------------------------=-----------------------*
 * int   value  An integer value                                              *
 * int   addend1  Addend #2, an integer value                                 *
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ----  ---------------------------------------------------------------------*
 * bool  "true":  Parameter value IS an even number                           *
 *       "false": Parameter value is NOT an even number                       *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Determines if an integer number is an even number.                         *
 *                                                                            *
 ******************************************************************************
 */
bool isEven(int number)
{
	bool even = false;   // Assume the number is NOT even

	if (number %2 == 0)
		even = true;

   return even;
}
