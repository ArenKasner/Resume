/******************************************************************************
*      Class: Budget3
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
* setDivisionBudget   Set's division budget to a specific amount, adds to corp.
* addDivisionBudget   Adds to current division budget and coporate budget
* setMainOfficeBudget Set's Main Office budget, adds to corp.           (static)
* addMainOfficeBudget Adds to current Main Office budget, adds to corp. (static)
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*             Data
*   Type      Type          Name                    Description
* --------  --------  ----------------  ---------------------------------------
* static    double    MIN_BUDGET_VALUE  const: Minimum allowed budget value
* static    double    MAX_BUDGET_VALUE  const: Maximum allowed budget value
* static    double    corpBudget        Variable: Total Corporate budget
* static    double    mainOfficeBudget  Variable: Total Main Office budget
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Budget3.h"  // For Class Definition: Budget3


// Definition of the static members of the Budget class
// 1. Constant "const" Value Initializations
const double Budget3::MIN_BUDGET_VALUE = 1.00;
const double Budget3::MAX_BUDGET_VALUE = 500000.00;

// 2. Variable Value Initializations
double Budget3::corpBudget = 0;
double Budget3::mainOfficeBudget = 0;

// External Class Method Definitions
// 1. Method: setDivisionBudget(double)
//    Sets a Class object's, non-static, instance budget value to a
//    validated budget value
void Budget3::setDivisionBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		if (divBudget > 0)
			corpBudget -= divBudget;

		divBudget = budgetValue;
		corpBudget += budgetValue;
	}
}
// 2. Method: addDivisionBudget(double)
//    Adds budget value to divison's budget (non-static data member) and to the
//    Corporate budget (static data member)
void Budget3::addDivisionBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		divBudget += budgetValue;
		corpBudget += budgetValue;
	}
}
//
// 3. Method: setMainOfficeBudget(double)
void Budget3::setMainOfficeBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		if (mainOfficeBudget > 0)
			corpBudget -= mainOfficeBudget;

		mainOfficeBudget = budgetValue;
		corpBudget += budgetValue;
	}
}
//
// 3. Method: addMainOfficeBudget(double)
void Budget3::addMainOfficeBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		mainOfficeBudget += budgetValue;
		corpBudget += budgetValue;
	}
}
