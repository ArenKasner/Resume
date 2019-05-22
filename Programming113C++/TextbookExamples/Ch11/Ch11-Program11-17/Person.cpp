/******************************************************************************
*      Class: Person
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
* Person   Sets object's name, date of birth, and country of birth. Also, an
*          unique ID for the object is set and passed to the Constructor for'
*          "Date", Class data member instantiation.
* ~Person  Class Destructor
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
#include "Person.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program


//**************************************************
// Initializing Constructor                        *
// Sets object's name, date of birth, and country  *
// of birth, and also sets the person's unique ID. *
// Includes a display statement to show when the   *
// Constructor is called.                          *
//**************************************************
Person::Person(string name, string month, int day, int year, Country *pC) :
personName(name), dateOfBirth(month, day, year, Person::uniquePersonID),
personID(Person::uniquePersonID), pCountry(pC)
{
	cout << "  Person object "
		<< personID << " has been created.\n";

	// Increment the unique ID for the the next "Person" object to be
	// instantiated.
	Person::uniquePersonID++;
}


//**************************************************
// Class Destructor                                *
// No action, except to a display statement to     *
// show when the Destructor is called.             *
//**************************************************
Person::~Person()
{
	cout << "  Person object "
		<< personID << " has been destroyed.\n";
}


// Initialize the static Class variable
int Person::uniquePersonID = 1; // First "Person" object's unique ID
