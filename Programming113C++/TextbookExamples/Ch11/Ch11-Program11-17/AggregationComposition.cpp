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
* Program: 11-17
*
* Solution/Project Name: Ch11-Program11-17
*             File Name: AggregationComposition.cpp
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
*   1.0     04/07/2015  Initial Release
*
* UDTs Utilized
*--------------
*   Name                                     Description
* --------  -------------------------------------------------------------------
* Country   A Class that represents a Country.
* Person    A Class that exhibits Class Composition by owning a "Date"
*           data member and Aggregation of a Class "Country" object, but
*           does not control the lifetime of the object.
* Date      A data member in the "Person" Class: Encapsulates Month, day, and
*           year in a Class object.
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
#include <string>
#include "Country.h"
#include "Person.h"

using namespace std;
// This program illustrates aggregation, composition
// and object lifetimes.

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates both Aggregation and Composition of objects as data
* members in a Class. The example Class, "Person" contains a pointer to a
* Class object, "Country", and does not control lifetime of the object; i.e.
* it is NOT destroyed when the "Person" object goes out of scope. In addition,
* the "Person" class contains a Class object, "Date", which is an example of
* Aggregation, since the object goes out of scope when the "Person" object
* goes out of scope.
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


	cout << "Textbook Example Program 11-17:\n"
		<< "  Aggregation and Composition" << endl << endl;


	// Example #1: Create a Country object
	cout << "Example #1: Create a \"Country\" object" << endl;
     Country usa("USA");

     // Example #2; Create a Person object via dynamic memory allocation
	 cout << "\nExample #2: Create a \"Person\" object via dynamic memory allocation"
		  << endl;
	 Person* person1 = new Person("Peter Lee", "January", 1, 1985, &usa);

     // Example #3: Create another Person object, as a static object
	 cout << "\nExample #3: Create a second \"Person\" object as a static object"
		  << endl;
	 Person person2("Eva Gustafson", "May", 15, 1992, &usa);
     cout << "  Now there are two people.\n";

     // Exaample #4: Delete the first person, a pointer to "Person"
	 cout << "\nExample #4: Delete the first person, a pointer to \"Person\""
		  << endl;
	 delete person1;
     cout << "\nNow there is only one \"Person\" object.\n";


	 // This prevents the Console Window from closing during debug mode
	 cin.ignore(cin.rdbuf()->in_avail());
	 cout << "\nPress only the 'Enter' key to exit program: ";
	 cin.get();

	 // The second person will go out of scope when "main()" returns
	 return NO_ERRORS;

}	// End Method: main() 
