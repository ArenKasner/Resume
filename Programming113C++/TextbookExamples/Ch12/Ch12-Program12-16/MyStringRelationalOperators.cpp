/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-16
*
* Solution/Project Name: Ch12-Program12-16
*             File Name: MyStringRelationalOperators.cpp
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
*   1.0     04/27/2015  Initial Release
*
*
* Program Inputs
* --------------
* None
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   1. Results of invoking class method "C_String" to receive an
*              object's underlying C-String to the caller's C_String array.
*           2. Examples showing results of the various overloaded "MyString"
*              relational Oerators.
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
#include <iostream>
#include "mystring.h" 

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the use of the overloaded, relational Operators
* for the class "MyString". In addition, a method has been added to class
* "MyString>, method "C_String", which copies the underlying C-String array
* from a class object to the caller's C-String array of "char"s.
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
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;     // Program execution status: No errors
	const int MAX_STRING = 256;  // Size of C-String array, minus "NULL" character

	// C-String array to receive "Mystring" object "string"s
	char cString[MAX_STRING + 1];

	// "MysString" objects
	MyString name1("Billy"), name2("Sue");
    MyString name3("Joe");
    MyString string1("ABC"), string2("DEF");

	// Uninitialized Variable Declaraytion
	bool allTransfered;


	cout << " Textbook Example Program 12-16:\n"
		<< "\"MyString\" Relational Operators" << endl << endl;

	// Example #1: Obtain "MyString" objects' into a C-String array
	cout << "Obtain \"MyString\" objects' into a C-String array" << endl;

	cout << "  Example 1A: Object \"name1\"" << endl;
	allTransfered = name1.C_String(cString, MAX_STRING);
	cout << "  name1: \"" << cString << '\"' << endl;
	if (allTransfered)
		cout << "  (All characters obtained)" << endl;
	else
		cout << "  (Only " << MAX_STRING << " obtained)" << endl;

	cout << "\n  Example 1B: Object \"name2\"" << endl;
	allTransfered = name2.C_String(cString, MAX_STRING);
	cout << "  name2: \"" << cString << '\"' << endl;
	if (allTransfered)
		cout << "  (All characters obtained)" << endl;
	else
		cout << "  (Only " << MAX_STRING << " obtained)" << endl;

	cout << "\n  Example 1C: Object \"name3\"" << endl;
	allTransfered = name3.C_String(cString, MAX_STRING);
	cout << "  name3: \"" << cString << '\"' << endl;
	if (allTransfered)
		cout << "  (All characters obtained)" << endl;
	else
		cout << "  (Only " << MAX_STRING << " obtained)" << endl;

	cout << "\n  Example 1D: Object \"string1\"" << endl;
	allTransfered = string1.C_String(cString, MAX_STRING);
	cout << "  string1: \"" << cString << '\"' << endl;
	if (allTransfered)
		cout << "  (All characters obtained)" << endl;
	else
		cout << "  (Only " << MAX_STRING << " obtained)" << endl;

	cout << "\n  Example 1E: Object \"string2\"" << endl;
	allTransfered = string2.C_String(cString, MAX_STRING);
	cout << "  string2: \"" << cString << '\"' << endl;
	if (allTransfered)
		cout << "  (All characters obtained)" << endl;
	else
		cout << "  (Only " << MAX_STRING << " obtained)" << endl;


	cout << "\nExample 2: Compare \"name1\" with \"name2\" for equality" << endl;
	if (name1 == name2)
        cout << "  name1 is equal to name2.\n";
    else
        cout << "  name1 is not equal to name2.\n";

	cout << "\nExample 3: Compare \"name3\" with literal \"Joe\" for equality" << endl;
	if (name3 == "Joe")
        cout << "  name3 is equal to Joe.\n";
    else
        cout << "  name3 is not equal to Joe.\n";


	cout << "\nExample #4: Comparisons of \"string1\" with \"string2\"" << endl;
	cout << "  4A: string1 > string2" << endl;
    if (string1 > string2)
        cout << "      \"string1\" IS greater than \"string2\".\n";
    else
        cout << "      \"string1\" is NOT greater than \"string2\".\n";

	cout << "  4B: string1 < string2" << endl;
    if (string1 < string2)
        cout << "      \"string1\" IS less than \"string2\".\n";
    else
        cout << "      \"string1\" is NOT less than \"string2\".\n";

	cout << "  4C: string1 >= string2" << endl;
	if (string1 >= string2)
        cout << "      \"string1\" IS greater than or equal to \"string2\".\n";
    else
        cout << "      \"string1\" is NOT greater than or equal to \"string2\".\n";

	cout << "  4D: string1 <= string2" << endl;
	if (string1 <= string2)
		cout << "      \"string1\" IS less than or equal to \"string2\".\n";
	else
		cout << "      \"string1 is NOT less than or equal to \"string2\".\n";


	cout << "\nExample #5: Comparisons of \"string1\" with literal strings" << endl;
	cout << "  5A: \"ABC\" >= string2" << endl;
	if (string1 >= "ABC")
        cout << "      \"string1\" IS greater than or equal to \"ABC\".\n";
    else
        cout << "      \"string1\" is NOT greater than or equal to \"ABC\".\n";

	cout << "  5B: \"string2\" <= \"string1\"" << endl;
	if (string2 <= "DEF")
        cout << "      \"string2\" IS less than or equal to \"DEF\".\n";
    else
        cout << "      \"string2\" is not less than or equal to \"DEF\".\n";


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()