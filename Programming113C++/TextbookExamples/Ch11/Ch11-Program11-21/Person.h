#pragma once

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
* Class Description
* -----------------
* This Class is serves as the Base Class for two separate Classes, "Student"
* and "Faculty: that both contain the functionalty and data of this Class; i.e.
* both those classes exhibit an "is a" relationship with this class.
*
* In this version, the Class data member is declared as a "proected" member of
* the Class. This allows any derived, "Child" class of this class to directly
* access the data member. Of course, the Client of this class can NOT access
* the data member.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                               Description
* --------  -------------------------------------------------------------------
* Person    Initializing and Conversion Constructor: Set person's name
* getName   RETurns the "Person" object's name
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type   Name                    Description
* ----------  ------  ----  ---------------------------------------------------
* non-static  string  name  Person's name
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include <string>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


class Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	string name;

public:
	// 1. Constructors
	//    A. Initializing/Conversion Constructor
	Person(string pName);
	//
	// 2. Observer methods
	//    A. getName()
	string getName() const;
};
