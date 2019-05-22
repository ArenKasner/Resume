/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg310-Program6-3
 * File Name:             Ch6Pg310-Program6-3_main.cpp
 *
 * This file defines the entry point ( main() ) for the Console application.
 *
 * Programmer: Robert Main
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     10-23-2012 Initial Release
 *
 * File Desciption
 * ---------------
 * This program demonstrates the definition and use of a multiple functions
 * that are called within each other, i.e. a nesting of function calls.
 * This program combines the concepts shown in Program 6-3 and Program 6-4.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototypes
void displayFirstMessage();  // "void": No RETurn value  (): No parameters supplied
void displaySecondMessage(); // "void": No RETurn value  (): No parameters supplied
void displayThirdMessage();  // "void": No RETurn value  (): No parameters supplied

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
 * RETurn          Name         Params            Description                 *
 * ------  -------------------- ------  --------------------------------------*
 * void    displayFirstMessage  None    Display Message identifying method    *
 * void    displaySecondMessage None    Display Message identifying method    *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, then calls function "displayFirstMessage" and finally   *
 * calls a second function "displaySecondMessage".                            *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 310 - Program 6-3: Nested Function calls\n\n";

	cout << "Hello from function: int main().\n";

	// Call function: void displayFirstMessage()
	displayFirstMessage();
	cout << "Back in function: int main() again.\n";
	displaySecondMessage();
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
 * Function: displayFirstMessage                                              *
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
 * RETurn           Name         Params            Description                *
 * ------  --------------------  ------  -------------------------------------*
 * None    displaySecondMessage  None    Display Message identifying method   *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Displays a greeting, indicating the function name and then calls method    *
 * "displaySecondMessage()" that describes its method name.                   *
 *                                                                            *
 ******************************************************************************
 */
void displayFirstMessage()
{
	cout << "Hello from function: void displayFirstMessage().\n";
	// Now display the second message
	displaySecondMessage();
	cout << "Back in function: void displayFirstMessage() again.\n";
}



/******************************************************************************
 * Function: displaySecondMessage                                             *
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
 * RETurn          Name         Params            Description                 *
 * ------  -------------------  ------  --------------------------------------*
 * None    displayThirdMessage  None    Display Message identifying method    *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Displays a greeting, indicating the function name and then calls method    *
 * "displayThirdMessage()" that describes its method name.                    *
 *                                                                            *
 ******************************************************************************
 */
void displaySecondMessage()
{
	cout << "Hello from function: void displaySecondMessage().\n";
	// Now display the third message
	displayThirdMessage();
	cout << "Back in function: void displaySecondMessage() again.\n";
}


/******************************************************************************
 * Function: displayThirdMessage                                              *
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
 *  Function Description                                                      *
 * ---------------------                                                      *
 * Displays a greeting, indicating the function name.                         *
 *                                                                            *
 ******************************************************************************
 */
void displayThirdMessage()
{
	cout << "Hello from function: void displayThirdMessage().\n";
}
