#pragma once

/******************************************************************************
*      Class: NumberArray
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
* NumberArray      Copy Constructor: Allocates array memory, copies values
* ~NumberArray     Class Destructor: Deallocates memory used for array
* setValue         Sets all array elements to specified value
* print            Displays all array element values
* operator=        Overridden Assignment Operator
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                          *** No private Methods ***
*
*
* -------------------------- Private Data Members -----------------------------
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
	double *arrayPntr;  // Pointer to allocated array
	int arraySize;      // Size of (number of elements in) the array

public:
	// 1. Constructors
	//    A. Default Constructor
	NumberArray() : arrayPntr(NULL), arraySize(0)
	{ }
	//   B. Initializing Constructor
	NumberArray(int size, double value);
	//   C. Copy Constructor
	NumberArray(const NumberArray &);
	//
	// 2. Class Destructor
	~NumberArray();

	// 3. Overloaded Operators
	//    A. Assignment Operator
	NumberArray operator=(const NumberArray &rValue);

	// 4. Class Mutator Methods
	//    A. Method: setValue(double)
	//       Sets all array elements to the specified value
	void setValue(double value);

	// 5. Class Observer Methods
	//    A. Method: print()
	//       Displays all array element values
	void print() const;
};