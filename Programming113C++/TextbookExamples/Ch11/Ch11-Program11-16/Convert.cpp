/******************************************************************************
*      Class: IntClass
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/06/2015  Initial Release
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
* IntArray
* IntArray         Copy Constructor
* operator=        Overloaded Assignment Operator
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
* subError  Tests for subscript error; exits program if out of range
*
*
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
*                         *** No Initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Convert.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


IntClass::IntClass(const IntClass& source)
{
	cout << "  Copy Constructor called" << endl;
	value = source.value;
}

IntClass::IntClass(int intValue) : value(intValue)
{
	cout << "  Conversion Constructor called, with value: " << value << endl;
}



IntClass IntClass::operator=(IntClass rValue)
{
	cout << "  Assignment Operator called" << endl;
	value = rValue.value;

	return *this;
}
