/******************************************************************************
*      Class: Date
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/07/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
* Methods                          Description
* -------  --------------------------------------------------------------------
* Date     Sets birth month, year, and day for person and unique ID
* ~Date    Class Destructor
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                          *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
* None
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Date.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

//*****************************************************
// Initializing Constructor                           *
// Sets object's month, year, and day of birth, along *
// with an unique ID per the person.                  *
// Includes a display statement to show when the      *
// Constructor is called.                             *
//*****************************************************
Date::Date(string m, int d, int y, int id) :
month(m), day(d), year(y), personID(id)
{
	cout << "  Date-Of-Birth object for person "
		<< personID << " has been created.\n";
}


//**************************************************
// Class Destructor                                *
// No action, except to a display statement to     *
// show when the Destructor is called.             *
//**************************************************
Date::~Date()
{
	cout << "  Date-Of-Birth object for person "
		<< personID << " has been destroyed.\n";
}
