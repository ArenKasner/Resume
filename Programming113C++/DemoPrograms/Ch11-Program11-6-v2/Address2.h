#pragma once

/******************************************************************************
*      Class: Address2
* Base Class: None
*
* Programmer: Robert Main

* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
*
* Class Description
* -----------------
* This Class is an example class to demonstrate overriding the Class Copy
* Constructor. In thsi case, since there are no Class pointers assigned
* addresses of dynamically allocated memory, the implementation is identical
* to that of the compiler supplied Copy Constructor. In addition, an overridden
* version of the Assignment Operator is provided. For the same reason as that
* for the Copy Constructor, the implementation is identical to that of the
* compiler supplied, default Assignment Operator.
*
* The only additional code aded to these two methods is a display statement for
* demonstration purposes only, to show when these two methods are invoked for
* the various Client code examples.
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
// External Definition files
#include <string>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

class Address2
{
private:
	// 1. Non-static (instance) Variable Declarations
	string street;

public:
	// 1. Class Default Constructor
	Address2()
	{ street = ""; }
	//
	// 2. Class Initializing Constructor
	Address2(string st)
	{ setStreet(st); }
	//
	// 3. Class Copy Constructor
	Address2(const Address2& source);

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

	// 6. Overloaded Operators
	//    A. Assignment
	Address2 operator= (Address2& rValue);
};