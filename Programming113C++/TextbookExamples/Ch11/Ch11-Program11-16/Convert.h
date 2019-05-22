#pragma once  // Include this file only once in a compilation unit (.cpp file)

/******************************************************************************
*      Class: IntClass
* Base Class: None
*
* This file defines the members of the class: IntClass
* These members include class variable data members, class constant, static
* data members, and class method declarations only and/or class method
* declarations and definitions.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     04/06/2015  Initial Release
*
* Class Description
* -----------------
* This Class utilizes a Conversion Constructor to create an "IntClass" object
* from a an "int" value; the Constructor contains a display mesage to show
* when it is invoked durin the instantiation of an "IntClass" object.
*
* Also, a Copy Constructor and overloaded Assignment Operator are provided to
* display a message when those methods are called.
*
* Class Data Members
* ------------------
*  Name    Scope    Type                     Description
* ------ --------- ------ -----------------------------------------------------
* value  private   int    A data member to demonstrate the Conversion Operator
*
* Class Methods
* -------------
*      Name       Scope                   Description
* -------------- ------- ------------------------------------------------------
* IntClass       Public  Conversion Constructor: "int" to "IntClass"
* IntClass       Public  Copy Constructor
* operator-      Public  Assignment Operator
* getValue()     Public  RETurns a copy of data member "value"
*
*******************************************************************************
*/

class IntClass
{
private:
  int value;

public:
	// 1. Class Constructor(s)
	//    A. Copy Constructor
	IntClass(const IntClass& source);
	//    B. Conversion Constructor: "int" to "IntClass"
	IntClass(int intValue);

	// 2. Observer Methods
	//    A. getValue()
	//       RETurns a copy of data member "value"
	int getValue() const
	{ return value; }
	//
	// 3. Overloaded Operators
	//    A. Assignment Operator
	IntClass operator=(IntClass rValue);
};