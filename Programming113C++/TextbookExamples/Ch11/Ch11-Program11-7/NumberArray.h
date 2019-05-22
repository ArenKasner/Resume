#pragma once

/******************************************************************************
*      Class: NumberArray
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate the various requirements of
* Class methods when the class has non-static pointer data members that are
* assigned memory addresses of dynamically allocated memory for Class objects
* or arrays.
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* NumberArray      Default Constructor: No elements, array pointer set to NULL
* NumberArray      Constructor: Size of array and set value for all elements
* setValue         Sets all array elements to specified value
* print            Displays all array element values
* arrayAddress     RETurns a copy of the pointer (address) to array of "double"
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
*
*
* ---------------------------- Private Data Members ---------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
* non-static  double*   arrayPntr   Pointer: Dynamically allocated array
* non-static  int       arraySize   Size (number of elements) in the array
*
*******************************************************************************
*/

class NumberArray
{
private:
	// 1. Non-static (instance) Variable Declarations
	double* arrayPntr;
	int arraySize;

public:
	// 1. Constructors
	//    A. Default Constructor
	NumberArray() : arrayPntr(NULL), arraySize(0)
	{ }
	//    B. Initializing Constructor
	NumberArray(int size, double value);
	//
	// 2. Class Destructor
	//    Commented out to avoid problems with the default Copy Constructor
//  ~NumberArray()
//	{ if (arrayPntr != NULL)
//		delete [ ] arrayPntr;
//	}

	// 3. Class Mutator Methods
	//    A. Method: setValue(double)
	//       Fills all elements in the array with the supplied value
	void setValue(double value);

	//
	// 4. Class Observer Methods
	//    A. Method: print()
	//       Displays all elements in the array
	void print() const;
	//    B. Method: arrayAddress()
	//       RETurns the address of the object's array
	double* arrayAddress() const
	{
		return this->arrayPntr;
	}
};