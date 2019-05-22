/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook: Starting Out With C++: Early Objects
*  Authors: Tony Gaddis, Judy Walters, and Godfrey Muganda
*  Edition: 8th
*
* Instructor Demonstration Program
* Chapter: 11
*
* Solution/Project Name: Ch11-CopyConstructorInvocations
*             File Name: CopyConstructorInvocations.cpp
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
*   1.0     03/31/2015  Initial Release
*
* File Methods
* ------------
*      Name                             Description
* --------------  -------------------------------------------------------------
* main            Program entry point method
* foo1            Demonstrates method invocation passing an object by Value
* foo2            Demonstrates a method  that RETurns an object by value
* displayObject   Display of a "NumberArray" object's array contents
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "NumberArray.h"   // Class Definition: NumberArray

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program


// Method Prototypes
void foo1(NumberArray, string);
void displayObject(NumberArray&, string);
NumberArray foo2();


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the various situations in which the Class Copy
* Constructor is invoked.
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
*      Name                             Description
* --------------  -------------------------------------------------------------
* foo1            Demonstrates method invocation passing an object by Value
* foo2            Demonstrates a method  that RETurns an object by value
* displayObject   Display of a "NumberArray" object's array contents
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

	// Create an object
	NumberArray one(3, 10.5);

	NumberArray two;
	NumberArray three(3, 7.89);

 
	cout << "Instructor Demonstration Program: Chapter 11\n"
		 << "Invocation Examples of the Copy Constructor" << endl << endl;


	cout << setprecision(2) << fixed << showpoint;

	// Invoke method "foo1"
	cout << "Invoking \"foo1\", passing object by Value" << endl;
	foo1(one, "one");
	cout << "Back in method \"main()\" from method \"foo1\"" << endl;

	// Invoke method "foo2"
	cout << "\nInvoking \"foo2\", which RETurns a Class object" << endl;
	foo2();
	cout << "Back in method \"main()\" from method \"foo2\"" << endl;

	cout << "\nInvoking \"foo2\", assigning to Class object \"two\"" << endl;
	two = foo2();
	cout << "Back in method \"main()\" from method \"foo2\"" << endl;
	displayObject(two, "two");

	cout << "\nAssigning Class object \"one\" to Class object \"three\"" << endl;
	three = one;
	cout << "Back in method \"main()\" from the Assignment Operator" << endl;
	displayObject(three, "three");

	cout << "\nAssigning Class object \"two\" to Class object \"one\"" << endl;
	one = two;
	cout << "Back in method \"main()\" from the Assignment Operator" << endl;
	displayObject(one, "one");

	cout << "\nAssigning Class object \"one\" to itself" << endl;
	one = one;
	cout << "Back in method \"main()\" from the Assignment Operator" << endl;
	displayObject(one, "one");


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


/******************************************************************************
* Method: foo1(NumberArray)
*
* Method Description
* ------------------
* This method formats and displays the array contents within the "NumberArray2"
* object passed to this method by reference. The array contents are displayed
* by invoking the class method "print()".
*
*
* Method Arguments
* ----------------
*      Type        Name                        Description
* --------------  ------  ----------------------------------------------------
* NumberArray2&   object  Reference to "NumberArray2" object to display
* string          name    Name (identifier) of the object to display
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
*                       *** Method RETurns no value ***
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void foo1(NumberArray object,string name)
{
	cout << "  Method \"foo1\" entered\n"
		 << "    Values stored in object \"" << name << "\":";
	object.print();
	cout << endl;

	cout << "  Method \"foo1\" completed" << endl;

}	// End Method: foo1(NumberArray,string)


NumberArray foo2()
{
	cout << "  Method \"foo2\" entered\n"
		<< "    Instantiating a local \"NumberArray\" object" << endl;

	NumberArray object(5, 34.78);

	cout << "  Method \"foo2\" completed" << endl;

	return object;

}	// End Method: foo2()


/******************************************************************************
* Method: displayObject(NumberArray&,string)
*
* Method Description
* ------------------
* This method formats and displays the array contents within the "NumberArray"
* object passed to this method by reference. The array contents are displayed
* by invoking the class method "print()".
*
*
* Method Arguments
* ----------------
*      Type        Name                        Description
* --------------  ------  ----------------------------------------------------
* NumberArray2&   object  Reference to "NumberArray2" object to display
* string          name    Name (identifier) of the object to display
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
*                       *** Method RETurns no value ***
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void displayObject(NumberArray& object, string name)
{
	cout << "  Values stored in object \"" << name << "\":";
	object.print();
	cout << endl;

}	// End Method: displayObject(NumberArray&,string)
