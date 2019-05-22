/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-8
*
*
* Solution/Project Name: Ch12-Program12-8
*             File Name: C_String_Search.cpp
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
* --------  ----------  ------------------------------------------------------
*   1.0     04/17/2015  Initial Release
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  ------------------------------------------------------------------
* Keyboard  User entry of a product name into a C-Style "char" array, which
*           will be use to search for a match in an array of C-Style, "char"
*           arrays.
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor   Result of the search, full product name or name not found 
*
*
* File Methods
* ------------
*      Name                             Description
* --------------  ------------------------------------------------------------
* main            Program entry point method
* C_StringSearch  Performs search for match of C-String in array of C-Strings
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

// Global, const" Value Declarations
const int N_ITEMS = 5;     // Maximum number of items
const int S_LENGTH = 31;   // maximum length of description

// Method Prototypes
int C_StringSearch(const char[][S_LENGTH], int, const char*);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates the use of the C-String method, "strstr", which
* searches a C-String array of "char"s for a match with a supplied, C-String
* array of "char"s. The method will RETurn a pointer to the character in the
* array being searched corresponding to the first character in the supplied
* array of "char"s for which to search. The C-String to search for can be a
* partial string in the searched array, thus allowing for a partial string
* match.
*
* The program will store in an array of C-String arrays, i.e. a 2-dimensional
* array of item numbers along with the item's description for each item in
* each of the C-String arrays. The User will then be asked to enter some
* partial or full string for the item number and the program will then search
* the entire array looking for a partial match. In this scheme, the User can
* also enter a partial item description string for the search.
*
* Pre-Conditions
* --------------
* None
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
*      Name                                Description
* --------------  -------------------------------------------------------------
* C_StringSearch  Performs the search for a partial/full match
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Value Declarations
	 const int NO_ERRORS = 0;   // Program Execution Status: No errors

	 // Array of product descriptions
	 const char prods[N_ITEMS][S_LENGTH] = { "TV327  31 inch Television",
		 "CD257  CD Player",
		 "TA677  Answering Machine",
		 "CS109  Car Stereo",
		 "PC955  Personal Computer" };

	 char lookUp[S_LENGTH];  // For user input
	 int index;


	 cout << "Textbook Example Program 12-8:\n"
		 << "   C-String Method \"strstr\"" << endl << endl;


	 // Get user input
	 cout << "        Product Database\n\n";
	 cout << "Enter a product number for the search: ";
	 cin.getline(lookUp, S_LENGTH);

	 // Search for the string
	 index = C_StringSearch(prods, N_ITEMS, lookUp);

	 // Output the result of the search
	 if (index < 0)
		 cout << "No matching product was found.\n";
	 else
		 cout << prods[index] << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()


 /******************************************************************************
 * Method: C_StringSearch(const char[][S_LENGTH],int,const char*)
 *
 * Method Description
 * ------------------
 * This method performs the search for a partial/full match of the supplied
 * search, C-String array in one of the C-String, "char" arrays in the supplied
 * 2-dimensional array of C-Strings.
 *
 * If a match is found, the index in the 2-dimensional array of the matched
 * C-String array of "char"s is RETurned. If no match occurs, "NULL" is
 * RETurned.
 *
 * Pre-Conditions
 * --------------
 * 1. A valid, 2-dimensional array is passed to the method
 * 2. The search C-String pointer argument is not "NULL"
 *
 *
 * Method Arguments
 * ----------------
 *   Type      Name                        Description
 * --------  --------  --------------------------------------------------------
 * char[][]  array     2-dim array of C-String, "char" arrays to search
 * int       size      Number of C-String, "char" arrays in the search array
 * char*     item      C-String, "char" array for the search
 *
 * Return Value
 * ------------
 * Type                               Description
 * ----  ----------------------------------------------------------------------
 * int   Array index of the full C-String description, or "NULL": Not found
 *
 *
 * Invoked Methods
 * ---------------
 * None
 *
 *******************************************************************************
 */
 int C_StringSearch(const char array[][S_LENGTH], int size, const char* item)
 {
	 int returnIndex = -1;
	 const char* strPntr;

	 int index = 0;
	 while (index < size)
	 {
		 strPntr = strstr(array[index], item);
		 if (strPntr != NULL)
		 {
			 returnIndex = index;
			 index = size;
		 }
		 else
			index++;
	 }

	 return returnIndex;

 }	// End Method: C_StringSearch(const char[][S_LENGTH],int,const char*)
