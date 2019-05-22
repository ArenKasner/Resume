/******************************************************************************
*      Class: Faculty
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
* ---------  ------------------------------------------------------------
* Faculty    Initializing Constructor
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
#include "Faculty.h"


//******************************************************************
// Initialializing Constructor for the Faculty class               *
// 1. Base Class Initialization in initialization list             *
// 2. "department" set in initialization list                      *
//    Note: The compiler can distinguish the argument "department" *
//          from the data member "department"                      *
//******************************************************************
Faculty::Faculty(string fname, Discipline department) : // Initializaton list follows
	Person(fname), department(department)
{
	cout << "  Class \"Faculty\" Initializing Constructor invoked:\n"
		<< "          \"name\": " << fname << endl
		<< "    \"department\": " << department << " (enum value)" << endl;

}
