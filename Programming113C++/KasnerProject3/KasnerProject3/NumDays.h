#pragma once

/******************************************************************************
*       Class: NumDays      (Ex: Car)
*  Base Class: ** None **  Supply Base Class name if inheritance applies
*
* This file defines the members of the class: NumDays
* These members include class variable data members, class constant, static
* data members, and class method declarations only and/or class method
* declarations and definitions.
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/21/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
* Class Description
* -----------------
* NumDays   Encapsulates hours worked with methods to indicate days and hours
* ** Describe the class defined here, including it's purpose  **
* ** This may take several lines to describe                  **
*
*
* ----------------------------- Public Interface ------------------------------
*      Method                               Description
* ----------------  -----------------------------------------------------------
* 1.  Default Constructor: Sets hours worked to 0
* 2.  Initializing Constructor: hours worked
* 3.  Destructor
* 4.  getDays(): Number of whole days for the hours worked
* 5.  getHours(): Number of residual hours after whole days calculated
* 6.  addHours(double): Add hours to the Class object

*
* ------------------------------ Private Methods ------------------------------
*       Name                               Description
* ----------------  -----------------------------------------------------------
* 6.  Operator Addition: Adds hours of two Class objects, RETurns a Class object
* 7.  Operator Subtraction: Subtract's one Class hours from another
* 8.  Combined Subtraction Operator: Subtracts hours from one object
* 9.  Prefix Increment Operator: Increments class object's hours by 1 hour
* 10. Postfix Increment Operator: Increments class object's hours by 1 hour
* 11. Prefix Decrement Operator: Decrements class object's hours by 1 hour
* 12. Postfix Decrement Operator: Decrements class object's hours by 1 hour
* 13. Stream Insertion Operator: Inserts days/hours worked into stream object
*
*
* --------------------------- Private Data Members ----------------------------
*               Data
*    Type       Type       Name                    Description
* ---------- --------- ------------ -------------------------------------------
* non-static double		HoursWorked This is the number of hours worked.
*
*
* ------------------  Public "static const" Data Members ----------------------
*   Data
*   Type         Name                         Description
* --------  --------------  ---------------------------------------------------
*                       *** No public data members ***
*
*******************************************************************************
*/
// External Definition Files
#include <iostream>


class NumDays
{
public:
	// 1. Non-static (instance) Variable Declarations
	double hoursWorked;

	// 2. Static Constant Value Declarations


	// 1. Constructors
	//    A. Default Constructor //sets hours worked to zero
	NumDays();
	//    B. Initializing Constructors HoursWorked
	NumDays(double);
	//    C. Conversion Constructors

	// 2. Class Destructor
	~NumDays();

	// 3. Mutator Methods
	double getDays() const; //Number of whole days for the hours worked
	double getHours() const; //Number of residual hours after whole days calculated
	double addHours(double);//Add hours to the Class object

	// 4. Observer Methods
	NumDays operator+(const NumDays &);//Operator Addition: Adds hours of two Class objects, RETurns a Class object
	NumDays operator+=(const NumDays& other_days);
	NumDays operator-(const NumDays &); //Operator Subtraction: Subtract's one Class hours from another

	NumDays operator-=(const NumDays &);// Combined Subtraction Operator: Subtracts hours from one object

	NumDays operator++();//Prefix Increment Operator: Increments class object's hours by 1 hour
	NumDays operator++(int);//Postfix Increment Operator: Increments class object's hours by 1 hour
	NumDays operator--();//Prefix Decrement Operator: Decrements class object's hours by 1 hour
	NumDays operator--(int);//Postfix Decrement Operator: Decrements class object's hours by 1 hour

	friend std::ostream& operator<<(std::ostream& os, const NumDays &);

	//Stream Insertion Operator: Inserts days/hours worked into stream object
	// 6. Type Conversion Operators

	// 7. Granted "friend" Method Declarations

	// 8. Public "static const" Value Declarations
};


//Operator Subtraction: Subtract's one Class hours from another

