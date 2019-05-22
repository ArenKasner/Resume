/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Spring 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: **Solution/Project Name**  (Ex: Project1)
 *             File Name: **ThisFileName**.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: **Your Name**
 *
 * Assigned Project Number: **See Syllabus, for example: 2A**
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     MM/DD/YYYY  Initial Release
 *   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
 *
 *
 * UDTs (Classes) Used
 *       Name                          Description
 * ----------------  ----------------------------------------------------------
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  ** Describe any inputs from the User; otherwise, None **
 *
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   ** Describe any Console display; otherwise, None **
 *
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
 * **** Add name and description of any other methods defined in this file ****
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <cstdlib>
#include <algorithm>
// Class Definition header file(s)
#include "AbstractSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

void print(int* array, const int size);

void randCreate(int* array, const int size);

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program creates two arrays and then 
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other Class methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
*
* Pre-Conditions
* --------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ------------------------------------------------
* 
* void		print			Prints the array
* void		randCreate		creates the random number and fills the array.
*
*
* Return Value
* ------------
*   Type                              Description
* --------  ---------------------------------------------------------------
* int       Program Execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Value Declarations
	AbstractSort *Sort[] = { new QuickSort, new SelectionSort };
	const int NO_ERRORS = 0,SIZE = 20,MAx = 100;
	int* randQuick = new int[SIZE];
	int* randSelect = new int[SIZE];
	randCreate(randSelect, SIZE);
	randCreate(randQuick, SIZE);
	cout << "Welcome to the sort function creator" << endl<<endl;
	cout << "Array before work done." << endl;
	cout << "Selection sort presort" << endl;
	print(randSelect,SIZE);
	Sort[1]->sort(randSelect, SIZE);
	cout << "Quick sort presort" << endl;
	print(randQuick, SIZE);
	Sort[0]->sort(randQuick,SIZE);
	cout << "this is the sorted Selection sort array with " << Sort[1]->count << " swaps" << endl;
	print(randSelect, SIZE);
	cout << "this is the sorted Quick sort array with " << Sort[0]->count << " swaps"<<endl;
	print(randQuick, SIZE);
	
	
	
	
// Examples of declaring class objects (remove these five lines)
//	Class* object1 = new Class();  // Object created in the Heap Memory
//	Class object2 = Class();       // Object created in Stack Memory
//
//	delete object1;  // Releases object/array memory allocated in Heap Memory!!


	// This prevents the Visual Studio Console Window from closing during
	// debug mode and allows you to select and copy the results displayed in
	// the Console window.
	cout << endl;  // Inserts a blank line before the prompt occurs
	system("pause");

	return NO_ERRORS;
}

void print(int* array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i<19)
		{
			cout << array[i] << ", ";
		}
		else
		{
			cout << array[i] << endl;
		}
	}
}

void randCreate(int* array, const int size)
{
	for (int i = 0; i < 20; i++)
	{
		array[i] = rand() % 100 + 1;
	}
}