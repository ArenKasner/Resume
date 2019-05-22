
/******************************************************************************
*       Class: QuickSort      (Ex: Car)
*  Base Class: AbstractSort  Supply Base Class name if inheritance applies
*
*
* This file defines the static, const data members, if any, and the class
* methods not defined in the class definition file, QuickSort.h
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     05/30/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* ----------------------------- Public Interface -----------------------------
*      Method                               Description
* ----------------  ----------------------------------------------------------
* QuickSort()           Default Constructor
* ~QuickSort()			Class Destructor
* Sort();				calls the recursive function
*  ***Enter the remaining Class methods here***
*
*
* ------------------------------ Private Methods -----------------------------
*       Name                               Description
* ----------------  ----------------------------------------------------------
* swap();			swaps the values inputed in to the function
* quickSort();		recusive quicksort function that calls it self 
* partition();      partions the function and swaps the values of 
*
*
* ------------------------- Data Member Initializations ----------------------
*               Data
*    Type       Type         Name                   Description
* ----------  --------  --------------  --------------------------------------
*	counter		int		count			counts number of swaps
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "QuickSort.h"
QuickSort::QuickSort() :AbstractSort()
{
		count = 0;
}


void QuickSort::sort(int* rand_array, const int size)
{

	quickSort(rand_array,0,size-1);
}

void QuickSort::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	counter();
}

void QuickSort::quickSort(int* arr, int start, int end)
{	
	int p;
	if (start < end)
	{
		//Partition the array and get the pivot point
		p = partition(arr, start, end);
		// Sort the portion before the pivot point
		quickSort(arr,start,p-1);
		//Sort the portion after the pivot point
		quickSort(arr, p + 1, end);
	}
}

int QuickSort::partition(int a[], int first, int last)
{
	int  p = first;
	int pivotElement = a[first];

	for (int i = first + 1; i <= last; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
			
		}
	}

	swap(a[p], a[first]);

	return p;
}

QuickSort::~QuickSort()
{
}
