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
* Program: 11-15
*
* Solution/Project Name: Ch11-Program11-15
*             File Name: ConversionOperators.cpp
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
*   1.0     04/03/2015  Initial Release
*
* UDTs Utilized
*--------------
*  Name                                     Description
* ------  ---------------------------------------------------------------------
* Length  Example Class that provides two Conversion Operators, one from
*         "Length" to "double" and another from "Length" to "int".
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
#include <iomanip>
#include <string>
#include "Length.h" 

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the use of two Conversion Operators, in this case to
* to convert a "Length" Class object to "int" and one to "int".
*
* Also, the Class contains the overloaded Addition Operator for the purpose of
* demonstating the ambiguity resolution when a literal "int" value is one of
* the Operands in the addition expression. The conflict arises since "int" and
* "double" Conversion Operators are provided, which creates an compiler
* ambiguity, sionce either the built-in Addition Operator for two "int" values
* may be used OR the "int" Operand could be converted to a "Length" object, a
* Class Conversion Constructor is provided, and the overloaded "Length" version
* of the Addition Operator could be used.
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
	Length distance1;
	Length distance2(3, 9);
	Length result;

	// Uninitialized Variable Declarations
	double feet;
	int inches;


	cout << "Textbook Example Program 11-15:\n"
		<< "      Conversion Operators" << endl << endl;


	cout << fixed << setprecision(2);


	// Convert and print
	distance1.setLength(4, 6);
	feet = distance1;
	inches = distance1;
	cout << "The Length \"distance1\" is " << distance1 << "." << endl;
	cout << "The Length \"distance1\" measures " << feet << " feet." << endl;
	cout << "The Length \"distance1\" measures " << inches << " inches.\n" << endl;

	feet = distance2;   // Conversion Operator from "Length" to "double" invoked
	inches = distance2; // Conversion Operator from "Length" to "int" invoked
	cout << "The Length \"distance2\" is " << distance2 << "." << endl;
	cout << "The Length \"distance2\" measures " << feet << " feet." << endl;
	cout << "The Length \"distance2\" measures " << inches << " inches.\n" << endl;

	result = distance1 + distance2;
	feet = result;   // Conversion Operator from "Length" to "double" invoked
	inches = result; // Conversion Operator from "Length" to "int" invoked
	cout << "The sum of \"distance1\" and \"distance2\" is " << result << ", \n"
		 << "which is equivalent to " << feet << " feet, or " << inches
		 << " inches.\n" << endl;

	result = Length(19) + distance2;  // Use of the Conversion Constructor
	feet = result;   // Conversion Operator from "Length" to "double" invoked
	inches = result; // Conversion Operator from "Length" to "int" invoked
	cout << "The sum of \"19\" and \"distance2\" is " << result << ",\n"
		<< "which is equivalent to " << feet << " feet, or " << inches
		<< " inches.\n" << endl;

	result = distance1 + Length(23);  // Use of the Conversion Constructor
	feet = result;   // Conversion Operator from "Length" to "double" invoked
	inches = result; // Conversion Operator from "Length" to "int" invoked
	cout << "The sum of \"distance1\" and \"23\" is " << result << ",\n"
		<< "which is equivalent to " << feet << " feet, or " << inches
		<< " inches.\n" << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()