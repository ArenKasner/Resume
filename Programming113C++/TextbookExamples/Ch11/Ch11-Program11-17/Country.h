#pragma once

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
* Class Description
* -----------------
* This Class is an example class to provide an object to demonstrate Aggregation
* of an object of this class as a data member within another class.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                               Description
* --------  -------------------------------------------------------------------
* Country   Initializing Constructor: "string" name of the Country
* ~Country  Class Destructor
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
*    Type      Type       Name                      Description
* ----------  ------  ------------  -------------------------------------------
* non-static  string  countryName   Name of the Country
*
*
* --------------------------- Public Data Members -----------------------------
*                          *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include <string>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

class Country
{
private:
	// 1. Non-static (instance) Variable Declarations
	string countryName;

public:
	// 1. Constructors
	//    A. Initializing and Conversion Constructor
	Country(string name);
	//
	// 2. Class Destructor
	~Country();
};
