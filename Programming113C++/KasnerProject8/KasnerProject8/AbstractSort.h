#pragma once

/******************************************************************************
*       Class: AbstractSort       (Ex: Car)
*  Base Class: ** None **  Supply Base Class name if inheritance applies
*
* This file defines the members of the class: AbstractSort
* These members include class variable data members, class constant, static
* data members, and class method declarations only and/or class method
* declarations and definitions.
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     05/31/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
* Class Description
* -----------------
* This is a virtual class that discribes the Abstract sort call and the 
* count method that both functions use to count.
* ** Describe the class defined here, including it's purpose  **
* ** This may take several lines to describe                  **
*
*
* ----------------------------- Public Interface ------------------------------
*      Method                               Description
* ----------------  -----------------------------------------------------------
*	counter();		counts and saves the value and is accessible in the derived
*					class.
*
* ------------------------------ Private Methods ------------------------------
*       Name                               Description
* ----------------  -----------------------------------------------------------
*                           *** No private methods ***
*
*
* --------------------------- Private Data Members ----------------------------
*               Data
*    Type       Type       Name                    Description
* ---------- --------- ------------ -------------------------------------------
* ***Type: static, non-static***
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



class AbstractSort
{
private:
	// 1. Non-static (instance) Variable Declarations
	
	// 2. Static Constant Value Declarations

public:
	int count;
	// 1. Constructors
	//    A. Default Constructor
	virtual void sort(int arr[], int size) = 0;
	void counter();
	AbstractSort();
	//    B. Initializing Constructors
	//    C. Conversion Constructors
	
	// 2. Class Destructor
	~AbstractSort();

	// 3. Mutator Methods

	// 4. Observer Methods

	// 5. Overloaded Operators

	// 6. Type Conversion Operators

	// 7. Granted "friend" Method Declarations

	// 8. Public "static const" Value Declarations

};

