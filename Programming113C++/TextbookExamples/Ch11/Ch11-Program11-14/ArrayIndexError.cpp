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
* Program: 11-14
*
* Solution/Project Name: Ch11-Program11-14
*             File Name: ArrayIndexError.cpp
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
* IntArray  Example Class that provides an overloaded [] Operator to access
*           elements in the underlying array of integers.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* main          Program entry point method
* displayTable  Disply all elements in "IntArray" object
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "intarray.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

// Method Prototypes
void displayTable(const IntArray&);


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates error detection if an index value is outside the
* allowed range of values when used to access an array element in a Class
* that overloads the [] Operator.
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
*     Name                             Description
* ------------  --------------------------------------------------------------
* displayTable  Disply all elements in "IntArray" object
*
***************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;
	const int TABLE_SIZE = 10;

	// Initialized Array Declaration
	IntArray table(TABLE_SIZE);

	// Uninitialized Variable Declaration
	int size;


	cout << "Textbook Example Program 11-14:\n"
		<< "       Array Index Error" << endl << endl;

	// Get the size of the array
	size = table.size();

	cout <<   "Array size: " << size
		 << "\n Max Index: " << size - 1 <<endl;

	// Display the initial state of the array
	cout << "Initial object elements:" << endl;
	cout << "  \"table\": ";
	displayTable(table);

	// Store values in the array
	cout << "\nFilling Table with 2x index value" << endl;
	cout << "  Filled Table: ";
	for (int x = 0; x < size; x++)
		table[x] = (x * 2);
	// Display the values in the array
	displayTable(table);


	// Attempt to access an element outside tha allowed range of
	// index values
	cout << "\nAttempt to modify element at index: " << table.size() << endl;
	table[table.size()] = 45;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


/******************************************************************************
* Method: displayTable(const IntArray&)
*
* Method Description
* ------------------
* This method displays all the elements in the "IntArray" object passed to it
* by reference.
*
*
* Method Arguments
* ----------------
*    Type      Name                        Description
* ----------  ------  ---------------------------------------------------------
* IntArray&   table   Array object to be displayed
*
*
* Return Value
* ------------
* Type                              Description
* ----  -----------------------------------------------------------------------
* void  The method RETurns no value
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
void displayTable(const IntArray& table)
{
	cout << '[';
	if (table.size() > 0)
	{
		cout << table[0];

		for (int x = 1; x < table.size(); x++)
			cout << " " << table[x];
	}

	cout << ']' << endl;

}	// End Method: displayTable(const IntArray&)