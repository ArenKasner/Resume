/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg308-Program6-2
 * File Name:             Ch6Pg308-Program6-2_main.cpp
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
 * This program demonstrates the definition and use of a simple function that
 * is called multiple times within a "for-next" loop.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototypes
void displayMessage();  // "void": No RETurn value  (): No parameters supplied
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
 * RETurn       Name      Params               Description                    *
 * ------  -------------- ------  --------------------------------------------*
 * void    displayMessage None    Display Message identifying method          *
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
	cout << "Chapter 6, page 310 - Program 6-2: Multiple Function calls\n\n";

	cout << "Hello from function: int main().\n";

	for (int count = 1; count <= 5; ++count)
	{	// Call function: void displayMessage()
		displayMessage();
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
 *   None                                                                     *
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
 * Displays a greeting, indicating the function name.                         *
 *                                                                            *
 ******************************************************************************
 */
void displayMessage()
{
	cout << "Hello from function: void displayMessage().\n";
}
