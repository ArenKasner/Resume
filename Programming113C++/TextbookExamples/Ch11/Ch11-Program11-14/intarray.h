#pragma once

/******************************************************************************
*      Class: IntArray
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/02/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate overloading the [] Operator for
* a class that encapsulates an array of integer values.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                          Description
* ---------------  ------------------------------------------------------------
* IntArray         Initializing Constructor: size of the array
* IntArray         Copy Constructor
* ~IntArray        Class Destructor
* size             RETurns thge size (number of elements) in the array
* operator[]       Overloaded element access Operator
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
* subError  Tests for subscript error; exits program if out of range
*
*
* -------------------------- Private Data Members -----------------------------
*             Data
*    Type     Type     Name                    Description
* ----------  ----  ----------  -----------------------------------------------
* non-static  int*   arrayPntr  Pointer: Dynamically allocated array
* non-static  int    arraySize  Size of the array
*
*******************************************************************************
*/
class IntArray
{
private:
	// 1. Non-static (instance) Variable Declarations
	int* arrayPntr;
	int arraySize;

	// 2. Non-static Methods
	//    A. subError(int)
	//       Checks array subscript for valid values
	void subError(int subscript) const;  // Handles subscripts out of range

public:
	// 1. Constructors
	//    A. Default Constructor
	IntArray() : arrayPntr(NULL), arraySize(0)
	{ }
	//    B. Initializing Constructor
	IntArray(int);
	//    C. Copy Constructor
	IntArray(const IntArray& source);
	// 2. Class Destructor
	~IntArray();
	//
	// 3. Class Mutator Methods
	//    A. Operator: []
	int& operator[](int) const;
	IntArray operator=(const IntArray& rValue);
	//
	// 4. Class Observer Methods
	//    A. Method: size()
	int size() const
	{ return arraySize; }
};
