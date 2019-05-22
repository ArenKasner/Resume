/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
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

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
* Pre-Conditions
* --------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/
//class Foo
//{
//private:
//	int value;
//public:
//	Foo(int val)
//	{
//		value = val;
//	}
//
//	int getValue()
//	{
//		return value;
//	}
//};

int foo(int);
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
//Foo obj;
//	cout << obj.getValue() << endl;
	 int myArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	 int* arrayPntr = myArray;
	 cout << arrayPntr;
	 int val1 = 7;
	 int val2 = 7;
	 int* pntr1 = &val1;
	 int* pntr2 = &val2;

	//What is displayed when the following C++ statement is executed ?

		 if (pntr1 == pntr2)
			 cout << "val1 equals val2" << endl;
		 else
			 cout << "val1 does NOT equal val2" << endl;
	// !! Insert your code here (remove this comment line) !!
		 for (int i = 2; i < 23000; ++i)
		 {
			 int sum = foo(i);
			 cout << "sum = " << sum << endl;
		 }

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}
 int foo(int max)
 {
	 int* array = new int[max];
	 int sum;

	 for (int i = 0; i < max; ++i)
		 array[i] = i + 1;

	 sum = 0;
	 for (int i = 0; i < max; ++i)
		 sum += array[i];

	 return sum;
 }
