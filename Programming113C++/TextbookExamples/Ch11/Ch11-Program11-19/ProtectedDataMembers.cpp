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
* Program: 11-19
*
* Solution/Project Name: Ch11-Program11-19
*             File Name: ProtectedDataMembers.cpp
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
*   1.0     04/01/2015  Initial Release
*
* UDTs Utilized
*--------------
*     Name                                     Description
* ------------  ---------------------------------------------------------------
* NumberArray   Example Class that provides an overridden Copy Constructor and
*               an overriden Assignment Operator.
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
#include "inheritance1.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program


// These arrays of string are used to print
// values of enumerated types
const string dName[] =  
       {"Archeology", "Biology", "Computer Science" };

const string cName[] = 
       {"Freshman", "Sophomore", "Junior", "Senior" };

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the declaration and use of "protected" Class
* members, a data member in this case, when inheritance occurs. The Base Class
* can declare its data members as "protected", which allows derived, "Child"
* classes direct access to the Base Class data members, without the need to
* utilize Base Class methods to access or modify the Base Class data members.
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


	cout << "Textbook Example Program 11-19:\n"
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