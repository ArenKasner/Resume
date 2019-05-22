#pragma once

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
* Class Description
* -----------------
* This Class is an example class to provide an object to demonstrate Composition
* of an object of this class as a data member within another class.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                               Description
* -------  -------------------------------------------------------------------
* Person   Initializing Constructor:Person's name, date of birth, Country of
*          birth.
* ~Person  Class Destructor
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*               Data
*    Type       Type       Name                      Description
* ----------  --------  ------------  -------------------------------------------
* non-static  string    personName    Person's name
* non-static  Date      dateOfBirth   Month, Year, and Day person was born
* non-static  Country*  pCountry      Pointer to object that represents Country
*                                     of birth.
* static      int       personID      Unique ID for next person object
*
*
* --------------------------- Public Data Members -----------------------------
*                          *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include <string>
#include "Date.h"
#include "Country.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


class Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	string personName;   // Name of the person
	Date dateOfBirth;    // Person's date of birth (Composition)
	int personID;        // Person identification number (PID)
	Country *pCountry;   // Pointer to a "Country" object (Aggregation)
	//
	// 2. Static Variable Declaration
	static int uniquePersonID; // Used to generate PIDs

public:
	// 1. Constructors
	//    A. Initializing Constructor
	Person(string name, string month, int day, int year, Country *pC);
	//
	// 2. Class Destructor
	~Person();
};
