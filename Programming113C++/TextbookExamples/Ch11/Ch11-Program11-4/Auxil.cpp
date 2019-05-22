/******************************************************************************
*      Class: Aux
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/01/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*    Methods                          Description
* -------------  --------------------------------------------------------------
* setAuxBudget   Set's Aux. Divison budget to a specific amount, adds to corp.
* addAuxBudget   Adds to current Aux. Division budget and corporate budget
*
*
* ------------------------------ Private Methods ------------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*              Data
*    Type      Type         Name                    Description
* ----------  ------  ----------------  ---------------------------------------
* static      double  MIN_BUDGET_VALUE  Minimum allowed budget value    (const)
* static      double  MAX_BUDGET_VALUE  Maximum allowed budget value    (const)
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Auxil.h"
#include "Budget3.h"


// Definition of the static members of the Budget class
// 1. Constant "const" Value Initializations
const double Aux::MIN_BUDGET_VALUE = 1.00;
const double Aux::MAX_BUDGET_VALUE = 500000.00;

// External Class Method Definitions
// 1. Method: addBudget(double)
//    Sets a Class object's, non-static, instance budget value to a
//    validated budget value and adds the value to Class "Budget3"s
//    static variable "corpBudget
void Aux::setAuxBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		if (auxBudget > 0)
			Budget3::corpBudget -= auxBudget;

		auxBudget += budgetValue;
		Budget3::corpBudget += budgetValue;
	}
}
// 2. Method: addBudget(double)
//    Adds budget value to divison's budget (non-static data member) and to the
//    Corporate budget (static data member)
void Aux::addAuxBudget(double budgetValue)
{
	if (budgetValue >= MIN_BUDGET_VALUE  &&  budgetValue <= MAX_BUDGET_VALUE)
	{
		auxBudget += budgetValue;
		Budget3::corpBudget += budgetValue;
	}
}
