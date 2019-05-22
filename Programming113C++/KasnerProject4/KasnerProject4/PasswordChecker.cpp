/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: Project4  (Ex: Project1)
 *             File Name: PasswordChecker.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Aren Kasner
 *
 * Assigned Project Number: P4
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     04/30/2015   Initial Release
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
 * passWordWork  the method that checks the password
 * **** Add name and description of any other methods defined in this file ****
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>
// Namespaces utilized in this program

using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program
//prototype
bool passWordWork(string);
/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* The Program asks the user for a password to check and then shows them if it was
* good or not and displays all problems if it is bad.
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
*passWordWork()  Checks the password
*******************************************************************************
/******************************************************************************
* Method: passWordWork()
*
* Method Description
* ------------------
* The passWordWork method takes in a string and then finds the lenght 
* then the method checks each value for password criteria one passes then you
* set that flag to true if all pass break loop when finished with loop display
* all unhit critera and delare if good data or not.
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
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 
	 string passwordString;
	 bool goodpassword = false;
	 cout << "This is the Password Checker" << endl;
	 do
	 {
		 cout << "Please Enter your password" << endl;
		 getline(cin, passwordString);
		 goodpassword = passWordWork(passwordString);
	 } while (goodpassword != true);


	// !! Insert your code here (remove this comment line) !!


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}
 bool passWordWork(string passWord)
 {
	
	 bool goodData = false;
	 bool containLower = false,containUpper = false,containNum = false,lenghtCheck = false;
	 int length = passWord.size();
	 char charCheck;
	 int const upperMin = 64, upperMax = 90, lowerMin = 97, lowerMax = 122,numMin = 48,numMax = 57;
	 if (length>=6)
	 {
		 lenghtCheck = true;
	 }
	 for (int i = 0; i < length; i++)
	 {
		 
		 
		 if (containNum==false||containUpper==false||containLower==false)
		 {
			 if (lenghtCheck == true && containNum == true && containLower == true && containUpper == true)
			 {
				 return true;
			 }
			 if (isupper(passWord[i]))
			 {
				 containUpper = true;
			 }
			 if (islower(passWord[i]))
			 {
				 containLower = true;
			 }
			 if (isdigit(passWord[i]))
			 {
				 containNum = true;
			 }
		 }
		 break;
	 }
	 if (containLower == false)
	 {
		 cout << "Password does not contain a lowercase letter." << endl;
	 }
	 if (containUpper == false)
	 {
		 cout << "Password does not contain a Uppercase letter." << endl;
	 }
	 if (containNum == false)
	 {
		 cout << "Password does not contain a number." << endl;
	 }
	 if (lenghtCheck == false)
	 {
		 cout << "Password is too short." << endl;
	 }
	 if (lenghtCheck==true&&containNum==true&&containLower==true&&containUpper==true)
	 {
		 goodData = true;
		 cout <<"Good password" << endl;
	 }
	 return goodData;
 }
