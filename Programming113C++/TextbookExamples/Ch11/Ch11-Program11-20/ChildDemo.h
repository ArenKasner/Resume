#pragma once

/******************************************************************************
*      Class: ChildDemo
* Base Class: BaseDemo
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
* Constructor when an object of this class, which is derived from a Base Class,
* is instantiated and then the sequence of the invocation of the Destructors
* when the object goes out of scope.
*
*
* ----------------------------- Public Interface ------------------------------
*   Method                               Description
* ----------  -----------------------------------------------------------------
* ChildDemo   Default Constructor: Display message to show when it is invoked
* ~ChildDemo  Class Destructor: Display message to show when it is invoked
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
#include "BaseDemo.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

class ChildDemo : BaseDemo
{
public:
	// 1. Constructors
	//    A. Default Constructor
	ChildDemo()
	{
		// Display a message to show when the Constructor is invoked
		cout << "  This is the \"ChildDemo\" Default Constructor.\n";
	}
	//
	// 2. Class Destructor
	~ChildDemo()
	{
		// Display a message to show when the Destructor is invoked
		cout << "  This is the \"ChildDemo\" Class Destructor.\n";
	}
};
