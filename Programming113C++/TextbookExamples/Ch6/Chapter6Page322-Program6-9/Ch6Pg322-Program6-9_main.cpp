/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg322-Program6-9
 * File Name:             Ch6Pg322-Program6-9_main.cpp
 *
 * This file defines the entry point ( main() ) for the Console application.
 *
 * Programmer: Robert Main
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     10/23/2012 Initial Release
 *
 * File Desciption
 * ---------------
 * This program demonstrates the definition and use of a simple function.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototypes
// "void": No RETurn value, one "int" parameter
void changeParameter(int val);

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
 * RETurn        Name       Params               Description                  *
 * ------  ---------------  ------  ------------------------------------------*
 * None    changeParameter  int     Modifies parameter passed to it           *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, then calls a function, passing a single "int" parameter,*
 * by VALUE to it. The function will modifiy the parameter, RETurn and the    *
 * the parameter passed from main() will be displayed to show that it has NOT *
 * modified.                                                                  *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
	// Variable Declaration
	int number;


    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 322 - Program 6-9: Passing parameters by value\n\n";

	// Display that function main() has been invoked
	cout << "Hello from function: int main().\n";

	// Now solicit an integer value from the User
	cout << "Please enter an integer value: ";
	cin >> number;
	cout << "\nValue of \"number\" before function call: " << number << endl;

	// Now call function: void changeParameter(int)
	changeParameter(number);
	cout << "Back in function: int main() again.\n"
		 << "Value of \"number\" after function call: " << number << endl;

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
 * Function: displayMessage                                                   *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Type  Name                           Description                           *
 * ----  ------  -------------------------------------------------------------*
 * int   number  An integer value that is modified within the function        *
 *                                                                            *
 * RETurn Value                                                               *
 * ------------                                                               *
 * void                                                                       *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Displays a greeting and then modifies the parameter passed to it.          *
 * The parameter, a value local to the function is multiplied by a factor     *
 * of 3.                                                                      *
 *                                                                            *
 ******************************************************************************
 */
void changeParameter(int number)
{
	cout << "Hello from function: void changeParameter(int).\n";
	// Modify the parameter
	// Note: Function parameters are "local" to the function and go out of
	//       scope when function execution RETurns to the calling function!
	number *= 3;
	cout << "Modified parameter \"number\": " << number << endl;

	/* For completeness, you may include a "return" statement at the
	 * end of a function. The general form of the "return" statement is:
	 *    return x;
	 * where x is a value (can be an expression) that is the same data type
	 * as the RETurn value of the function. When the RETurn value is "void",
	 * i.e. NO return value, no value  for "x" may be specified.
	 */
	return;

}

