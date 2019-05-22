/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-11
*
*
* Solution/Project Name: Ch12-Program12-11
*             File Name: C_StringCopyExample
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/18/2015  Initial Release
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  User will enter a string of characters, no longer than specified
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  --------------------------------------------------------------------
* Monitor   1. Source and destination arrays with initialized "char" elements
*           2. Source and destination arrays after source set to User's entry
(           3. Source and destination arrays after copy of source to destination
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* stringCopy    Same as C-String method, "strcpy"
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
void stringCopy(char[], const char[]);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
This program demonstrates the code required to implment the functionality of
* the C-String method "strcpy".
*
* Pre-Conditions
* --------------
* User will enter a string no longer that that specified in the prompt
*
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
* ------------  ---------------------------------------------------------------
* stringCopy    Same as C-String method, "strcpy"
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	 const int S_LENGTH = 30;

	 // Define two arrays of char
	 char source[S_LENGTH + 1];
	 char destination[S_LENGTH + 1];


	 cout << "Textbook Example Program 12-11:\n"
		 << "  C-String Copy Method Example" << endl << endl;

	 int index;
	 for (index = 0; index < S_LENGTH; ++index)
	 {
		 source[index] = 'A';
		 destination[index] = 'B';
	 }
	 source[index] = '\0';
	 destination[index] = '\0';

	 cout << "C-String arrays before data entry to \"source\":" << endl;
	 cout << "       source: \"" << source << "\"" << endl;
	 cout << "  destination: \"" << destination << "\"" << endl;


	 // Read a string into a source array
	 cout << "\nEnter a string with no more than " << S_LENGTH << " characters: ";
	 cin.getline(source, S_LENGTH);

	 cout << "\nC-String arrays before copy:" << endl;
	 cout << "       source: \"" << source << "\"" << endl;
	 cout << "  destination: \"" << destination << "\"" << endl;

	 //	Copy it into a destination array and print
	 stringCopy(destination, source);

	 cout << "\nC-String arrays after copy:" << endl;
	 cout << "       source: \"" << source << "\"" << endl;
	 cout << "  destination: \"" << destination << "\"" << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


 /*****************************************************************************
* Method: stringCopy(char[],char[])
*
* Method Description
* ------------------
* This method simulates the C-String method "strcpy" copy of one C-String,
* "NULL" terminated array contents to another C-String array.
*
* Pre-Conditions
* --------------
* 1. Both array pointers are not "NULL" pointers
* 2. The destination array size is at least as big as the source array size
*
*
* Method Arguments
* ----------------
*  Type       Name                        Description
* ------  ------------  -------------------------------------------------------
* char[]  source        Source C-String array for the copy ("NULL" terminated)
* char[]  destination   Destination C-String array for the copy
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* void      Method RETurns no value
*
*
* Invoked Methods
* ---------------
* None
*
*******************************************************************************
*/
 void stringCopy(char destStr[], const char sourceStr[])
 {
	 int index = 0;

	 // Copy one character at a time till the "NULL" character is found in the
	 // source C-String array
	 while (sourceStr[index] != '\0')
	 {
		 destStr[index] = sourceStr[index];
		 index++;
	 }
	 // Then add a "NULL" character to the end of the destination C-String array
	 destStr[index] = '\0';

 }	// End Method: stringCopy(char[],char[])