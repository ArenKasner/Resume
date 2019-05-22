/******************************************************************************
*      Class: TFaculty
* Base Class: Faculty
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/12/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                          Description
* --------  -------------------------------------------------------------------
* TFaculty  Initializing Constructor
* getName   Overrides the Base Class method to prefix the name with a title
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
* setTitle  Validates/sets the object's "title" data member
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
#include "TFaculty.h"


//*******************************************************************
// Initialializing Constructor for the Faculty class                *
// 1. Base Class Initialization in initialization list              *
// 2. "title" set in the initialization list to an "empty" string.  *
//     In the body of the Constructor, a "private" method is called *
//     to validate the "title" string passed to the Constructor.    *
//*******************************************************************
TFaculty::TFaculty(string fname, Discipline d, string title) :
Faculty(fname, d), title("")
{
	setTitle(title);
}


//*************************************************************
// Mutator Method: setTitle                                   *
// This method can be used to test the validity of a "string" *
// passed to the method for allowed titles for a "TFaculty"   *
// member. In this exmple, no tests are done.                 *
//************************************************************
void TFaculty::setTitle(string title)
{
	this->title = title;
}


//***************************************************************
// Observer Method: getName                                     *
// This method overrides the method of the same signature in    *
// the Bsse Class: "Person"                                     *
// Prefixes the "TFaculty" object's title string to the faculty *
// members name, obtained via invoking the Base Class' method.  *
//***************************************************************
string TFaculty::getName() const
{
	return title + " " + Person::getName();
}
