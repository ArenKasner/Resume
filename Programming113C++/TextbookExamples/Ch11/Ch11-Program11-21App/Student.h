#pragma once

/******************************************************************************
*      Class: Student
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/10/2015  Initial Release
*
* Class Description
* -----------------
* This Class inherits from the Base Class, "Person". It thus contains all the
* functionality of that Class; i.e. it "contains" the public methods of that
* Class. The non-static data members of Class "Person" are declared "protected";
* therefore, member methods of this, the inherited or "child" Class do have
* access to them.
*
* This "child" Class may override a method of the Base Class; i.e. it may
* contain a method with the same signature as that in the Base Class. In
* addition, an overridden method in the "child" Class may invoke the Base Class
* method with the same signature by scoping the invocation with the Base Class
* name.
*
* An object of this "child" Class may invoke a Base Class method as if it was
* defined in the "child" Class. If the method is not overridden in the "child"
* Class, the compiler will implicitly look for it in the Base Class.
*
*
* ----------------------------- Public Interface ------------------------------
*    Method                               Description
* ------------  ---------------------------------------------------------------
* Student       Initializing Constructor: Set name, major, and advisor
* getMajor      RETurns the "Student" object's Major
* getAdvisor    RETurns the "Student" object's Advisor's name
* getName       Overridden "getName" method: Adds description preceding the
*               student's name, obtained from the Base Class, "getName" method.
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*                Data
*    Type        Type             Name                  Description
* ----------  --------------  ------------  -----------------------------------
* non-static  Discipline      major         Student's major
* non-static  Person*         advisor       Pointer to student's Advisor object
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
// External Definition files
#include "Person.h"
#include "CollegeEnumsDescriptions.h"


class Student : public Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	Discipline major;
	Person* advisor;

public:
	// 1. Constructors
	//    A. Initializing Constructor
	Student(string sname, Discipline d, Person *adv);
	//
	// 2. Observer methods
	//    A. getMajor()
	//       RETurns object's Major, a college discipline
	Discipline getMajor() const
	{
		return major;
	}
	//    B. getMajor()
	//       RETurns object's Advisor, a pointer to a "Person" object
	Person* getAdvisor() const
	{
		return advisor;
	}
	//    C. getMajor()
	//       RETurns object's Name
	//       Note: Overrides the Base Class Method
	string getName() const;
};
