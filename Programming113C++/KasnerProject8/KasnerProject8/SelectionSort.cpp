#include "stdafx.h"
#include "SelectionSort.h"

/******************************************************************************
*       Class: **Class Name**       (Ex: Car)
*  Base Class: ** None **  Supply Base Class name if inheritance applies
*
*
* This file defines the static, const data members, if any, and the class
* methods not defined in the class definition file, ***ClassName***.h
*
* Programmer: **Your Name**
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     MM/DD/YYYY  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* ----------------------------- Public Interface -----------------------------
*      Method                               Description
* ----------------  ----------------------------------------------------------
* Class()           Default Constructor
* ~Class()          Class Destructor
*  ***Enter the remaining Class methods here***
*
*
* ------------------------------ Private Methods -----------------------------
*       Name                               Description
* ----------------  ----------------------------------------------------------
*                           *** No private methods ***
*
*
*
* ------------------------- Data Member Initializations ----------------------
*               Data
*    Type       Type         Name                   Description
* ----------  --------  --------------  --------------------------------------
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list

SelectionSort::SelectionSort():AbstractSort()
{
	count = 0;
}


SelectionSort::~SelectionSort()
{
}

void SelectionSort::sort(int* rand_array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		bool switched = false;

		for (int j = 0; j < size - 1; j++)
		{
			if (rand_array[j + 1] < rand_array[j])
			{
				int temp;

				temp = rand_array[j];
				rand_array[j] = rand_array[j + 1];
				rand_array[j + 1] = temp;
				switched = true;
				counter();
			}

		}
		if (switched == false)
		{
			break;
		}
	}
}