/******************************************************************************
*      Class: Student
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/10/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*  Methods                          Description
* -------  --------------------------------------------------------------------
* Student  Initializing Constructor
* getName  Overridden version of the Base Class method
* 
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                          *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*                          *** No Initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Student.h"


//***************************************************************
// Initializing Constructor                                     *
// 1. Invoke Base Class Initializing Constructor                *
// 2. Set the object's "major" data member                      *
// 3. Set the object's "advisor" data member                    *
//    Note: The compiler can distinguish the argument "advisor" *
//          from the data member "advisor"                      *
//***************************************************************
Student::Student(string name, Discipline discipline, Person* advisor) :
	// Initializaton list follows
	Person(name), major(discipline), advisor(advisor)
{
	cout << "   Class \"Student\" Initializing Constructor invoked:\n"
		<< "           \"name\": " << name << endl
		<< "     \"discipline\": " << discipline << " (enum value)\n"
		<< "        \"advisor\": " << advisor << " (hex)" << endl;
}

//********************************************* 
// Method: getName()                          *
// RETurns the "string" name of the student   *
// Note: Overrides the Base Class method      *
//*********************************************
string Student::getName() const
{
	cout << "  Class \"Student\" method \"getName\" invoked" << endl;

	// Invoke the Base Class method to get just the student's name
	return  "  The student's name is " + Person::getName();
}

