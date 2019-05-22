/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook: Starting Out With C++: Early Objects
*  Authors: Tony Gaddis, Judy Walters, and Godfrey Muganda
*  Edition: 8th
*
* Textbook Example Program
* Chapter: 11
* Program: 11-11
*
* Solution/Project Name: Ch11-Program11-11
*             File Name: MoreOperatorOverloading.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     04/02/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* Length    Example Class that demonstrates overloading the prefix and postfix
*           Operators and the stream Insertion and Extraction Operators
*
*
* File Methods
* ------------
*  Name                             Description
* ------  --------------------------------------------------------------------
* main    Program entry point method
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Length1.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ------------------------------------------------
*                       *** No Arguments Defined ***
*
*
* Return Value
* ------------
* Type                              Description
* ----  ---------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
* None
*
***************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Initialized Variable Declarations
    Length first(0), second(1, 9), c(0);


	cout << "                 Textbook Example Program 11-11:\n"
		<< "Overloaded Increment Operators and Stream Insertion/Extraction Operators"
		<< endl << endl;

	cout << "To start with:" << endl;
	cout << "   \"first\": " << first << endl;
	cout << "  \"second\": " << second << endl << endl;

	cout << "Demonstrating prefix ++ operator and Class stream Insertion Operator.\n"
		<< "  first = 0 + ++second;" << endl;
    for (int count = 0; count < 4; count++)
    {
        first = 0 + ++second;
        cout << "\"first\": " << first <<  ".  \"second\": " << second << ".\n";
    }

	second.setLength(1, 9);
	cout << "\nResetting \"second\":" << endl;
	cout << "  \"second\": " << second << endl;
	cout << "   \"first\": " << first << endl;

	cout << "\nDemonstrating postfix ++ operator and Class stream Insertion Operator.\n"
		 << "  first = 0 + second++;" << endl;
	for (int count = 0; count < 4; count++)
    {
        first = 0 + second++;
        cout << "\"first\": " << first <<  ".  \"second\": " << second << ".\n";
    }

    cout << "\nDemonstrating Class stream Extraction Operator.\n";
    cin >> c;
    cout << "You entered " << c << "." << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()