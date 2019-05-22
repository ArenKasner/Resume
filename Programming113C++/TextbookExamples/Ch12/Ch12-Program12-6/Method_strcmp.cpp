/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-6
*
*
* Solution/Project Name: Ch12-Program12-6
*             File Name: Method_strcmp
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
* Keyboard  User's selection for an item part number
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor   The price of the User's selected item or error message if User's
*           part number is invalid.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* main          Program entry point method
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines I/O Manipulators
#include <string>    // Defines Class: string

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program demonstrates the use of the C-String method "strcmp".
* This example displays a list of inventoried item part numbers from the User,
* then requests the User to enter a part number selection, as a string of
* "char"s, which are stored in a C-Style "char" array. The User's entry is then
* checked to see if it is in the inventory of items, and if so the price of the
* item is then displayed to the USer. If the item is NOT in the inventory, an
* error message is issued.
*
* This example utilizes parallel arrays for the item part numbers, item
* descriptins, and item prices.
*
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
* None
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	// 1. Miscellaneous values
	const int NO_ERRORS = 0;       // Program Status: No errors 
	const int PART_LENGTH = 8;     // Size of "char" array, minus the "NULL"
	const double NO_PRICE = -1.0;  // Signifies no item number match found

	// 2. Item Parallel Arrays
	const double PRICES[] =       { 49.0,                 69.95 };
	const string DESCRIPTIONS[] = { "Blu-ray Disk Drive", "Wireless Router" };
	const string PART_NUMBERS[] = { "S147-29A",           "S147-29B" };
	const int NMBR_ITEMS = sizeof(PRICES) / sizeof(PRICES[0]);

	// Uninitialized Variable Declarations
	// 1. Character array for part number from the User
	//    Include room for the required, terminating "NULL" character
	char partNum[PART_LENGTH + 1];
	// 2. The price of the User's selected item
	double price;
	// 3. Pointer to C-String array obtained from "string" method "c_str()"
	const char* selection;


	cout << "Textbook Example Program 12-6:\n"
		<< "   Method \"strcmp\" Example" << endl << endl;


	// Instruct the User to enter a part number
	cout << "The computer part numbers are:" << endl;
	cout << "Part Number      Description" << endl;
	cout << "-----------  -------------------" << endl;
	for (int index = 0; index < NMBR_ITEMS; ++index)
	{
		cout << setw(13) << left << PART_NUMBERS[index] << setw(19) << left
			 << DESCRIPTIONS[index] << endl;
	}
	cout << "\nEnter an item part number: ";

	cout << showpoint << fixed << setprecision(2);

	// Read a part number of at most 8 characters
	cin >> setw(9);  // Allows for the terminating "NULL" character
	cin >> partNum;  // Now get the User's input, stored in the "char" array

	// Determine if the User entered a valid part number, and if so,
	// determine its price from the parallel array of "PRICES".
	price = NO_PRICE;  // Assume the User's part number is invalid
	for (int index = 0; index < NMBR_ITEMS; ++index)
	{
		// Need to obtain a pointer to "char" from the "string"
		// element in the "PART_NUMBERS" array by invoking the
		// "string" method, "c_str" on the selected element object.
		selection = PART_NUMBERS[index].c_str();
		if (strcmp(partNum, selection) == 0)
		{	// Found an EXACT match...
			price = PRICES[index];  // Set the price from the parallel array
			index = NMBR_ITEMS;     // This will terminate the loop
		}
	}
	// See if a match was found
	if (price != NO_PRICE)
		cout << "The price is $" << price << endl;
	else
		cout << partNum << " is not a valid part number.\n";


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}
