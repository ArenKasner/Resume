/******************************************************************************
* Bellevue Class: PROG 113
*     Instructor: Robert Main
*
* Textbook: Starting Out With C++: Early Objects
*  Authors: Tony Gaddis, Judy Walters, and Godfrey Muganda
*  Edition: 8th
*
* Textbook Example Program
* Chapter: 11
* Program: 11-3
*
* Solution/Project Name: Ch11-Program11-3
*             File Name: TStaticDataMembers.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Robert Main
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     03/30/2015  Initial Release
*
* File Methods
* ------------
*  Name                             Description
* ------  --------------------------------------------------------------------
* main    Program entry point method
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Budget2.h"            // For Budget class declaration

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program


/******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program demonstrates the declaration, initialization, and use od Class
* "static" data members. THe program creates an array of "Budget2" objects,
* corporate divisions, then solicits budget values for each division and
* adds the value to the division via a Class mutator method. This method
* will add the budget value, if it is in the allowed range of values, to the
* array object's non-static data member. In addition, it will add the value
* to the Class, static data member, which repreents the entire corrporate
* budget. The corporate budget value is declared "static", since only one
* "copy" of the value is needed, regardless of the number of divisions.
*
* In addition, two "static const" values are declared and initialized, which
* represent the minimum and maximum allowed budget values for any division.
* There need be only one "copy" of these values also, regardless of the number
* of divisions (Class objects). In this version of gthe program, they are
* declared as "public" data members. This does not violate the OO design
* goal of encapsulation of "private" data with Class, public methods since
* the data members are declared "const" and cannot be modified by Client code.
* In this example, it is advantageous to declare the "const" values public
* so that Client code is aware of the restrictions for adding budget values
* to either the Main Office budget or any division's budget.
*
* Finally, this program enhances the program 11-2 by providing a static mutator
* method to add a Main Office budget amount to just the total, static
* corporate budget amount.
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ------------------------------------------------
*                       *** No Arguments Defined ***
*
*
* Return Value
* ------------
* Type                              Description
* ----  ---------------------------------------------------------------
* int   Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
* None
*
***************************************************************************
*/
int main()
{
	// Constant "const" Value Declaration
	const int NO_ERRORS = 0;
	const int N_DIVISIONS = 4;

	// Uninitialized Array Declaration
	Budget2 divisions[N_DIVISIONS];
	double budgetValue;
    

	cout << "Textbook Example Program 11-3: Static Data Members, Part 2"
		 << endl << endl;


	cout << fixed << setprecision(2);

	// First, get the Corporate, Main Office budget
	// Utilize the Class "static const" values, declared "public" to inform the User
	// of the allowed range of values for the requested budget amount.
	cout << "Enter the budget request for the Main Office (" << Budget2::MIN_BUDGET_VALUE
		 << " - " << Budget2::MAX_BUDGET_VALUE <<"): ";
	cin >> budgetValue;
	// Note: When invoking a Class "static" method, the method is resolved to'
	//       the Class itself, as the static method cannot affect non-static
	//       data members, and hence cannot be bound to a Class object.
	Budget2::addMainOfficeBudget(budgetValue);


	// Get the budget request for each division
	for (int count = 0; count < N_DIVISIONS; count++)
	{
		cout << "Enter the budget request for division " << (count + 1)
			 << " (" << Budget2::MIN_BUDGET_VALUE << " - "
			 << Budget2::MAX_BUDGET_VALUE << "): ";
		cin >> budgetValue;
		divisions[count].addDivisionBudget(budgetValue);
	}
		
	// Display the budget request for each division
	cout << "\nHere are the division budget requests:\n";
	for (int count = 0; count < N_DIVISIONS; count++)
	{
	cout << "  Division " << (count + 1) << ": $ ";
		cout << divisions[count].getDivBudget() << endl;
	}
		
	// Display the total budget request
	cout << "\nCorporate Budget: $ ";
	// Note: A Class object may bind itself to a Class "static" method.
	//       However, bindng it to the Class itself is preferable:
	//         cout << Budget2::getCorpBudget() << endl;
	cout << divisions[0].getCorpBudget() << endl; 


	// This prevents the Console Window from closing during debug mode
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;

}	// End Method: main()