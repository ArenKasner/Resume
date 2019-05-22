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
* Program: 11-16
*
* Solution/Project Name: Ch11-Program11-16
*             File Name: ConversionConstructorExamples.cpp
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
*   1.0     04/06/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* IntClass   Example Class that provides a Conversion Constructor.
*
*
* File Methods
* ------------
*    Name                             Description
* ----------  -----------------------------------------------------------------
* main        Program entry point method
* foo         Method that RETurns an "int" value as a "IntClass" object
* printValue  Method that receives an "IntClass" object but is passed an "int"
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Convert.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

// Function prototypes.
void printValue(IntClass);
IntClass foo(int);

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the use of Conversion Constructors, which allows
* the compiler to convert a built-in data type or another UDT to an object of
* the Class.
*
* Two examples of the need for a Conversion Constructor are shown,
* 1) A built-in data type is passed to a mwethod that expects an object of the
* Class, and 2) A method that attempts to RETurn a built-in data type value
* when the method promises to RETurn an object of the Class.
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
*    Name                             Description
* ----------  -----------------------------------------------------------------
* foo         Method that RETurns an "int" value as a "IntClass" object
* printValue  Method that receives an "IntClass" object but is passed an "int"
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;


	cout << "    Textbook Example Program 11-16:\n"
		<< "Examples of using  Conversion Constructor" << endl << endl;


	// Example #1: Instantiate and initialize with an "int" value
	cout << "Example #1, Conversion Constructor: intClass intObject(23);" << endl;
	IntClass intObject(23);
	cout << "The value is " << intObject.getValue() << endl;

	// Example #2: Assign an "int" value to an "IntClass" object
	cout << "\nExample #2, Assignment of an \"int\" value: intObject = 24;" << endl;
	intObject = 24;
	cout << "The value is " << intObject.getValue() << endl;

	// Example #3: Pass an int to a function expecting IntClass
	cout << "\nExample #3, pass an \"int\" value to a method that expects a \"IntClass\" object" << endl;
	printValue(25);
	cout << endl;

	// Example #4: Conversion Constructor to convert an "int" value to a "IntClass" object
	//             for a method RETurn value.
	cout << "\nExample #4, Conversion of \"IntClass\" to \"int\" for a method RETurn"
		 << "\n            intObject = foo(26)" << endl;
	intObject = foo(26);
	cout << "Back in \"main()\" from method \"foo\"" << endl;
	int value = intObject.getValue();
	cout << "The value is " << value << endl;;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


/******************************************************************************
* Method: foo(int)
*
* Method Description
* ------------------
* This method demonstrates the compiler's use of a Conversion Constructor to
* create an "IntClass" object from an "int" value for the RETurn value from
* the method.
*
*
* Method Arguments
* ----------------
* Type    Name                        Description
* ----  --------  -------------------------------------------------------------
* int   intValue  An "int" value to be converted to an "IntClass object
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* IntClass  An object created from an "int" value
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
IntClass foo(int intValue)
{
	cout << "Method \"foo\" entered" << endl;

	return intValue;

}	// End Method: foo(int)


/******************************************************************************
* Method: printValue(IntClass)
*
* Method Description
* ------------------
* This method demonstrates the compiler's use of a Conversion Constructor to
* create an "IntClass" object from an "int" value in the invoking method to
* this method.
*
*
* Method Arguments
* ----------------
*   Type    Name                        Description
* --------  ----  -------------------------------------------------------------
* IntClass  obj   An "IntClass"  object for processing.
*
*
* Return Value
* ------------
* Type                              Description
* ----  -------------------------------------------------------------------
* void  The method RETurns no value
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void printValue(IntClass x)
{
	cout << "The value is " << x.getValue();

}	// End Method: prntValue(IntClass)