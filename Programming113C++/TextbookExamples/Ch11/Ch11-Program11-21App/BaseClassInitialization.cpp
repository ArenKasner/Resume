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
* Program: 11-21App
*
* Solution/Project Name: Ch11-Program11-21App
*             File Name: BaseClassInitialization.cpp
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
*   1.0     04/10/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* Person     Base Class for two Class objects intantiated in this program
* Student    Class representing a college student, derived from "Person"
* Faculty    Class representing a college Faculty member, derived from "Person"
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
#include "Student.h"
#include "Faculty.h"
#include "CollegeEnumsDescriptions.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates utilizing an Initialization list in the declaration
* of Class Constructors. Specifically, the list should be utilized to invoke
* a Base Class Constructor when the Class is a derived, "Child" Class of a
* Base Class.
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


	cout << "Textbook Example Program 11-21App:\n"
		<< "     Protected Data Members" << endl << endl;


	// Example #1A: Create/Initialize a "Faculty" object
	cout << "Example #1A: Create/Initialize a \"Faculty\" object" << endl;
	Faculty prof("Indiana Jones", ARCHEOLOGY);

	// Example #1B: Display the "Faculty" object
	cout << "\nExample #1B: Display the \"Faculty\" object" << endl;
	cout << "  Professor " << prof.getName() << " teaches "
		<< dName[prof.getDepartment()] << "." << endl;


	// Example #2A: Create/Initialize a "Student" object
	cout << "\n\nExample #2: Create/Initialize a \"Student\" object" << endl;
	Student st("Sean Bolster", ARCHEOLOGY, &prof);
		  

	// Example #2B: Display the "Student" object
	cout << "\nExample #2B: Display the \"Student\" object" << endl;
	//Get student's advisor
	Person* pAdvisor = st.getAdvisor();
	cout << endl << st.getName() << ".\n"
		 << "  The student's advisor is " << pAdvisor->getName() << "." << endl;
		  

   // This prevents the Console Window from closing during debug mode
   cin.ignore(cin.rdbuf()->in_avail());
   cout << "\nPress only the 'Enter' key to exit program: ";
   cin.get();

   return NO_ERRORS;

}	// End Method: main()