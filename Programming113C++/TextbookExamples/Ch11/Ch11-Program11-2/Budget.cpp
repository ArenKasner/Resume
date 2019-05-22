/******************************************************************************
*      Class: Budget
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
*   Method                          Description
* ---------- ---------------------------------------------------------
* addBudget  Adds to current division budget and coporate budget
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*            Data
*    Type    Type          Name                    Description
* --------  ------  ----------------  -----------------------------------------
* static    double  MIN_BUDGET_VALUE  const: Minimum allowed budget value
* static    double  MAX_BUDGET_VALUE  const: Maximum allowed budget value
* static    double  corpBudget        Variable: Total Corporate budget
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Budget.h"  // For Class Definition: Budget


// Definition of the static members of the Budget class
// 1. Constant "const" Value Initializations
//    Note: The key word "static" is only used as a qualifier in the
//          Class definition
const double Budget::MIN_BUDGET_VALUE = 1.00;
const double Budget::MAX_BUDGET_VALUE = 500000.00;

// 2. Variable Value Initialization
double Budget::corpBudget = 0;

// External Class Method Definitions
// 1. Method: addBudget(double)
//    Adds budget value to divison's budget (non-static data member) and to the
//    Corporate budget (static data member)
void Budget::addBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		divBudget += budgetValue;
		corpBudget += budgetValue;
	}
}

