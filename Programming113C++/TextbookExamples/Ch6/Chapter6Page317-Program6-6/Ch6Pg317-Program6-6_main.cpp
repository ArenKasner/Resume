/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg317-Program6-6
 * File Name:             Ch6Pg317-Program6-6_main.cpp
 *
 * This file defines the entry point ( main() ) for the Console application.
 *
 * Programmer: Robert Main
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     10/23/2012  Initial Release
 *
 * File Desciption
 * ---------------
 * This program demonstrates the definition and use of a function with a single
 * parameter that is called multiple times within a "for-next" loop.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototypes
// "void": No RETurn value
// Only the data type of the paramter need be specified
// A "placeholder", i.e. an identifier (name) of the parameter may be specified
// for documentation purposes, but is ignored by the compiler.
void displayMessage(int);
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
 * RETurn       Name      Params            Description                       *
 * ------  -------------- ------  --------------------------------------------*
 * void    displayMessage None    Display message deacribing function         *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, then calls another function repeatedly to display a     *
 * seperate message.                                                          *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 317 - Program 6-6:\n"
		 << "Multiple calls to a Function with one parameter \n\n";

	cout << "Hello from function: int main().\n";

	for (int count = 1; count <= 5; ++count)
	{	// Call function: void displayMessage(int)
		// Pass by value (i.e a COPY of "count"), the value of count
		displayMessage(count);
	}

	cout << "Back in function: int main() again.\n";

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
 * Type   Name                            Description                         *
 * ----  ------  -------------------------------------------------------------*
 * int   value   Value to be displayed in the function.                       *
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
 * Displays a greeting, indicating the function name and the value of the     *
 * parameter passed to the function.                                          *
 *                                                                            *
 ******************************************************************************
 */
void displayMessage(int value)
{
	cout << "\nHello from function: void displayMessage(int).\n"
		 <<   "The parameter passed to me is: " << value << endl;
}

