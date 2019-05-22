/******************************************************************************
*       Class: NumDays       (Ex: Car)
*  Base Class: ** None **  Supply Base Class name if inheritance applies
*
*
* This file defines the static, const data members, if any, and the class
* methods not defined in the class definition file, NumDays.h
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  ------------------------------------------------------
*   1.0     04/21/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* ----------------------------- Public Interface -----------------------------
*      Method                               Description
* ----------------  ----------------------------------------------------------
* 1.  Default Constructor: Sets hours worked equal to 0
* 2.  Initializing Constructor: hours worked equal to input
* 3.  Destructor
* 4.  getDays(): Number of whole days for the hours worked
* 5.  getHours(): Number of residual hours after whole days calculated
* 6.  addHours(double): Add hours to the Class object
*
*
* ------------------------------ Private Methods -----------------------------
*       Name                               Description
* ----------------  ----------------------------------------------------------
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
*
* ------------------------- Data Member Initializations ----------------------
*               Data
*    Type       Type         Name                   Description
* ----------  --------  --------------  --------------------------------------
*
******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include "NumDays.h"   // Class Definition file

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace "std"
                     // are utilized in this program


	// Class Constant Value Initializations

	// Class Default Constructor
	NumDays::NumDays()
	{
		hoursWorked = 0.00;
	}
	//    B. Initializing Constructors //sets hours worked to zero
	NumDays::NumDays(double input)
	{
		hoursWorked = input;
	}
	//    C. Conversion Constructors

	// 2. Class Destructor
	NumDays::~NumDays()
	{
		
	}
	// 3. Mutator Methods
    double NumDays::getDays() const//getDays(): Number of whole days for the hours worked
	{
		int daysWorked;
		daysWorked = this->hoursWorked / 8;
		return daysWorked;
	}
	double NumDays::getHours() const//	getHours(): Number of residual hours after whole days calculated
	{
		
		int daysWorked = this->getDays();
		
		double hoursExtra = this->hoursWorked - (daysWorked * 8);
		return hoursExtra;
	}
	double NumDays::addHours(double input)//Add hours to the Class object
	{
		this->hoursWorked = this->hoursWorked + input;
		return this->hoursWorked;
	}

	NumDays NumDays::operator+(const NumDays & other_days)//Operator Addition: Adds hours of two Class objects, RETurns a Class object
	{

		NumDays temp = *this;
		temp.hoursWorked += other_days.hoursWorked;
		return temp;
	}


	// 4. Observer Methods

	// 5. Overloaded Operators

	NumDays NumDays::operator-(const NumDays & other_days)  //Operator Subtraction: Subtract's one Class hours from another
	{
		NumDays temp = *this;
		temp.hoursWorked -= other_days.hoursWorked;
		return temp;
	}

	NumDays NumDays::operator-=(const NumDays &other_days)// Combined Subtraction Operator: Subtracts hours from one object
	{
		
		this->hoursWorked = this->hoursWorked - other_days.hoursWorked;
		return *this;
	}

NumDays NumDays::operator++()//Prefix Increment Operator: Increments class object's hours by 1 hour
{
	this->hoursWorked = this->hoursWorked + 1;
	
	return *this;
}

NumDays NumDays::operator++(int)//Postfix Increment Operator: Increments class object's hours by 1 hour
{
	NumDays tmp(*this);
	operator++();
	return tmp;
}

NumDays NumDays::operator--()//Prefix Decrement Operator: Decrements class object's hours by 1 hour
{
	this->hoursWorked = this->hoursWorked - 1;

	return *this;
}

NumDays NumDays::operator--(int)//Postfix Decrement Operator: Decrements class object's hours by 1 hour
{
	NumDays tmp(*this);
	operator--();
	return tmp;
}


ostream& operator<<(std::ostream& os, const NumDays& obj)//Stream Insertion Operator: Inserts days/hours worked into stream object
{
	double daysFinal = obj.getDays();
	double hoursFinal = obj.getHours();
	return os << daysFinal << " days, " << hoursFinal <<" hours ";
}