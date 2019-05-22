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
* Program: 11-21
*
* Solution/Project Name: Ch11-Program11-21
*             File Name: OverriddenMethod.cpp
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
*   1.0     04/09/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* TFaculty  Example Class that inherits from a Base Class
* Student   Example Class that inherits from a Base Class and demonstrates
*           overridding of a Base Class method
* Person    The Base Class for "Child" Classes "Faculty" and "Student". Some of
*           its methods are invoked by objects of the "Child" classes
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
#include "Person.h"
#include "TFaculty.h"
#include "Student.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the overriding a Base Class method in a derived,
* "Child" Class.
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


	cout << "Textbook Example Program 11-21:\n"
		 << "Overriding a Base Class Method" << endl << endl;


	// Example #1A: Create/Initialize a "TFaculty" object
	cout << "Example #1A: Create/Initialize a \"TFaculty\" object" << endl;
	TFaculty prof("Indiana Jones", ARCHEOLOGY, "Dr.");

	// Example #1B: Display the "Faculty" object
	cout << "    " << prof.getName() << " teaches "
		<< dName[prof.getDepartment()] << "." << endl;


	// Example #2A: Create/Initialize a "Student" object
	cout << "\n\nExample #2A: Create/Initialize a \"Student\" object" << endl;
	Student st("Sean Bolster", ARCHEOLOGY, &prof);

	// Example #2B: Display the "Student" object
	cout << "\nExample #2B: Display the \"Student\" object" << endl;
	//Get student's advisor
	Person *pAdvisor = st.getAdvisor();
	// Now utilze just the "Person" method, "getName()".
   cout << "  " << st.getName() <<"\'s advisor is " << pAdvisor->getName() << "." << endl;


   // This prevents the Console Window from closing during debug mode
   cin.ignore(cin.rdbuf()->in_avail());
   cout << "\nPress only the 'Enter' key to exit program: ";
   cin.get();

   return NO_ERRORS;

}	// End Method: main()