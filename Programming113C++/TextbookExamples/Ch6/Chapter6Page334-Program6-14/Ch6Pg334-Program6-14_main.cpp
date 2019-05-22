/******************************************************************************
 * Bellevue Class: PROG 111
 * Textbook Program Examples
 * Textbook: Starting Out with C++, Early Objects - 7th Edition
 *
 * Solution/Project Name: Ch6Pg334-Program6-14
 * File Name:             Ch6Pg334-Program6-14_main.cpp
 *
 * This file defines the entry point ( main() ) for the Console application.
 *
 * Programmer: Robert Main
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     11/04/2012  Initial Release
 *
 * File Desciption
 * ---------------
 * This program demonstrates the use of methods to support Menu-Driven programs.
 * The program first calls the method "displayMenu()" that presents a
 * Membership Menu, which consists of selections for the various membership
 * offerings.
 *
 * Next the method "getChoice" is called to prompt the User for a selection
 * from the Menu.The selection is validated and if not valid, the User is
 * prompted to re-enter a selection, one of which is to quit the program.
 * The method RETurns the validated Menu Selection, an enumerated data type.
 *
 * Next, the method "getMonths()" is called to prompt the User for the number
 * of months of membership the User wishes to pay. The value entered is
 * validated and if not valid, the User is prompted to re-enter a value.
 * The method RETurns the validated numbe of months value, which completes the
 * required data entry from the User.
 *
 * Next, the total fee is calculated with a call to function "calculateFee()",
 * passing the User's membership type and number of months selections as
 * parameters. Once the monthly rate and total fee is determined,
 * "calculateFee()" calls method "showFees()" to display the results, passing
 * the membership type, the monthly membership rate,the number of months, and
 * the total calculated memberssip fee as parameters.
 *
 * The methods are designed to "encapsulate" as much "internal" information as
 * possible within the individual methods. For instance, method "getMonths()"
 * "contains" the minimum and maximum number of months allowed for the entry.
 * The values are declared "const" and are local to the method, i.e. can not
 * be accessed from outside the method. A similar situation occurs for the
 * method "calculateFee()", where the possible monthly rates and the
 * description strings corresponding to the Menu membership types allowed are
 * declared as "const" values, local to the method.
 *
 * This process of functional decomposition leaves the code in "main()" to
 * "conduct" the process of determining the membership fee by calling the
 * various methods in the proper sequence to accomplish the task.
 *
 ******************************************************************************
 */
#include "stdafx.h"  // Defines external definiton files required for the program
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines the output stream manipulators
#include <string>    // Defines the "string" class
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program

// Global Enumeration
enum MemberMenuSelections
{
	STANDARD_ADULT = 1, CHILD, SENIOR_ADULT, QUIT
};

// Function Prototypes
void displayMenu();
MemberMenuSelections getChoice();
int getMonths();
double calculateDisplayFees(MemberMenuSelections menuSelection, int months);
void showFees(string category, double rate, int months, double totalFee);


/******************************************************************************
 * Function: main                                                             *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 *   None                                                                     *
 *                                                                            *
 * RETurn Value                                                               *
 * ------------                                                               *
 * Type  Value                           Description                          *
 * ----  -----  --------------------------------------------------------------*
 * int   0      No error(s) status to Operating System                        *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 *         Name                               Description                     *
 * --------------------  -----------------------------------------------------*
 * displayMenu           Displays the Membership Menu to the User             *
 * getChoice             Obtain a valid Menu choice from the User             *
 * getMonths             Obtain a valid membership term, in months from User  *
 * calculateDisplayFees  Calculate total membership Fee and display results   *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * This is the entry function to program.                                     *
 *                                                                            *
 ******************************************************************************
 */
int main()
{
	// Variable Declarations
	MemberMenuSelections menuChoice;  // User's menu choice
	int months;                       // Number of months being paid 
	double totalFee;                  // Total Membership Fee

	// Set numeric output formatting
	cout << fixed << showpoint << setprecision(2);
	
    do
    {
		displayMenu();
		menuChoice = getChoice(); // Assign choice the value returned 
                                  // by the getChoice function 
		if (menuChoice != QUIT)   // Does the User wish to Quit? 
		{	// No: Proceed...
			months = getMonths();
			totalFee = calculateDisplayFees(menuChoice, months);
		}
	} while (menuChoice != QUIT);

	return 0;
}

/******************************************************************************
 * Function: displayMenu                                                      *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * None                                                                       *
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ----  ---------------------------------------------------------------------*
 * None                                                                       *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Clears the Console screen, then presents the Membersip Menu selections     *
 *                                                                            *
 ******************************************************************************
 */
void displayMenu()
{
	system("cls");          // Clear the screen.
	cout << "\n  Health Club Membership Menu\n\n";
	cout << (int)STANDARD_ADULT << ".  Standard Adult Membership\n";
	cout << (int)CHILD << ".  Child Membership\n";
	cout << (int)SENIOR_ADULT << ".  Senior Citizen Membership\n";
	cout << (int)QUIT << ".  Quit the Program\n\n";

	return;
}


/******************************************************************************
 * Function: getChoice                                                        *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * None                                                                       *
 *                                                                            *
 *     RETurn Value                              Description                  *
 * --------------------  -----------------------------------------------------*
 * MemberMenuSelections  User's valid Menu selection                          *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Solicits User's Membership choice and validates the choice.                *
 * The function will NOT return to the calling method until a valid Menu      *
 * choice is entered.                                                         *
 *                                                                            *
 ******************************************************************************
 */
MemberMenuSelections getChoice()
{	
	// Variable Declarations
	int choice;
	bool validChoice;

	MemberMenuSelections menuSelection = QUIT;

	do
	{
		cout << "Enter your Membership choice: ";
		cin >> choice;

		if (choice < STANDARD_ADULT || choice > QUIT)
		{	cout << "Error: Choice " << choice << " is invalid, try again\n";
			validChoice = false;
		}
		else
		{
			menuSelection = (MemberMenuSelections)choice;
			validChoice = true;
		}
	}
	while (!validChoice);

	return menuSelection;
}


/******************************************************************************
 * Function: getMonths                                                        *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 * None                                                                       *
 *                                                                            *
 * RETurn                                                                     *
 * Value                                   Description                        *
 * ------  -------------------------------------------------------------------*
 * int     User's valid number of months data entry                           *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Solicits User's number of months value and validates the value.            *
 * The function will NOT return to the calling method until a valid number    *
 * of months value is entered.                                                *
 *                                                                            *
 ******************************************************************************
 */
int getMonths()
{
	// Constant "const" Declarations
	const int MIN_MONTHS = 1;
	const int MAX_MONTHS = 60;

	// Variable Declarations
	int numberMonths;
	bool validValue;

	MemberMenuSelections menuSelection = QUIT;

	do
	{
		cout << "Enter the number of membership months (" <<  MIN_MONTHS
			 << " - " << MAX_MONTHS << "): ";
		cin  >> numberMonths;

		if (numberMonths < MIN_MONTHS || numberMonths > MAX_MONTHS)
		{	cout << "Error: Choice " << numberMonths << " is invalid, try again\n";
			validValue = false;
		}
		else
			validValue = true;
	}
	while (!validValue);

	return numberMonths;
}




/******************************************************************************
 * Function: calculateDisplayFees                                             *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 *          Type              Name                    Description             *
 * --------------------  -------------  --------------------------------------*
 * MemberMenuSelections  menuSelection  Membership type, from Menu selection  *
 * int                   months         Number of Membership months           *
 *                                                                            *
 * RETurn                                                                     *
 * Value                                   Description                        *
 * ------  -------------------------------------------------------------------*
 * double  Total membership Fee required                                      *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 *   Name                            Description                              *
 * --------  -----------------------------------------------------------------*
 * showFees  Display Fees information to User: 1) Membership type,            *
 *           2) Monthly Rate, 3) Number of Months, and 4) Total Membership Fee*
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Determines the total membership fee, given the membership type and the     *
 * number of months the User wishes to pay.                                   *
 *                                                                            *
 ******************************************************************************
 */
double calculateDisplayFees(MemberMenuSelections menuSelection, int months)
{
	// Constants "const" Declarations
	// 1. monthly Membership rates
	const double ADULT_RATE =  40.00,
                 SENIOR_RATE = 30.00,
                 CHILD_RATE =  20.00,
				 UNKNOWN_RATE = 0.00;
	// 2. Membership Types
	const string MEMBERTYPE_STANDARD_ADULT = "Adult";
	const string MEMBERTYPE_CHILD =          "Child";
	const string MEMBERTYPE_SENIOR_ADULT =   "Senior";

	// Variable Declaration
	double monthlyRate;
	double totalFee;
	string membershipType;


	switch (menuSelection)
	{
		case STANDARD_ADULT:
			membershipType = MEMBERTYPE_STANDARD_ADULT;
			monthlyRate =    ADULT_RATE;
			break;

		case CHILD:
			membershipType = MEMBERTYPE_CHILD;
			monthlyRate =    CHILD_RATE;
			break;

		case SENIOR_ADULT:
			membershipType = MEMBERTYPE_SENIOR_ADULT;
			monthlyRate =    SENIOR_RATE;
			break;

		default:
			monthlyRate = UNKNOWN_RATE;
			totalFee =   0.0;
	}

	if (monthlyRate == UNKNOWN_RATE)
		cout << "Error: Unknown Membership Menu Selection!\n";
	else
	{
		totalFee = monthlyRate * months;
		showFees(membershipType, monthlyRate, months, totalFee);
	}

	return totalFee;
}
	

/******************************************************************************
 * Function: showFees                                                         *
 *                                                                            *
 * Parameters                                                                 *
 * ----------                                                                 *
 *  Type       Name                          Description                      *
 * ------  ------------  -----------------------------------------------------*
 * string  memberType    Membership type description, as a string             *
 * double  monthlyRate   Number of Membership months                          *
 * int     months        Number of Membership months                          *
 * double  totalFee      Total Membership Fee                                 *
 *                                                                            *
 * RETurn                                                                     *
 * Value                              Description                             *
 * ------  -------------------------------------------------------------------*
 * double  Total Meembership Fee                                              *
 *                                                                            *
 * Methods Called                                                             *
 * --------------                                                             *
 * None                                                                       *
 *                                                                            *
 * Function Description                                                       *
 * --------------------                                                       *
 * Displays the Membership information to the User, then waits for the User   *
 * to review the information by pausing the program until the User presses    *
 * the Console "Enter" key.                                                   *
 *                                                                            *
 ******************************************************************************
 */
void showFees(string memberType, double monthlyRate, int months,
	          double totalFee)
{
	cout << "\nMembership Type : "  << memberType
		 << "\nMonthly Rate:     "  << monthlyRate
		 << "\nNumber of months: "  << months
		 << "\nTotal Fee:        $" << totalFee << endl;

	// Pause the program until the User presses the ENTER key.
	// This next statement purges any characters, if any, remaining in the
	// Console input buffer, BEFORE "cin.get()" looks for the "new line" character
	cin.ignore(cin.rdbuf()->in_avail(), '\n');
	cout << endl << "Press only the 'Enter' key to continue: ";
	cin.get();

	return;
}

