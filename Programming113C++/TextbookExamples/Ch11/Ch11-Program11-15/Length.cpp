/******************************************************************************
*      Class: Length
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/03/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*   Public Methods                          Description
* -----------------  ------------------------------------------------------------
* setLength          Sets the length for the object
* operator double()  Converts a "Length" object to "double"
* operator+          Adds two "Length" objects to produce a third "Length" object
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                          *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*            Data
*  Type      Type           Name                    Description
* ------  ----------  ----------------  ---------------------------------------
* static  const int   INCHES_PER_FOOT   Conversion constant: inches per foot
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Length.h"

//**************************************************
// Constant: INCHES_PER_FOOT                       *
// Initialization                                  *
//**************************************************
const int Length::INCHES_PER_FOOT = 12;


//**************************************************
// Method: setLength                               *
// Validates and sets the object's length variable *
//**************************************************
void Length::setLength(int feet, int inches)
{
	if (feet >= 0  &&  inches >= 0)
		lengthInches = INCHES_PER_FOOT * feet + inches;
}

//**************************************************
// Operator double()                               *
// Converts "Length" to "double"                   *
//**************************************************
Length::operator double() const
{
	double factor = static_cast<double>(INCHES_PER_FOOT);

	return lengthInches / INCHES_PER_FOOT +
		(lengthInches % INCHES_PER_FOOT) / factor;
}

//*************************************************
// operator<<                            (friend) *                        
// Overloaded Insertion Operator                  *
//*************************************************
ostream &operator<<(ostream& out, Length a)
{
    out << a.getFeet() << " feet, " << a.getInches() << " inches";
    return out;
}

//************************************************
// operator+                            (friend) *
// Overloaded Addition Operator                  *
//************************************************
Length operator+(Length left, Length right)
{
	return Length(left.lengthInches + right.lengthInches);
}
