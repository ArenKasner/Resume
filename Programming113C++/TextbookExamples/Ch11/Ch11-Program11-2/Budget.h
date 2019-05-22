#pragma once

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
* Class Description
* -----------------
* This Class defines a Corporate Budget structure, consisting of individual
* division budgets, objects of the Class, a Main Office budget, a "static"
* value, and a total coprporate budget, a "static" value.
*
*
* ----------------------------- Public Interface ------------------------------
*    Method                              Description
* -------------  --------------------------------------------------------------
* Budget         Default Constructor: Budget set to 0.00
* addBudget      Adds to current division budget and coporate budget
* getDivBudget   RETurns current division object's total budget
* getCorpBudget  RETurns current Corporate's total budget              (static)
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type         Name                     Description
* ----------  ------  ----------------  ---------------------------------------
* static      double  corpBudget        Variable: Total budget for Corporation
* non-static  double  divBudget         Total budget for division object
* static      double  MIN_BUDGET_VALUE  const: Minimum allowed budget value
* static      double  MAX_BUDGET_VALUE  const: Maximum allowed budget value
*
*******************************************************************************
*/
class Budget
{
private:
	// 1. Class "static const" Value Declarations
	//    Note: Initialization occurs in the external, Class source code file.
	static const double MIN_BUDGET_VALUE;
	static const double MAX_BUDGET_VALUE;
	//
	// 2. "static" Variable Declaration
	//    Note: Initialization occurs in the external, Class source code file.
	static double corpBudget;
	//
	// 3. Non-static (instance) Variable Declarations
	double divBudget;

public:
	// 1. Class Default Constructor
	Budget() : divBudget(0)
	{ }

	// 2. Class Mutator Methods
	//    A. Method: addBudget(double)
	//       Adds a validated budget value to a Class object's, non-static
	//       (instance) budget value
	void addBudget(double bValue);
	//
	// 3. Class Observer Methods
	//    A. Method: getDivBudget()
	double getDivBudget() const
	{ return divBudget; }
	//    B. getCorpBudget()
	//       Notes:
	//       1. Method declared static since it accesses ONLY a Class, "static"
	//          data member
	//       2. A Class "static" method cannot be declared "const"
	static double getCorpBudget()
	{ return corpBudget; }
};
