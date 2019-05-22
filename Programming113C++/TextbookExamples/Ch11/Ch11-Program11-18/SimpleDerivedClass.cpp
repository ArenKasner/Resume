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
* Program: 11-18
*
* Solution/Project Name: Ch11-Program11-18
*             File Name: SimpleDerivedClass.cpp
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
* Faculty   Example Class that inherits from a Base Class
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
#include "inheritance.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the simple concepts associated with two Classes
* that inherit functionality from a Base Class. In addition, the concept of
* overridding a method defined in the Base Class in the derived or "Child" Class
* is demonstrated, including the ability to call the Base Class method from
* within the overridden "Child" Class method, or for that matter, from any
* method in the "Child" Class.
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

	// These arrays of string are used to print the
	// enumerated types.
	const string dName[] = {
		"Archeology", "Biology", "Computer Science"
	};

	const string cName[] = {
		"Freshman", "Sophomore", "Junior", "Senior"
	};

	string name;

	cout << "Textbook Example Program 11-18:\n"
			<< "      Simple Inheritance" << endl << endl;


	// Example #1: Create a Faculty object
	cout << "Example #1: Create a \"Faculty\" object" << endl;
	Faculty professor;

	// Example #2:
	cout << "\nExample #2:"
		 << "\n1. Set \"Faculty\" object's name via a Base Class method" << endl;
	professor.setName("Indiana Jones");
	cout << "\n2. Set the \"Faculty\" object's department via a method in the Child Class"
		 << endl;
	professor.setDepartment(ARCHEOLOGY);
	cout << "\n3. Obtain the \"Faculty\" object's name via a method in the Base Class"
		<< endl;
	name = professor.getName();  // Note: Base Class method invoked!
	cout << "\n4. Get the \"Faculty\" object's department via a method in the Child Class"
		<< endl;
	Discipline dept = professor.getDepartment();
	cout << "\n   Professor " << name
		 << " teaches in the " << "Department of " << dName[dept] << endl;


	// Example #3: Create a Student object
	cout << "\n\nExample #3: Create a \"Student\" object" << endl;
	Student student;

	// Example #4:
	cout << "\nExample #4:"
		<< "\n1. Set \"Student\" object's name via a Base Class method" << endl;
	student.setName("John Doe");

	cout << "\n2. Set the \"Student\" object's Major via a method in the Child Class" << endl;
	student.setMajor(COMPUTER_SCIENCE);
	cout << "\n3. Set the \"Student\" object's Classification via a method in the Child Class"
		 << endl;
	student.setClassification(JUNIOR);
	cout << "\n4. Set the \"Student\" object's Advisor via a method in the Child Class" << endl;
	student.setAdvisor(&professor);
	cout << "\n5. Obtain the \"Student\" object's Name via an OVERRIDDEN method" << endl;
	name = student.getName();
	cout << "\n6. Get the \"Student\" object's Major via a method in the Child Class" << endl;
	Discipline major = student.getMajor();
	cout << "\n7. Get the \"Student\" object's Classification via a method in the Child Class"
		<< endl;
	Classification year = student.getClassification();
	cout << "\n8. Get the \"Student\" object's Advisor, a pointer to  \"Person\"" << endl;
	Person* advisor = student.getAdvisor();

	cout << "\n   " <<  name << '.'
		<< "\n   The student is a " << cName[year] << ", majoring in " << dName[major]
		<< "\n   The student's advisor is " << advisor->getName() << endl;


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()