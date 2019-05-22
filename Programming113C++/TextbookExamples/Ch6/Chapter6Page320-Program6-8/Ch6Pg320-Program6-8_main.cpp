/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg320-Program6-8
 * File Name:             Ch6Pg320-Program6-8_main.cpp
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
 * This program demonstrates the definition and use of a function with multiple
 * parameters, three in this case. Integer values are solicited from the User
 * and then passed, by value, to a function that calculates and then displays
 * the sum of the thress values.
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
void displaySum(int val1, int val2, int val3);

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
 * RETurn     Name       Params            Description                        *
 * ------  ---------- -------------  -----------------------------------------*
 * void    displaySum int, int, int  Sum and display of three parameters      *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, requests three integer numbers from the User and then   *
 * calls function "displaySum", passing the three values entered, that will   *
 * compute and display the sum of the three values.                           *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
	// Variable Declarations
	int value1, value2, value3;


    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 320 - Program 6-8:\n"
		 << "Call to function with multiple parameters\n\n";

	cout << "Hello from function: int main().\n";

	cout << "Please enter an integer for value #1: ";
	cin >> value1;

	cout << "Please enter an integer for value #2: ";
	cin >> value2;

	cout << "Please enter an integer for value #3: ";
	cin >> value3;

	// Call function "displaySum" to calculate and display
	// the sum of the three numbers entered.
	displaySum(value1, value2, value3);

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
 * Function: displaySum                                                       *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Type   Name                            Description                         *
 * ----  ------  -------------------------------------------------------------*
 * int   value1  First value to be summed.                                    *
 * int   value2  Second value to be summed.                                   *
 * int   value3  Third value to be summed.                                    *
 *                                                                            *
 * RETurn Value                                                               *
 * ------------                                                               *
 * void                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Displays the sum of the three parameters passed (by value) to the function.*
 *                                                                            *
 ******************************************************************************
 */
void displaySum(int value1, int value2, int value3)
{
	int sum = value1 + value2 + value3;

	cout << "\nHello from function: void displaySum(int, int, int).\n"
		 <<   "The sum of " << value1 << ", " << value2 << ", and " << value3
		 <<   " is " << sum << endl;
}
