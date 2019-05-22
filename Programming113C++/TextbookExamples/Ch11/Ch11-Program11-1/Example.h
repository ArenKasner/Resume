#pragma once

/******************************************************************************
*      Class: Example
* Base Class: None
*
* Programmer: Robert Main

* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/01/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate the use of an object's "this"
* pointer to its data members and the declaration of a Class method as "const".
*
*
* ----------------------------- Public Interface ------------------------------
*        Method                          Description
* ---------------------  ------------------------------------------------------
* Example                Constructor: Initialize data member "x"
* setValue               Set the value of "x"
* printAddressandValue   Display the address and value of data member "x"
*
*
* ----------------------------- Private Methods -------------------------------
*      Name                              Description
* --------------  -------------------------------------------------------------
*                          *** No private Methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*             Data
*    Type     Type  Name                      Description
* ----------  ----  -----  ----------------------------------------------------
* non-static  int   x      Variable, no importance, for demonstration purposes
*
*******************************************************************************
*/
class Example
{
private:
	// 1. Non-static (instance) Variable Declarations
	int x;

public:
	// 1. Initializing Constructor
	Example(int a) : x(a)
	{ }

	// 2. Mutator Methods
	//    A. Method: setValue(int)
	//       Modifies Class Private data member, if conditions met
	void setValue(int);

	// 3. Observer Methods
	//    A. Method: printAddressandValue()
	//       Displays object's data member address and value stored there
	//       Note: Method is declared "const", which is a promise that the
	//             method will NOT modify any Class data member, i.e.
	//             only access data members
	void printAddressandValue() const;
};
