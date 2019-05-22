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
* Program: 11-10
*
* Solution/Project Name: Ch11-Program11-10
*             File Name: OperatorOverloading.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/02/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* Length    Example Class that demonstrates overloading of arithmetic and
*           relational Operators applied to a Class object.
*
*
* File Methods
* ------------
*     Name                             Description
* -------------  --------------------------------------------------------------
* main           Program entry point method
* displayLength  Displays the feet and inches for the secified "Length" object
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Length.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

// Method Prototypes
void displayLength(string,char,const Length&);


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates overloading of two Arithmetic Operators, addition
* and subtrraction, and several Comparison Operators, equality, inequality,
* and the "less than" Operator.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                       *** No Arguments Defined ***
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* -------------  --------------------------------------------------------------
* displayLength  Displays the feet and inches for the secified "Length" object
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Initialized Variable Declarations
	Length first(0), second(0);  // Invoke Initializing Constructor
	Length third;                // Invoke the Default Constructor

	// Uninitialized Variable Declarations
	int feet;
	int inches;


	cout << "       Textbook Example Program 11-10:\n"
		<< "Overloaded Arithmetic and Comparison Operators" << endl << endl;


	cout << "Initial state of three \"Length\" objects:" << endl;
	displayLength("   first", ':', first);
	displayLength("  second", ':', second);
	displayLength("   third", ':', third);


    cout << "\nEnter the first length, feet and inches" << endl;
	cout << "    Enter the number of feet: ";
	cin >> feet;
	cout << "  Enter the number of inches: ";
	cin >> inches;
	first.setLength(feet, inches);

	cout << "Enter the second length, feet and inches" << endl;
	cout << "    Enter the number of feet: ";
	cin >> feet;
	cout << "  Enter the number of inches: ";
	cin >> inches;
	second.setLength(feet, inches);
	cout << endl;

    // Test the + and - operators 
    third = first + second;
	displayLength("first + second ", '=', third);

	third = first - second;
	displayLength("first - second ", '=', third);

    // Test the relational operators
    cout << "first == second: ";
	cout << ((first == second) ? "true" : "false") << endl;

	cout << "first != second: ";
	cout << ((first != second) ? "true" : "false") << endl;

	cout << "first < second: ";
	cout << ((first < second) ? "true" : "false") << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

	}	// End Method: main()

/******************************************************************************
* Method: displayLength(string,char,const Length&)
*
* Method Description
* ------------------
* This method displays a "Length" object, specifying the number of feet and
* inches along with the supplied description and separator character.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
* string    descriprion    Description of the "Length" object displayed
* char      separator      Separator character after "description"
* Lnegth&   object         "const" reference to "Length" object to display
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* void  Method RETurns no value
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void displayLength(string description, char separator, const Length& object)
{
	cout << description << separator << ' ';
	cout << object.getFeet() << " feet, ";
	cout << object.getInches() << " inches.\n";

}	// End Method: displayLength(string,char,constLength&)