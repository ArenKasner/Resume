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
* Program: 11-5
*
* Solution/Project Name: Ch11-Program11-5
*             File Name: MemberwiseAssignment.cpp
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
*   1.0     03/31/2015  Initial Release
*
* UDTs Utilized
*--------------
*    Name                              Description
* ----------  -----------------------------------------------------------------
* Rectangle   Basic features of a Rectangle. Used for demonstration purpose
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
#include "Rectangle.h"
using namespace std;


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the effect of assigning one Class object to
* another Class object of the same type, using the Assignment Operator.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                                *** None ***
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
* None
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;

   // Set up two rectangle objects
   Rectangle box1(10, 20), box2(5, 10);  

   // Display the rectangle objects
   cout << "Before the assignment:\n";
   cout << "Box 1 data:\t";  box1.output();
   cout << "Box 2 data:\t";  box2.output();

   /* Assignment of object "box1" to object "box2"
    *
    * Hidden is the code for the Default Assignment Operator, which is provided
    * by the compiler for all UDT Classes that do not provide an overloaded
    * version of the Assignment Operator. The default action is to copy the
    * values of all non-static data members of the the "rValue" Operand to the
    * data members of the "lValue" Operand
	*/
   box2 = box1;

   // Display the rectangle objects
   cout << "\nAfter the assignment:\n";
   cout << "Box 1 data:\t"; box1.output();
   cout << "Box 2 data:\t"; box2.output();  


   // This prevents the Console Window from closing during debug mode
   cin.ignore(cin.rdbuf()->in_avail());
   cout << "\nPress only the 'Enter' key to exit program: ";
   cin.get();

   return NO_ERRORS;
}