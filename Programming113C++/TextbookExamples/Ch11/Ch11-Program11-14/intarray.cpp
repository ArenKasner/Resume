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
* IntArray         Constructor: Size provided, dynamically allocate array
* IntArray         Copy Constructor
* ~IntArray        Class Destructor
* operator[]       Overloaded [] Operator, implemented to index array elements
* operator=        Overloaded Assignment Operator
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
* subError  Tests for subscript error; exits program if out of range
*
*
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
*                         *** No Initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include "intarray.h" 

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


//****************************************************
// Constructor for IntArray class. Sets the size of  *
// the array and allocates memory for it.            *
//****************************************************
IntArray::IntArray(int size) : arrayPntr(NULL), arraySize(0)
{
	if (size > 0)
	{
		arraySize = size;
		arrayPntr = new int[arraySize];

		for (int count = 0; count < arraySize; count++)
			*(arrayPntr + count) = 0;
	}
}

//****************************************************
// Copy constructor for IntArray class.              *
//****************************************************
IntArray::IntArray(const IntArray& obj) : arrayPntr(NULL), arraySize(0)
{
	if (obj.arraySize > 0)
	{
		arraySize = obj.arraySize;

		arrayPntr = new int[arraySize];

		for (int count = 0; count < arraySize; count++)
		*(arrayPntr + count) = *(obj.arrayPntr + count);
	}
}

//****************************************************
// Destructor for IntArray class.                    *
//****************************************************
IntArray::~IntArray()
{
	if (arrayPntr != NULL)
	   delete[] arrayPntr;
}

//*****************************************************
// subError method. Displays an error message and   *
// exits the program when a subscript is out of range.*
//*****************************************************
void IntArray::subError(int subsript) const
{
	if (subsript < 0 || subsript >= arraySize)
	{
		cout << "ERROR: Subscript out of range.\n";

		// This prevents the Console Window from closing during debug mode
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\nPress only the 'Enter' key to exit program: ";
		cin.get();
		exit(0);
	}
}

//******************************************************
// Overloaded [] operator. The argument is a subscript *
// This function returns a reference to the element    *
// in the array indexed by the subscript.              *
//******************************************************
int& IntArray::operator[](int subscript) const
{
	// First, test for subscript out-of-range
	subError(subscript);

	return arrayPntr[subscript];
}


//***************************************************
// Operator: Assignment                             *
//***************************************************
IntArray IntArray::operator=(const IntArray& rValue)
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
			arrayPntr = new int[rValue.arraySize];
		}

		// Update the 
		arraySize = rValue.arraySize;

		for (int index = 0; index < arraySize; index++)
			arrayPntr[index] = rValue.arrayPntr[index];

	}	// End if: Not assigning a Class object to itself

	return *this;

}	// End Operator: Assignement
