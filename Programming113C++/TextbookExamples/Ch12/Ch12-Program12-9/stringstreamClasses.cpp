/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook Example Program
* Chapter: 12
* Program: 12-9
*
* Solution/Project Name: Ch12-Program12-9
*             File Name: stringstreamClasses.cpp
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
*  Device                            Description
* --------  ------------------------------------------------------------------
* Keyboard  1. Name and two test scores for student #1
*           2. Name and two test scores for student #2
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  ------------------------------------------------------------------
* Monitor   Display the formatted "string" from the "ostringstream" object 
*
*
* File Methods
* ------------
* None
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <sstream>   // Defines Classes: istringstream and ostringstream
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines I/O stream Manipulators
#include <string>    // Defines Class: string

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
*
* Pre-Conditions
* --------------
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
* ------------  --------------------------------------------------------------
*
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 string str = "John  23 50";       // "string" to read from
	 const char* cstr = "Amy 30 47";   // C-String to read from

	 // Utilize both versions of the "istringstream" Constuctors
	 // 1. Conversion Constructor
	 //    Source: A "string" object
	 istringstream istr1(str);  // istr1 will read from str
	 // 2. Default Constructor
	 //    Source: To be set using class method "str()"
	 istringstream istr2;  // istr2 will read from cstr
	 // Establish an "ostringstring" object to receive "string" data
	 ostringstream ostr;

	 string name;
	 int score1, score2;
	 double average_score;


	 cout << "            Textbook Example Program 12-9:\n"
		  << "Examples of classes \"istringstream\" and \"ostringstream\"" 
		  << endl << endl;


	 // Direct the "ostr" stream object to format floating-point values
	 // it receives showing the decimal point and 2 digits of precision.
	 ostr << fixed << setprecision(2);

	 // Read name and scores and compute average then write to the "ostr" object
	 istr1 >> name >> score1 >> score2;
	 // Now insert the text information for the 1st person into the "ostr" stream
	 ostr << "\n   " << name << "'s scores are: " << score1 << " and " << score2
		  << " (decimal)" << endl;
	 ostr << hex;  // Switch to display "int" values in hexidecimal format
	 ostr << "   " << name << "'s scores are: " << score1 << " and " << score2
		 << " (hexidecimal)" << dec << endl;  // Switch back to decimal formatting
	 average_score = (score1 + score2) / 2.0;
	 ostr << name << "'s average score: " << average_score << "\n";

	 // Set object "istr2" to read from the C string and repeat the above
	 istr2.str(cstr);
	 istr2 >> name >> score1 >> score2;
	 // Insert the text information for the 2nd person into the "ostr" stream
	 ostr << "\n   " << name << "'s scores are: " << score1 << " and " << score2
		  << " (decimal)" << endl;
	 ostr << hex;  // Switch to display "int" values in hexidecimal format
	 ostr << "   " << name << "'s scores are: " << score1 << " and " << score2
		  << " (hexidecimal)" << dec << endl;  // Switch back to decimal formatting
	 average_score = (score1 + score2) / 2.0;
	 ostr << name << "'s average score: " << average_score << endl;

	 // Extract the string from ostr and insert it into the Console Monitor stream
	 cout << ostr.str();


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

