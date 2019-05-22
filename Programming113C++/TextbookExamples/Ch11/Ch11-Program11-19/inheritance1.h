#pragma once

// External Definition files
#include <string>
#include <iostream>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program

// Enumerations
// ------------
// 1. College Discipline Categories
enum Discipline
{
	ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE
};
//
// 2. Student's Classification (Year in college)
enum Classification
{
	FRESHMAN, SOPHOMORE, JUNIOR, SENIOR
};


// Class Definitions
//------------------
//
/******************************************************************************
*      Class: Person
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/09/2015  Initial Release
*
* Class Description
* -----------------
* This Class is serves as the Base Class for two separate Classes, "Student"
* and "Faculty: that both contain the functionalty and data of this Class; i.e.
* both those classes exhibit an "is a" relationship with this class.
*
* In this version, the Class data member is declared as a "proected" member of
* the Class. This allows any derived, "Child" class of this class to directly
* access the data member. Of course, the Client of this class can NOT access
* the data member.
*
*
* ----------------------------- Public Interface ------------------------------
*       Method                               Description
* ------------------  ---------------------------------------------------------
* Person              Default Constructor: Set name to "empty"
* Person              Initializing and Conversion Constructor: Set person's name
* setName             Set/change the "Person" object's name
* getName             RETurns the "Person" object's name
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type   Name                    Description
* ----------  ------  ----  ---------------------------------------------------
* non-static  string  name  Person's name
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
class Person
{
protected:
	// 1. Non-static (instance) Variable Declarations
	string name;

public:
	Person()
	{
		name = "No Name";

		cout << "  Class \"Person\" Default Constructor invoked\n"
			 << "    \"name\": " << name << endl;
	}

	Person(string pName)
	{
		cout << "  Class \"Person\" Initializing Constructor invoked: "
			 << pName << endl;
		name = pName;
	}

	string getName() const
	{
		cout << "  Class \"Person\" method \"getName\" invoked" << endl;

		return name;
	}
};


/******************************************************************************
*      Class: Student
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/09/2015  Initial Release
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
	Person *getAdvisor() const
	{
		return advisor;
	}
	//    C. getMajor()
	//       RETurns object's Name
	//       Note: Overrides the Base Class Method
	string getName() const;
};


/******************************************************************************
*      Class: Faculty
* Base Class: Person
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/09/2015  Initial Release
*
* Class Description
* -----------------
* This Class inherits from the Base Class, "Person". It thus contains all the
* functionality of that Class; i.e. it "contains" the public methods of that
* Class. The non-static data members of Class "Person" are declared "protected";
* therefore, member methods of this, the inherited or "child" Class do have
* access to them.
*
*
* ----------------------------- Public Interface ------------------------------
*     Method                               Description
* --------------  -------------------------------------------------------------
* Faculty         Initializing Constructor: Set name, major, and advisor
* getDepartment   RETurns the "Faculty" object's Department (enum value)
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
*    Type        Type            Name                  Description
* ----------  ----------  ----------  -----------------------------------------
* non-static  Discipline  department   Faculty member's department (enum value)
*
*
* --------------------------- Public Data Members -----------------------------
*                         *** No public data members ***
*
*******************************************************************************
*/
class Faculty : public Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	Discipline department;

public:
	// 1. Constructors
	//    A. Initializing Constructor
	Faculty(string fname, Discipline d);

	//
	// 2. Observer methods
	//    A. getDepartment()
	//       RETurns object's department, a college discipline
	Discipline getDepartment() const
	{
		return department;
	}
};