#pragma once

/******************************************************************************
*      Class: Address
* Base Class: None
*
* Programmer: Robert Main

* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate the compiler supplied Copy
* Constructor, since this class does not provide an overridden version.
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* Address          Default Constructor: "empty" street address "string"
* Address          Constructor: Street address supplied
* setStreet        Changes the street address "string" data member
* getStreet        RETurns a copy of the "string" data member
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                          *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type    Name                    Description
* ----------  ------  ------  -------------------------------------------------
* non-static  string  street  Full street address
*
*******************************************************************************
*/

#include <string>
using namespace std;

class Address
{
private:
	// 1. Non-static (instance) Variable Declarations
	string street;

public:
	// 1. Class Default Constructor
	Address()
	{ street = ""; }
	//
	// 2. Class Initializing Constructor
	Address(string st)
	{ setStreet(st); }

	// 4. Class Mutator Methods
	//    A. Method: setStreet(string)
	//       Modifies the object's street address
	void setStreet(string st)
	{ street = st; }

	//
	// 5. Class Observer Methods
	//    A. Method: getStreet()
	string getStreet() const
	{ return street; }
};