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
* setValue         Sets all array elements to specified value
* print            Displays all array element values
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
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
#include <iomanip>
#include "NumberArray.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
// are utilized in this program


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

//********************************************************
// Method: setValue(double)                              *
// Sets all the elements of the array to the same value. *
//********************************************************
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
