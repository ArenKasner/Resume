/******************************************************************************
*      Class: Length
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/02/2015  Initial Release
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
* Length           Constructor: fet and inches supplied
* setLength        Validates "feet" and "inches" arguments, sets "lengthInches"
* operator+        Overloaded Addition Operator
* operator-        Overloaded Subtraction Operator
* operator==       Overloaded Equality Operator
* operator!=       Overloaded Inequality Operator
* operator<        Overloaded "less than" Operator
* operator++()     Prefix Increment
* operator++(int)  Postfix Increment
* operator<<       Stream Insertion Operator
* operator>>       Stream Extraction Operator
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
*                         *** No Initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Length1.h"


//********************************************************************
// Initializing Constructor                                          *
// Initially, assume one or both argument(s) is/are not valid.       *
// Set the instance variable "lengthInches" to 0.                    *
// to indicate no array has been created. Invoke method "setLength"  *
// to validate the arguments before setting "lengthInches".          *
//********************************************************************
Length::Length(int feet, int inches) : lengthInches(0)
{
	// Let method "setLength" ensure the arguments are valid
	setLength(feet, inches);
}


//******************************************
// Method: setLength(int,int)              *
// Validates arguments, set "lengthInches" *
// iff both arguments are valid.           *
//******************************************
void Length::setLength(int feet, int inches)
{
	if (feet >= 0  && inches >= 0)
		lengthInches = INCHES_PER_FOOT * feet + inches;
}


//***********************************************************
// Overloaded operator++()                                  *
// Prefix Increment                                         *
// RETurns: "this" object after incrementing "lengthInches" *
//***********************************************************
Length Length::operator++()
{
	++lengthInches;

	return *this;
}


//**********************************************************************
// Overloaded operator++(int)                                          *
// Postfix Increment                                                   *
// RETurns: A copy of "this" object BEFORE incrementing "lengthInches" *
//**********************************************************************
Length Length::operator++(int)
{
	// First, make a copy of "this" object
	// Invoke the compiler supplied Default Copy Constructor
	Length before(*this);  // Same as: Length before = *this;

	// Now increment "lengthInches"
	++lengthInches;

	// Then RETurn a copy of the object before incrementing "lengthInches"
	return before;
}


//****************************************************************************
// Overloaded operator+ (const Length& left, const Length& right)  "friend"  *
// RETurns: "Length" object: left.lengthInches + right.lengthInches          *
//****************************************************************************
Length operator+(Length left, Length right)
{
	return Length(left.lengthInches + right.lengthInches);
}


//****************************************************************************
// Overloaded operator- (const Length& left, const Length& right)  "friend"  *
// RETurns: "Length" object: left.lengthInches - right.lengthInches          *
//    Note: If "right" > "left", the object RETurned will indicate           *
//          0 feet, 0 inches                                                 *
//****************************************************************************
Length operator-(Length left, Length right)
{
	return Length(left.lengthInches - right.lengthInches);
}


//****************************************************************************
// Overloaded operator== (const Length& left, const Length& right)  "friend" *
// RETurns: "true" if left.lengthInches == right.lengthInches                *
//          "false", otherwise                                               *
//****************************************************************************
bool operator==(Length left, Length right)
{
	return left.lengthInches == right.lengthInches;
}


//****************************************************************************
// Overloaded operator!= (const Length& left, const Length& right)  "friend" *
// RETurns: "true" if left.lengthInches != right.lengthInches                *
//          "false", otherwise                                               *
//****************************************************************************
bool operator!=(Length left, Length right)
{
	return !operator==(left, right);
}


//****************************************************************************
// Overloaded operator< (const Length& left, const Length& right)  "friend"  *
// RETurns: "true" if left.lengthInches < right.lengthInches                 *
//          "false", otherwise                                               *
//****************************************************************************
bool operator<(Length left, Length right)
{
	return left.lengthInches < right.lengthInches;
}


//****************************************************************************
// Overloaded operator<< (ostream& outStream, Length right)        "friend"  *
// Inserts a text description of the "Length" object onto the referenced     *
// "ostream" object.                                                         *
// RETurns: "ostream" reference argument (supports "chaining")               *
//****************************************************************************
ostream& operator<<(ostream& outStream, Length right)
{
	outStream << right.getFeet() << " feet, " << right.getInches() << " inches";

	return outStream;
}


//****************************************************************************
// Overloaded operator>> (istream& inStream, Length& right)        "friend"  *
// Prompts User for inches and feet values, Extracting them from the         *
// "istream" object, then setting the "lengthInches" data member of the      *'
// referenced "Length" object.                                               *
// RETurns: "istream" reference argument (supports "chaining")               *
//****************************************************************************
istream& operator>>(istream& inStream, Length& right)
{
	// Uninitialized Variable Declarations
	int feet;
	int inches;

	// Prompt User for the number of feet
	cout << "Enter number of feet: ";
		inStream >> feet;

	// Prompt User for the number of inches
	cout << "Enter number of inches: ";
	inStream >> inches;

	right.setLength(feet, inches);

	return inStream;
}

