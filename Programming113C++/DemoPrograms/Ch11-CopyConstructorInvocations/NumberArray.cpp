/******************************************************************************
*      Class: NumberArray
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/01/2015  Initial Release
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
#include <iomanip>
#include "NumberArray.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
// are utilized in this program

//*********************************************************
// Initializing Constructor                               *
// Allocates an array of the  given size and sets all its *
// entries to the given value.                             *
//*********************************************************
NumberArray::NumberArray(int size, double value)
{
  arraySize = size;
  arrayPntr = new double[arraySize];
  setValue(value);
}


//**********************************************************
// Copy Constructor                                        *
// Allocates an array of the same size as the array in the *
// "source" object, then does an element by element copy   *
// from the "source" array to "this" object's array.       *
//**********************************************************
NumberArray::NumberArray(const NumberArray& source)
{
	cout << "  Copy Constructor called" << endl;

	this->arraySize = source.arraySize;

	arrayPntr = new double[arraySize];

	for (int index = 0; index < arraySize; ++index)
		*(arrayPntr + index) = *(source.arrayPntr + index);
}


//**********************************************************
// Class Destructor                                        *
// Deallocates the memory dynamically allocated for "this" *
// object's array.                                         *
//**********************************************************
NumberArray::~NumberArray()
{
	cout << "  Class Destructor called" << endl;

	if (arrayPntr != NULL)
		delete[] arrayPntr;
}


//*******************************************************
// Method: setValue(double)                             *
// Sets all the entries of the array to the same value. *
//*******************************************************
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
}


//*************************************************************
// Operator: Assignment                                       *
// Assigns a copy of one Class object to another Class object *
//*************************************************************
NumberArray NumberArray::operator= (const NumberArray& rValue)
{
	cout << "  Assignment Operator invoked" << endl;
	if (this->arrayPntr == NULL)
	{
		cout << "    \"this\" is \"NULL\": Creating an object as a Copy" << endl;
		NumberArray temp(rValue.arraySize, rValue.arrayPntr[0]);
		return temp;
	}
	else if (this == &rValue)
		cout << "    Assigning an object to itself; nothing to do!" << endl;
	else
	{
		if (arraySize != rValue.arraySize)
		{
			cout << "    Size mismatch: Deleting old array" << endl;
			delete[] arrayPntr;

			arraySize = rValue.arraySize;
			arrayPntr = new double[arraySize];
		}
		else
			cout << "    Arrays in both objects the same size, \"reusue\" rValue array" << endl;

		for (int index = 0; index < arraySize; ++index)
			*(arrayPntr + index) = *(rValue.arrayPntr + index);
	}

	return *this;

}