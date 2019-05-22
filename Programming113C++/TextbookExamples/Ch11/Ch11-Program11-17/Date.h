#pragma once

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
* Class Description
* -----------------
* This Class is an example class to provide an object to demonstrate Composition
* of an object of this class as a data member within another class.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                               Description
* -------  -------------------------------------------------------------------
* Date     Initializing Constructor: month, day, and unique ID for person
* ~Date    Class Destructor
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
*    Type      Type      Name                      Description
* ----------  ------  ----------  -------------------------------------------
* non-static  string  month       Month person was born
* non-static  int     year        Year person was born
* non-static  int     day         Day person was born
* non-static  int     personID    Unique ID for the person
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


class Date
{
private:
	// 1. Non-static (instance) Variable Declarations
	string month;   // Month person was born
	int year;       // Year person was born
	int day;        // Day person was born
	int personID;   //ID of person whose birthday this is.

public:
	// 1. Constructors
	//    A. Initializing Constructor
	Date(string m, int d, int y, int id);
	//
	// 2. Class Destructor
	~Date();
};
