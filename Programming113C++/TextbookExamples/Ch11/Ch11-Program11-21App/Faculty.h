#pragma once

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
* Class Description
* -----------------
* This Class inherits from the Base Class, "Person". It thus contains all the
* functionality of that Class; i.e. it "contains" the public methods of that
* Class. The non-static data members of Class "Person" are declared "protected";
* therefore, member methods of this, the inherited or "child" Class do have
* access to them.
*
*
* ----------------------------- Public Interface ------------------------------
*     Method                               Description
* --------------  -------------------------------------------------------------
* Faculty         Initializing Constructor: Set name, major, and advisor
* getDepartment   RETurns the "Faculty" object's Department (enum value)
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*                Data
*    Type        Type            Name                  Description
* ----------  ----------  ----------  -----------------------------------------
* non-static  Discipline  department   Faculty member's department (enum value)
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include "Person.h"
#include "CollegeEnumsDescriptions.h"


class Faculty : public Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	Discipline department;

public:
	// 1. Constructors
	//    A. Initializing Constructor
	Faculty(string fname, Discipline d);

	//
	// 2. Observer methods
	//    A. getDepartment()
	//       RETurns object's department, a college discipline
	Discipline getDepartment() const
	{
		return department;
	}
};