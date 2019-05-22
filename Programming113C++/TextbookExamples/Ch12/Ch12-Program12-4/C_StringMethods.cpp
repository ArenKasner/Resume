/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
*  Chapter: 12
* Programs: 12-4 and 12-5
*
* Solution/Project Name: Ch12-Program12-4
*             File Name: C_StringMethods.cpp
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
*   1.0     04/17/2015  Initial Release
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  Two "words", the second word to be concatenated to the first word
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   1. Several examples of the C-Style "strcmp" method
*           2. Result of the C-Style "strcat" method
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
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

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates two of the C-Style methods, "strcmp" and "strcat".
* In addition, the improper use of the equality Operator, ==, when comparing
* two C-Style strings, pointers to a "char" array, is demonstrated for two
* separate strings that are identical, and as such should indicate they are
* equal to each other.
*
* Pre-Conditions
* --------------
* None
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
* None
*
*******************************************************************************
*/
int main()
{
	// Constant "const" Vlaue Declarations
	const int NO_ERRORS = 0;
	const int LENGTH = 40;

	char firstWord[2 * LENGTH];
	char secondWord[LENGTH];
	char concatenatedWords[2 * LENGTH];

	char string1[] = "Hello";
	char string2[] = "Hello";
	char string3[] = "hello";
	char string4[] = "Bello";

	int comparison;


	cout << "Textbook Example Program 12-4 and 12-5:\n"
		<< "         C-String Methods" << endl << endl;


	cout << "Fixed, literal C-String arrays:" << endl;
	cout << "  \"string1\": " << string1 << endl;
	cout << "  \"string2\": " << string2 << endl;
	cout << "  \"string3\": " << string3 << endl;
	cout << "  \"string4\": " << string4 << endl;

	cout << "\nExample 1A: Compare \"string1\" to \"string2\" using the equality (==) Operator:"
		 << endl;
	if (string1 == string2)
		cout << "  \"string1\" IS equal to \"string2\"" << endl;
	else
		cout << "  \"string1\" is NOT equal to \"string2\"" << endl;
	cout << "Example 1B: Compare \"string1\" to \"string2\", using \"strcmp\":"
		 << endl;
	if (strcmp(string1, string2) == 0)
		cout << "  \"string1\" IS equal to \"string2\"" << endl;
	else
		cout << "  \"string1\" is NOT equal to \"string2\"" << endl;


	cout << "\nExample #2: Compare \"string1\" with \"string3\", using \"strcmp\":"
		 << endl;
	comparison = strcmp(string1, string3);
	cout << "  Comparison value: " << comparison << endl;
	if (comparison == 0)
		cout << "  \"string1\" IS equal to \"string3\"" << endl;
	else if (comparison < 0)
		cout << "  \"string1\" is LESS THAN \"string3\"" << endl;
	else
		cout << "  \"string1\" is GREATER THAN \"string3\"" << endl;


	cout << "\nExample #3: Compare \"string1\" with \"string4\", using \"strcmp\":"
		 << endl;
	comparison = strcmp(string1, string4);
	cout << "  Comparison value: " << comparison << endl;
	if (comparison == 0)
		cout << "  \"string1\" IS equal to \"string4\"" << endl;
	else if (comparison < 0)
		cout << "  \"string1\" is LESS THAN \"string4\"" << endl;
	else
		cout << "  \"string1\" is GREATER THAN \"string4\"" << endl;


	cout << "\nExample #4: C-String method \"strcat\":" << endl;
	cout << "  Enter the first word: ";
	cin.getline(firstWord, LENGTH);
	cout << "  Enter the second word: ";
	cin.getline(secondWord, LENGTH);
	cout << "   \"firstWord\": " << firstWord << endl;
	cout << "  \"secondWord\": " << secondWord << endl;
	cout << "  Copy \"firstWord\" to \"concatenatedWords\", using \"strcpy_s\":"
		 << endl;
	strcpy_s(concatenatedWords, firstWord);
	cout << "    \"concatenatedWords\": " << concatenatedWords << endl;
	cout << "  Concatenating \"secondWord\" to \"concatenatedWords\", using \"strcat_s\":"
		 << endl;
	strcat_s(concatenatedWords, secondWord);
	cout << "    \"concatenatedWords\": " << concatenatedWords << endl;
	cout << "  Verify \"firstWord\" and \"secondWord\" are unchanged:" << endl;
	cout << "     \"firstWord\": " << firstWord << endl;
	cout << "    \"secondWord\": " << secondWord << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

