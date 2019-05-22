/******************************************************************************
*      Class: Address2
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* Address2         Default Constructor: "empty" street address "string"
* Address2         Constructor: Street address supplied
* Address2         Copy Constructor: Same as Default Copy Constructor
* setStreet        Changes the street address "string" data member
* getStreet        RETurns a copy of the "string" data member
* operator=        Overridden Assignment Operator
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                          *** No private Methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
* None
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Address2.h"
#include <iostream>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


// External Class Method Definitions
// 1. Constructors
//    A. Copy Constructor: Address2(const Address2&)
//       Note: Support Constant objects!
Address2::Address2(const Address2& source)
{
	street = source.street;
	cout << "  Copy Constructor called" << endl;
}
//
// 2. Overloaded Operators
//    A. Assignment: operator= (Address2& )
Address2 Address2::operator= (Address2& rValue)
{
	this->street = rValue.street;
	cout << "  Assignment Operator called" << endl;

	// RETurn "this" object to allow it to be the "rValue" for
	// Assignment "chaining".
	// Note: To obtain the object itself, a Copy of "this" objeect
	//       must be made. Equivalent to: Address2(*this) 
	return *this;

}	// End Operator: Assignment
