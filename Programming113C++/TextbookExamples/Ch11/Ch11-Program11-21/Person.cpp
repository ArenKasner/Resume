/******************************************************************************
*      Class: Person
* Base Class: None
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
* Person   Initializing Constructor
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
#include "Person.h"


//***************************************** 
// Initializing/Conversion Constructor    *
// 1. Set the object's "name" data member *
//*****************************************
Person::Person(string pName)
{
	cout << "  Class \"Person\" Initializing Constructor invoked: "
		<< pName << endl;
	name = pName;
}


//*******************************************************
// Observer Method: getName                             *
// 1. RETurns a copy of the object's "name" data member *
//*******************************************************
string Person::getName() const
{
	cout << "  Class \"Person\" method \"getName\" invoked" << endl;

	return name;
}

