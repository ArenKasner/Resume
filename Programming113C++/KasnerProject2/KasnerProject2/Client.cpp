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
 * Assigned Project Number: Project2 **See Syllabus, for example: 2A**
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
// Class Definition header file(s)
#include "Class.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program
//prototypes
string isPalindrome(int*,int);
/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
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
*                        *** No Arguments supplied ***
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
	const int NO_ERRORS = 0;
	string possiblePalindrome = "";
	int Length;
	cout << "welcome to the palindrome tester." << endl;
	cout << "Please enter a palindrome" << endl;
	getline(cin,possiblePalindrome);
	cout << "\n\n" << possiblePalindrome << endl;

	// !! Insert your code here (remove this comment line) !!

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
string isPalindrome(int*,int size)
{
	int index;
//	char character = (*this)[index];

}