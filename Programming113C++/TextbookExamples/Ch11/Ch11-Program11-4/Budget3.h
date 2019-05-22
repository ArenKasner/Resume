#pragma once

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
* Class Description
* -----------------
* This Class defines a Corporate Budget structure, consisting of individual
* division budgets, objects of the Class, a Main Office budget, a "static"
* value, and a total coprporate budget, a "static" value.
*
* In addition, provision is allowed via "friend" declarations to allow access
* to updating the corporate budget amount from other Class objects of type
* "Aux", which represent "Auxillary" offices, separate from a "Division" office.
*
*
* ----------------------------- Public Interface ------------------------------
*       Method                              Description
* ------------------- ---------------------------------------------------------
* Budget3             Default Constructor: Budget set to 0.00
* setDivisionBudget   Set's division budget to a specific amount, adds to corp.
* addDivisionBudget   Adds to current division budget and corporate budget
* setMainOfficeBudget Set's Main Office budget, adds to corp.           (static)
* addMainOfficeBudget Adds to current Main Office budget, adds to corp. (static)
* getCorpBudget       RETurns current Corporate's total budget          (static)
* getMainOfficeBudget RETurns current Main Office's total budget        (static)
* getDivBudget        RETurns current division object's total budget
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
*    Type      Type          Name                    Description
* ----------  ------  ----------------  ---------------------------------------
* static      double  corpBudget        Variable: Total budget for Corporation
* static      double  mainOfficeBudget  Variable: Total budget for Main Office
* non-static  double  divBudget         Total budget for division object
* static      double  MIN_BUDGET_VALUE  const: Minimum allowed budget value
* static      double  MAX_BUDGET_VALUE  const: Maximum allowed budget value
*
*
* -------------------------- Friend Declarations ------------------------------
* Granted     Allowed
*  Class      Method                       Allowed Activity
* -------  -------------  -----------------------------------------------------
* AUX      setAuxBudget   Update (add to) the corporate total budget
* AUX      addAuxBudget   Update (add to) the corporate total budget
*
*******************************************************************************
*/
// External Definition files
// Defines Class: AUX, specifically, "friend" method, "addAuxBudget"
#include "AUXIL.h" 

class Budget3
{
private:
	// 1. "static" Variable Declarations
	//    Note: Initialization occurs in the external, Class source code file.
	static double corpBudget;
	static double mainOfficeBudget;
	// 2. Non-static (instance) Variable Declarations
	double divBudget;

public:
	// 1. Class Default Constructor
	Budget3() : divBudget(0)
	{ }

	// 2. Class Mutator Methods
	//    A. Method: addDivisionBudget(double)
	//       Sets a Class object's, non-static, instance budget value to a
	//       validated budget value
	void setDivisionBudget(double budgetValue);
	//    B. Method: addDivisionBudget(double)
	//       Adds a validated budget value to a Class object's, non-static,
	//       instance budget value
	void addDivisionBudget(double budgetValue);
	//
	//    C. Method: setMainOfficeBudget(double)
	//       Note: Method declared static since it only affects a Class,
	//             "static" data member
	static void setMainOfficeBudget(double budgetValue);
	//
	//    D. Method: addMainOfficeBudget(double)
	//       Note: Method declared static since it only affects a Class,
	//             "static" data member
	static void addMainOfficeBudget(double budgetValue);
	//
	// 3. Class Observer Methods
	//    A. Method: getDivBudget()
	double getDivBudget() const
	{ return divBudget; }
	//
	//    B. getCorpBudget()
	//       Notes:
	//       1. Method declared static since it accesses ONLY a Class, "static"
	//          data member
	//       2. A Class "static" method cannot be declared "const"
	static double getCorpBudget()
	{
		return corpBudget;
	}
	//
	//    C. getMainOfficeBudget()
	double getMainOfficeBudget()
	{ return mainOfficeBudget; }
	//
	//
	// 4. "Friend" Method Declarations
	friend void Aux::setAuxBudget(double);
	friend void Aux::addAuxBudget(double);

	// 5. Class "static const" Value Declarations
	//    Note: Initialization occurs in the external, Class source code file.
	static const double MIN_BUDGET_VALUE;
	static const double MAX_BUDGET_VALUE;

};
