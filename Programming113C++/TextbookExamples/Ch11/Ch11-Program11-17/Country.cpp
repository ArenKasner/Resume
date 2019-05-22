/******************************************************************************
*      Class: Country
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
*  Methods                          Description
* ---------  ------------------------------------------------------------------
* Country    Sets the name of the country
* ~Country   Class Destructor
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
#include "Country.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program



//**************************************************
// Initializing Constructor                        *
// Sets object's country name.                     *
// Includes a display statement to show when the   *
// Constructor is called.                          *
//**************************************************
Country::Country(string name) : countryName(name)
{
	cout << "  A Country object has been created.\n";
}


//**************************************************
// Class Destructor                                *
// No action, except to a display statement to     *
// show when the Destructor is called.             *
//**************************************************
Country::~Country()
{
	cout << "  A Country object has been destroyed.\n";
}
