/******************************************************************************
*      Class: Example
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/01/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*        Method                          Description
* ---------------------  ------------------------------------------------------
* setValue               Set the value of "x"
* printAddressandValue   Display the address and value of data member "x"
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
*                          *** No initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "Example.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

void Example::setValue(int a)
{
	// Minimum and maximum values allowed for data member "x"
	const int MIN_VALUE = 10;
	const int MAX_VALUE = 50;

	if (a >= MIN_VALUE  &&  a <= MAX_VALUE)
		x = a;
}

void Example::printAddressandValue() const
{
	// Note: In a non-static Class method, "this" refers to the address of the
	//       first defined, non-static data member of the object bound to the
	//       method call.
	cout << "The object at address " << this << "(hex) has "
		<< "value " << this->x << endl;
}
