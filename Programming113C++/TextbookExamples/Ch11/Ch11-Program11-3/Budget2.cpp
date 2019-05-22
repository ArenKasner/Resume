/******************************************************************************
*      Class: Budget2
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/30/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*       Method                          Description
* ------------------- ---------------------------------------------------------
* addDivisionBudget   Adds to current division budget and coporate budget
* addMainOfficeBudget Adds to current Main Office budget, adds to corp. (static)
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                             *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type          Name                    Description
* --------  --------  ----------------  ---------------------------------------
* static    double    MIN_BUDGET_VALUE  const: Minimum allowed budget value
* static    double    MAX_BUDGET_VALUE  const: Maximum allowed budget value
* static    double    corpBudget        Variable: Total Corporate budget
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Budget2.h"  // For Class Definition: Budget


// Definition of the static members of the Budget class
// 1. Constant "const" Value Initializations
const double Budget2::MIN_BUDGET_VALUE = 1.00;
const double Budget2::MAX_BUDGET_VALUE = 500000.00;

// 2. Variable Value Initialization
double Budget2::corpBudget = 0;

// External Class Method Definitions
// 1. Method: addBudget(double)
//    Adds budget value to divison's budget (non-static data member) and to the
//    Corporate budget (static data member)
void Budget2::addDivisionBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		divBudget += budgetValue;
		corpBudget += divBudget;
	}
}
//
// 2. Method: addMainOfficeBudget(double)
void Budget2::addMainOfficeBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		corpBudget += budgetValue;
	}
}
