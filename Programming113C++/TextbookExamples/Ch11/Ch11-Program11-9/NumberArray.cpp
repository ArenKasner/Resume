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
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
* None
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "NumberArray.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


//********************************************************************
// Initializing Constructor                                          *
// Initially, assume "size" is not valid. Set the instance variables *
// to indicate no array has been created. If the "size" is valid,    *
// then allocate memory for the array, fill all rray elements with   *
// specified value, and set the instance variable "arraySize".       *
//********************************************************************
NumberArray::NumberArray(int size, double value) : arrayPntr(NULL), arraySize(0)
{
	if (size > 0)
	{
		arraySize = size;
		arrayPntr = new double[arraySize];

		setValue(value);
	}
}


//**********************************************
// Copy constructor                            *
//**********************************************
NumberArray::NumberArray(const NumberArray& obj)
{
	// 1. Set the size of "this" object's array
	arraySize = obj.arraySize;
	// 2. Allocate memmory for "this" object's array
	arrayPntr = new double[arraySize];
	// 3. Set the element values in "this" object's array to the
	//    corresponding element values in the "obj" array
	for (int index = 0; index < arraySize; index++)
		arrayPntr[index] = obj.arrayPntr[index];
}


//**********************************************
// Class Destructor                            *
// Deallocates Heap Memory allocated for array *
//**********************************************
NumberArray::~NumberArray()
{
	if (arrayPntr != NULL)
		delete[] arrayPntr;
}

//*****************************************************
// Method: setValue(double)                           *
// Sets the value stored in all elements of the array *
//*****************************************************
void NumberArray::setValue(double value)
{
  for(int index = 0; index < arraySize; index++)
	  arrayPntr[index] = value;
}


//****************************************
// Nethod: print()                       *
// Prints all the elements of the array. *
//****************************************
void NumberArray::print() const
{
	// Start the display with the left "bracket" character
	cout << '[';

	if (arraySize > 0)
	{
		// Solve the "fencepost" issue
		// 1. "Plant" the first "Post", namely display the first array
		//     element value
		cout << *arrayPntr;

		// Now display the remaining "paired", "Rails" and "Posts",
		// namely the separator characters (Rail) and the next array
		// element value (Post).
		for (int index = 1; index < arraySize; index++)
			cout << ", " << arrayPntr[index];
	}

	// Finally, conclude with the terminating, right "bracket" character
	cout << ']';

}	// End Method: print()


//***************************************************
// Operator: Assignment                             *
//***************************************************
NumberArray NumberArray::operator=(const NumberArray& rValue)
{
	if (this != &rValue)
	{
		// Not assigning an object to itself...
		// See if a new array needs to be allocated. The only case for which
		// the current array is adeqaute is if its size it the same as the
		// "rValue" object's array size
		if (arrayPntr == NULL || rValue.arraySize != arraySize)
		{
			// Need to allocate a new array..
			// Deallocate the memory for the current array iff (if and only if)
			// an array has been allocated.
			if (arrayPntr != NULL)
				delete[] arrayPntr;
			// Now create the new array, the same size as the "rValue" object's
			// array
			arrayPntr = new double[rValue.arraySize];
		}

		// Update the 
		arraySize = rValue.arraySize;

		for (int index = 0; index < arraySize; index++)
			arrayPntr[index] = rValue.arrayPntr[index];

	}	// End if: Not assigning a Class object to itself

	return *this;

}	// End Operator: Assignement
