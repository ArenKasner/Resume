#pragma once

/******************************************************************************
*      Class: Aux
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
* This Class represnts th budget activities of "Auxillary" offices, which are
* separate entities from a corporate "Division" office. Budget values updated
* by objects of this Class need to update the total corporate budget amount,
* which is encapsulated in the "Budget3" Class, which represents "Division"
* offices.
*
* The "Budget3" Class grants access to its private data members by granting
* "friend" status to the two methods in this Class that need to update the
* totatl corporate budget maintained in the "Budget3" Class, namely methods
* "setAuxBudget" and "addAuxBudget".
*
*
* ----------------------------- Public Interface ------------------------------
*    Method                              Description
* -------------  --------------------------------------------------------------
* Aux            Default Constructor: Budget set to 0.00
* setAuxBudget   Set's Aux. Divison budget to a specific amount, adds to corp.
* addAuxBudget   Adds to current Aux. Division budget and corporate budget
* getAuxBudget   RETurns current Auxillary Divison's total budget
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
*    Type      Type         Name                      Description
* ----------  ------  ----------------  ---------------------------------------
* non-static  double  auxBudget         Total budget: Auxillary Division object
* static      double  MIN_BUDGET_VALUE  Minimum allowed budget value
* static      double  MIN_BUDGET_VALUE  Maximum allowed budget value
*
*******************************************************************************
*/
class Aux
{
private:
	// 1. Non-static (instance) Variable Declarations
	double auxBudget;

public:
	// 1. Class Default Constructor
	Aux() : auxBudget(0.0)
	{ }

	// 2. Class Mutator Methods
	//    A. Method: addAuxBudget(double)
	//    Sets a Class object's, non-static, instance budget value to a
	//    validated budget value
	void setAuxBudget(double);
	//    B. Method: addAuxBudget(double)
	//       Adds a validated budget value to a Class object's, non-static,
	//       instance budget value
	void addAuxBudget(double);

	// 3. Class Observer Methods
	//    A. Method: getAuxBudget()
	double getAuxBudget() const { return auxBudget; }

	// 4. Class "static const" Value Declarations
	//    Note: Initialization occurs in the external, Class source code file.
	static const double MIN_BUDGET_VALUE;
	static const double MAX_BUDGET_VALUE;
};