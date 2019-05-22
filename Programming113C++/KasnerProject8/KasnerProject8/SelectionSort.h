#pragma once
#include "AbstractSort.h"
/******************************************************************************
*       Class: SelectionSort       (Ex: Car)
*  Base Class: AbstractSort  Supply Base Class name if inheritance applies
*
* This file defines the members of the class SelectionSort
* These members include class variable data members, class constant, static
* data members, and class method declarations only and/or class method
* declarations and definitions.
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     05/31/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
* Class Description
* -----------------
* This is the Selection Sort Class that uses the bubble sort method
* to sort the function and counts the number of swaps used to run it.
* ** Describe the class defined here, including it's purpose  **
* ** This may take several lines to describe                  **
*
*
* ----------------------------- Public Interface ------------------------------
*      Method                               Description
* ----------------  -----------------------------------------------------------
*   SelectionSort(); constructor
*	~SelectionSort(); destructor
* Sort();			uses the swap function
*
* ------------------------------ Private Methods ------------------------------
*       Name                               Description
* ----------------  -----------------------------------------------------------
*                           *** No private methods ***
*
*
* --------------------------- Private Data Members ----------------------------
*               Data
*    Type       Type       Name                    Description
* ---------- --------- ------------ -------------------------------------------
* ***Type: static, non-static***
*
*
* ------------------  Public "static const" Data Members ----------------------
*   Data
*   Type         Name                         Description
* --------  --------------  ---------------------------------------------------
*  int        count			counts the number of swaps.
*
*******************************************************************************
*/
// External Definition Files

class SelectionSort :public AbstractSort
{
public:
	SelectionSort();
	~SelectionSort();
	virtual void sort(int* rand_array, const int size) override;
};

