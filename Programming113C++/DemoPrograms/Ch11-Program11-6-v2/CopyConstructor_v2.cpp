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
* Program: 11-6  Version 2
*
* Solution/Project Name: Ch11-Program11-6
*             File Name: CopyConstructor_v2.cpp
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
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* Address2  Example Class that overrides the Default Copy Constructor and the
*           Assignment Operator
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
#include "Address2.h"
#include <iostream>
#include <string>
using namespace std;



/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the effect of the UDT Class Default Constructor,
* which copies the values of all non-static data members of one Class object
* to another, same Class object that is being instantiated.
*
* In this version, the subtlity of using the overloaded Assignment Operator is
* demonstrated. The Assignment Operator must RETurn the "lValue" object itself
* in order to support Assignment chaining. To do so, a Copy, not the "lValue"
* itself must be RETurned from the overloaded Assignment Operator. Thus, the
* Class Default Constructor must be invoked to obtain the copy.
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

  // Mary, Joan, and Sue live at same address
  Address2 mary("1234 Main St");


  cout << "Textbook Example Program 11-6: Copy Constructor - Part 2"
	  << endl << endl;

  cout << "Instantiating object \"joan\" from object \"mary\" using Assignment" << endl;
  Address2 joan = mary;  // Use of the Assignment Operator
  cout << "Instantiating object \"sue\" from object \"mary\" using Copy Constructor" << endl;
  Address2 sue(mary);    // Direct use of the Default Copy Constructor
  cout << endl;

  cout << "    Mary lives at " << mary.getStreet() << endl;
  cout << "    Joan lives at " << joan.getStreet() << endl;
  cout << "    Sue  lives at " << sue.getStreet() << endl << endl;

  // Now Joan moves out
  joan.setStreet("1600 Pennsylvania Ave");
  cout << "    Mary lives at " << mary.getStreet() << endl;
  cout << "Now Joan lives at " << joan.getStreet() << endl;
  cout << "    Sue  lives at " << sue.getStreet() << endl << endl;

  // Finally, Sue moves out
  sue.setStreet("4567 Jones Street");
  cout << "    Mary lives at " << mary.getStreet() << endl;
  cout << "    Joan lives at " << joan.getStreet() << endl;
  cout << "Now Sue  lives at " << sue.getStreet() << endl;


  // Then Jaon moves back to Mary's home
  cout << "\nAssigning object \"mary\" to object \"joan\""
	   << "\n  Note: Copy Construcor gets called!" << endl;
  joan = mary;
  cout << "    Mary lives at " << mary.getStreet() << endl;
  cout << "Now Joan lives at " << joan.getStreet() << endl;
  cout << "    Sue  lives at " << sue.getStreet() << endl << endl;

  // This prevents the Console Window from closing during debug mode
  cin.ignore(cin.rdbuf()->in_avail());
  cout << "\nPress only the 'Enter' key to exit program: ";
  cin.get();

  return NO_ERRORS;

}	// End Method: main()