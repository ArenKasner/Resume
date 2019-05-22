#pragma once

/******************************************************************************
*      Class: BaseDemo
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
* This Class is an example class to demonstrate the invocation sequence of a
* Constructor when an object of a class derived from this class and the
* sequence of the invocation of the Destructors when the object goes out of
* scope.
*
*
* ----------------------------- Public Interface ------------------------------
*   Method                               Description
* ----------  -----------------------------------------------------------------
* BaseDemo    Default Constructor: Display message to show when it is invoked
* ~BaseDemo   Class Destructor: Display message to show when it is invoked
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*             Data
*    Type     Type      Name                    Description
* ----------  ----  ------------  ---------------------------------------------
*                         *** No private data members ***
*
*
* --------------------------- Public Data Members -----------------------------
*             Data
*    Type     Type        Name                      Description
* ----------  ----  ----------------  -----------------------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include <iostream>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

class BaseDemo
{
public:
	// 1. Constructors
	//    A. Default Constructor
	BaseDemo()
	{
		// Display a message to show when the Constructor is invoked
		cout << "  This is the \"BaseDemo\" constructor.\n";
	}
//
	// 2. Class Destructor
	~BaseDemo()
	{
		// Display a message to show when the Destructor is invoked
		cout << "  This is the \"BaseDemo\" destructor.\n";
	}
};
