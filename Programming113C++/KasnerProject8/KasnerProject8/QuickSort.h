#pragma once
/******************************************************************************
*       Class: **QuickSort**       (Ex: Car)
*  Base Class: ** AbstractSort **  Supply Base Class name if inheritance applies
*
* This file defines the members of the class: ***QuickSort***
* These members include class variable data members, class constant, static
* data members, and class method declarations only and/or class method
* declarations and definitions.
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     05/30/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
* Class Description
* -----------------
* This is the QuickSort Class that partions the array in to smaller peices 
* to speed up the sorting of the array so that there are less total swaps needed.
* it breaks by 
* ** Describe the class defined here, including it's purpose  **
* ** This may take several lines to describe                  **
*
*
* ----------------------------- Public Interface ------------------------------
*      Method                               Description
* ----------------  -----------------------------------------------------------
*   QuickSort();	constructor
*	~QuickSort();	default destructor
* sort(int* rand_array, int start); calls the underlying sort array
*
*
* ------------------------------ Private Methods ------------------------------
*       Name                               Description
* ----------------  -----------------------------------------------------------
*	void swap(int&a,int&b); swaps the values in the array
*	void quickSort(int* arr, int start, int end); 
*	int partition(int* arr, int start, int end);  splits the array and calls the 
*					swap function
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
* 
*
*******************************************************************************
*/
// External Definition Files

#include "AbstractSort.h"

class QuickSort : public AbstractSort
{
private:
void swap(int&a,int&b);
	void quickSort(int* arr, int start, int end);
	int partition(int* arr, int start, int end);
public:
	QuickSort();
	~QuickSort();
	virtual void sort(int* rand_array, int start);
	
};

