/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg328-Program6-11
 * File Name:             Ch6Pg328-Program6-11_main.cpp
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
 * RETurns a value.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines the output stream manipulators
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Function Prototypes
// "int": RETurn "int" value, two "int" parameters
int add(int addend1, int addend2);


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
 * RETurn  Name   Params                      Description                     *
 * ------  ----  --------  ---------------------------------------------------*
 * int     add   int, int  RETurns the sum of the 2 integer parameter values  *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program. It displays a greeting, indicating  *
 * the function name, then calls a function, "add", passing a two parameters, *
 * by VALUE. The function will calculate the sum of the two parameter values, *
 * RETurning the sum to the calling method.                                   *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
	int value1;     // The first value
    int value2;     // The second value
    int sum;        // The RETurn value from method "sum"
	float average;  // The average of the two integer values

    // Display the Chapter, page, and description of the example
	cout << "Chapter 6, page 328 - Program 6-11:\n"
		 << "Call to a function that RETurns the sum of two parameter values\n\n";


	// Solicit the two numbers for the addition from the User
	cout << "Please enter the first number for the sum:  ";
	cin >> value1;

	cout << "Please enter the second number for the sum: ";
	cin >> value2;

   // Call the sum function, passing the variables "value1"
   // and "value2" as arguments by value. Assign the RETurn
   // "int" value to the total variable.
   sum = add(value1, value2);

   // Compute the average, as a "float" value
   // Note: "sum", an "int" value will be IMPLICITLY cast to a "float"
   //       for the calculation of the average!
   average = sum / 2.0f;
   
   // Display the sum of the values.
   cout << fixed << setprecision(2);
   cout << "The sum of " << value1 << " and "
        << value2 << " is " << sum << ", and the average is "
		<< average << endl;


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
 * Function: add                                                              *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * Type   Name                           Description                          *
 * ----  -------  ------------------------------------------------------------*
 * int   addend1  Addend #1, an integer value                                 *
 * int   addend1  Addend #2, an integer value                                 *
 *                                                                            *
 * RETurn Value                         Description                           *
 * ------------  -------------------------------------------------------------*
 * int           The sum of the two "int" addends                             *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Calculates the sum of two integer numbers.                                 *
 *                                                                            *
 ******************************************************************************
 */
int add(int addend1, int addend2)
{
   return (addend1 + addend2);
}

