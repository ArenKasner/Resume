#pragma once

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
* Class Description
* -----------------
* This Class is an example class to demonstrate Conversion Operators.
* The class contains an "int" variable, the length of the Class object. Two
* conversions are available, one to convert the "Length" object to an "int"
* value and the other to convert the "int" length, class variable value to a
* "double" value in feet.
*
*
* ----------------------------- Public Interface ------------------------------
*       Method                               Description
* ------------------  ---------------------------------------------------------
* Length              Default Constructor: Set length to 0.
* IntArray            Initializing Constructor: Feet, inches to "lengthInches"
* IntArray            Conversion Constructor: inches to "Length" object
* setLength           Validates and sets object's "lengthInches" variable
* getInches           RETurns residual inches of "lengthInches" in feet
* getFeet             RETurns number of whole feet in "lengthInches" variable
* operator(double)    Conversion Operator: "Length" to "double"
* operator(int)       Conversion Operator: "Length" to "int"
* operator+           Overloaded Addition Operator for two "Length" objects
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
* non-static  int   lengthInches  Total length of object, in inches
*
*
* --------------------------- Public Data Members -----------------------------
*             Data
*    Type     Type        Name                      Description
* ----------  ----  ----------------  -----------------------------------------
* static      int   INCHES_PER_FOOT  Conversion factor: inches per foot
*
*******************************************************************************
*/
// External Definition files
#include <iostream>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

class Length
{ 
private:
	// 1. Non-static (instance) Variable Declarations
	int lengthInches;

public:
	// 1. Constructors
	//    A. Default Constructor
	Length() : lengthInches(0)
	{ }
	//    B. Initializing Constructor
	Length(int feet, int inches) : lengthInches(0)
    {
        setLength(feet, inches);
    }
	//    C. Conversion Constructor: "int" to "Length"
	Length(int inches) : lengthInches(0)
	{
		setLength(0, inches);
	}
	//
	// 2. Mutator Methods
	//    A. SetLength(int,int)
	void setLength(int feet, int inches);
	//
	// 3. Observer methods
	//    A. getFeet()
	int getFeet() const
	{
		return lengthInches / INCHES_PER_FOOT;
	}
	//    B. getInches()
    int getInches() const
	{
		return lengthInches % INCHES_PER_FOOT;
	}
	//
    // 4. Type conversion Operators
	//    A. "Length" to "double"
    operator double() const;
	//    B. "Length" to "int"
	operator int() const
	{
		return lengthInches;
	}
	//
	// 5. Friend Methods
	//    A. Overloaded Operators
	//       i. Addition
	friend Length operator+(Length l, Length r);
    //       ii. Stream Insertion Operator
    friend ostream &operator<<(ostream &out, Length a);
	//
	// 6. Public "static const" Value Declarations
	static const int INCHES_PER_FOOT;
};


