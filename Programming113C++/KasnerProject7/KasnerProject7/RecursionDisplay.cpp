/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: KasnerProject7  (Ex: Project1)
 *             File Name: RecursionDisplay.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Aren Kasner
 *
 * Assigned Project Number: 7
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     5/24/2015  Initial Release
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
 * squaredValue  Recursive display method

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
void squaredValue(int value,bool forward,int endPoint);

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* this method recursively displays the squared list odd and even values of the
* entered value in order seperating even and odd values on either side.
* the main function changes the starting number such that the entering
* number is odd and dlisplays properly.
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
* Pre-Conditions
* --------------
*  the program expects perfect entry information an number 
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
* squaredValue	recursive display method
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 bool forward;
	 
	 int enteredValue,endPoint;
	 cout << "Please enter a value to display:  ";
	 cin >> enteredValue;
	 endPoint = enteredValue;
	 cout <<endl;
	 if (enteredValue%2==0)
	 {
		 forward = false;
		 enteredValue = enteredValue-1;
	 }
	 else
	 {
		 forward = false;
	 }
	 
	 squaredValue(enteredValue,forward,endPoint);
	 // This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

 /******************************************************************************
 * Method: void squaredValue(int value,bool forward,int endPoint);

 *
 * Method Description
 * ------------------
 * the squaredValue method uses if function to check for
 * each value then prints the correct value in order then
 * called subtracted 2 and repeats until the point that the
 * value is equal to or less than 0 then flips the forward
 * bit and then call and prints recursively forward until it
 * reaches the endValue
 *
 *
 * Method Arguments
 * ----------------
 *   Type        Name                        Description
 * --------  -------------  ---------------------------------------------------
 * int		 value		starting pointer
 * bool		 forward    the derection of the function
 * int		 endPoint	the endPoint of the function
 *
 * Return Value
 * ------------
 *   Type                              Description
 * --------  ------------------------------------------------------------------
 * void
 *
 * Invoked Methods
 * ---------------
 *      Name                            Description
 * --------------  ------------------------------------------------------------
 *	squaredValue			the recusive function call
 ******************************************************************************
 */
 void squaredValue(int value,bool forward,int point)
 {
	 if (value<=0)
	 {
		 forward = true;
		 value = 0;
	 }
	 if (forward == false&&value>0)
	 {
		 if (value==1)
		 {
			 
		 }
		 else
		 {
			 cout << value*value << ", ";
		 }
		 squaredValue(value - 2,forward,point);
	 }
	 if (forward == true&& value<=point)
	 {
		 if (value ==0)
		 {
			 cout << 1;
		 }
		 else
		 {
			 cout << ", " << value*value;
		 }
		 squaredValue(value + 2, forward,point);
	 }
 }