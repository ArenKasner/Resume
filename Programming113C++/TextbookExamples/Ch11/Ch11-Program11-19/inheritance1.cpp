#pragma once

// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "inheritance1.h"


/******************************************************************************
*      Class: Student
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/09/2015  Initial Release
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
* ---------  ------------------------------------------------------------
* Student    Initializing Constructor
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
//********************************************* 
// Constructor for the Student class.         *
//*********************************************
Student::Student(string name, Discipline discipline, Person* advisor)
{
	cout << "   Class \"Student\" Initializing Constructor invoked:\n"
		<< "           \"name\": " << name << endl
		<< "     \"discipline\": " << discipline << " (enum value)\n"
		<< "        \"advisor\": " << advisor << " (hex)" << endl;
		// Access the  protected member name
	this->name = name;

	// Access the other members
	major = discipline;
	this->advisor = advisor;

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



/******************************************************************************
*      Class: Faculty
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/09/2015  Initial Release
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
* ---------  ------------------------------------------------------------
* FAculty    Initializing Constructor
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
//********************************************* 
// Constructor for the Faculty class.         *
//*********************************************
Faculty::Faculty(string fname, Discipline department)
{
	cout << "  Class \"Faculty\" Initializing Constructor invoked:\n"
		<< "          \"name\": " << fname << endl
		<< "    \"department\": " << department << " (enum value)" << endl;

	// Die=rectly access the protected base class member
	name = fname;  // Same as: this->name = fname;

	this->department = department;

}
