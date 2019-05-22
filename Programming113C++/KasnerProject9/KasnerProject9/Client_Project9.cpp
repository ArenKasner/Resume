/******************************************************************************
* Bellevue Class: PROG 113
*           Term: Spring 2015
*     Instructor: Robert Main
*
*   Assigned Project: 9
*            Chapter: 16
* Challenge Programs: 4, 5, and 6
*
*
* Solution/Project Name: Solution-Project9
*             File Name: Client_Project9.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
*
* Programmer: Aren Kasner
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     05/xx/2015  Initial Release
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
* Monitor   1. Results of filling various "vector" objects, of different types
*           2. Results of shifting "vector" objects one element to the Left
*           3. Results of shifting "vector" objects one element to the Right
*           4. Results of reversing the elements in "vector" objects
*           5. Reslults of "Accumulating", "vector" objects
*           6. Result of shifting, reversing, and accumulating an "empty",
*              "vector" object
*
*
* UDTs (User Defined Types) Utilized
* ----------------------------------
*   Name                               Description
* --------  -------------------------------------------------------------------
* vector    C++ Template Class: Enhances basic features of an array of objects
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
#include "VectorTemplateMethods.h"

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Templates
template <class T>
void fillVector(vector<T>& vect, const T array[], int size)
{
	for (int index = 0; index < size; ++index)
		vect.push_back(array[index]);
}



/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program tests the required template methods specified in the Project #9,
* Project Description document, namely the methods:
*   1. output(const vector<>&)
*   2. shiftLeft(vector<>&)
*   3. shiftRight(vector<>&)
*   4. reverse(vector<>&)
*   5. accumulate(const vector&)
* In addition, tests of the shift/reverse/accumulate methods are performed when
* passing an "empty", "vector" object to those methods to ensure they throw
* the required "EmptyVectorException" exception.
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
*    Name                             Description
* ----------  -----------------------------------------------------------------
* fillVector  Template Method: Fills a "vector" object from an array
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;

	const string  strings[] = { "How ", "Now ", "Brown ", "Cow" };
	const char chars[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	const int intNmbrs[] = { 1, 3, 5, 7, 9, 11, 13 };
	const double dblNmbrs[] = { 11.1, 22.2, 33.3, 44.4, 55.5, 66.6 };

	const int STRINGS_SIZE = sizeof(strings) / sizeof(strings[0]);
	const int CHARS_SIZE = sizeof(chars) / sizeof(chars[0]);
	const int INTS_SIZE = sizeof(intNmbrs) / sizeof(intNmbrs[0]);
	const int DOUBLES_SIZE = sizeof(dblNmbrs) / sizeof(dblNmbrs[0]);

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program errors will occur

	// Initialized UDT Objects
	vector<int> intVector;
	vector<double> doubleVector;
	vector<string> stringVector;
	vector<char> charVector;

	vector<int> emptyVector;


	cout << "          Project #9 Solution: Client Program\n" << endl;


	// Fill the "vector" objects
	fillVector(intVector, intNmbrs, INTS_SIZE);
	fillVector(doubleVector, dblNmbrs, DOUBLES_SIZE);
	fillVector(stringVector, strings, STRINGS_SIZE);
	fillVector(charVector, chars, CHARS_SIZE);


	cout <<   "Example #1: Initial State of \"vector\" objects"
		 << "\n  \"intVector\":    ";
	output(intVector);
	cout << "\n  \"doubleVector\": ";
	output(doubleVector);
	cout << "\n  \"stringVector\": ";
	output(stringVector);
	cout << "\n  \"charVector\":   ";
	output(charVector);
	cout << endl;


	cout << "\nExample #2: Rotate all \"vector\" objects one element to the Left"
		 << "\n            Note: 1st element is copied to last element";
	rotateLeft(intVector);
	rotateLeft(doubleVector);
	rotateLeft(stringVector);
	rotateLeft(charVector);

	cout << "\n  \"intVector\":    ";
	output(intVector);
	cout << "\n  \"doubleVector\": ";
	output(doubleVector);
	cout << "\n  \"stringVector\": ";
	output(stringVector);
	cout << "\n  \"charVector\":   ";
	output(charVector);
	cout << endl;


	cout << "\nExample #3: Reverse the sequence of all \"vector\" objects";
	reverse(intVector);
	reverse(doubleVector);
	reverse(stringVector);
	reverse(charVector);

	cout << "\n  \"intVector\":    ";
	output(intVector);
	cout << "\n  \"doubleVector\": ";
	output(doubleVector);
	cout << "\n  \"stringVector\": ";
	output(stringVector);
	cout << "\n  \"charVector\":   ";
	output(charVector);
	cout << endl;


	cout << "\nExample #4: Reverse, again the sequence of all \"vector\" objects"
		 << "\n            Note: Back to state after Example #2";
	reverse(intVector);
	reverse(doubleVector);
	reverse(stringVector);
	reverse(charVector);

	cout << "\n  \"intVector\":    ";
	output(intVector);
	cout << "\n  \"doubleVector\": ";
	output(doubleVector);
	cout << "\n  \"stringVector\": ";
	output(stringVector);
	cout << "\n  \"charVector\":   ";
	output(charVector);
	cout << endl;


	cout << "\nExample #5: Rotate all \"vector\" objects one element to the Right"
		 << "\n            Note: Last element is copied to 1st element";
	rotateRight(intVector);
	rotateRight(doubleVector);
	rotateRight(stringVector);
	rotateRight(charVector);

	cout << "\n  \"intVector\":    ";
	output(intVector);
	cout << "\n  \"doubleVector\": ";
	output(doubleVector);
	cout << "\n  \"stringVector\": ";
	output(stringVector);
	cout << "\n  \"charVector\":   ";
	output(charVector);
	cout << endl;


	cout << "\nExample #6: \"Accumulate\" (sum all) \"vector\" objects"
		 << "\n            Note: Not appropriate for a \"char\" vector!";
	cout << "\n     \"intVector\" sum: " << accum(intVector);
	cout << "\n  \"doubleVector\" sum: " << accum(doubleVector);
	cout << "\n  \"stringVector\" sum: " << accum(stringVector);
	cout << endl;


	cout << "\nExample #7A: Attempt to rotate Left an \"empty\" vector object";
	try
	{
		rotateLeft(emptyVector);
		cout << "\n  \"emptyVector\": ";
	}
	catch (EmptyVectorException)
	{
		cout << "\n  Error: \"vector\" object is empty!" << endl;
	}

	cout << "\nExample #7B: Attempt to rotate Right an \"empty\" vector object";
	try
	{
		rotateRight(emptyVector);
		cout << "\n  \"emptyVector\": ";
	}
	catch (EmptyVectorException)
	{
		cout << "\n  Error: \"vector\" object is empty!" << endl;
	}

	cout << "\nExample #7C: Attempt to reverse an \"empty\" vector object";
	try
	{
		reverse(emptyVector);
		cout << "\n  \"emptyVector\": ";
	}
	catch (EmptyVectorException)
	{
		cout << "\n  Error: \"vector\" object is empty!" << endl;
	}

	cout << "\nExample #7D: Attempt to \"Accumulate\" an \"empty\" vector object";
	try
	{
		cout << "\n\"emptyVector\" sum: " << accum(emptyVector);
	}
	catch (EmptyVectorException)
	{
		cout << "\n  Error: \"vector\" object is empty!" << endl;
	}


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

