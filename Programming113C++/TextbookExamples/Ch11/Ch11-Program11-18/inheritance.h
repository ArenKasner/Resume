#pragma once

// External Definition files
#include <string>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program

// Enumerations
// ------------
// 1. College Discipline Categories
enum Discipline
{ ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
//
// 2. Student's Classification (Year in college)
enum Classification
{ FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };


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
private:
	// 1. Non-static (instance) Variable Declarations
	string name;

public:
	Person()
	{ 
		cout << "   Class \"Person\" Default Constructor invoked" << endl;
		setName("No Name");
	}

	Person(string pName)
	{
		cout << "   Class \"Person\" Initializing Constructor invoked: "
			 << pName << endl;
		setName(pName);
	}

	void setName(string pName)
	{
		cout << "   Class \"Person\" method \"setName\" invoked: ";
		if (&pName != NULL)
		{
			cout << pName << endl;
			name = pName;
		}
		else
			cout << "No name supplied!" << endl;
	}

	string getName() const
	{
		cout << "   Class \"Person\" method \"getName\" invoked" << endl;

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
* This Class inherits from the Base Class, "Student". It thus contains all the
* functionality of that Class; i.e. it "contains" the public methods of that
* Class. The non-static data members of Class "Person" are declared "private";
* therefore, member methods of this, the inherited or "child" Class does not
* have access to them.
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
*       Method                               Description
* ------------------  ---------------------------------------------------------
* Student             Default Constructor: Set name to "empty"
* setMajor            Set/change the "Student" object's Major
* getMajor            RETurns the "Student" object's Major
* setAdvisor          Set/change the "Student" object's Advisor, a pointer
* getAdvisor          RETurns the "Student" object's Advisor's name
* setClassification   Set/change the "Student" object's year in college
* getClassification   RETurns the "Student" object's year in college
* getName             Overridden "getName" method: Adds description preceding
*                     student's name obtained from the Base Class, "getName"
*                     method.
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
* non-static  Classification  collegeYear   Student's year in college
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
	Classification collegeYear;
	Person* advisor;

public:
	// 1. Constructors
	//    A. Default Constructor
	Student()
	{	// Nothing to do but disply a message that the Constructor has been invoked
		cout << "   Class \"Student\" Default Constructor invoked" << endl;
	}
	//
	// 2. Mutator Methods
	//    A. setMajor(Discipline)
	//       Sets/changes student's Major, an enumerated college discipline
	void setMajor(Discipline d)
	{
		cout << "   Class \"Student\" method \"setMajor\" invoked" << endl;
		major = d;
	}
	//    B. setAdvisor(Person*)
	//       Sets/changes student's faculty member Advisor
	//       Note: This a a pointer, and thus the object to which it refers is
	//             an example of Composition; this Class does NOT control the
	//             lifetime of the object.
	void setAdvisor(Person* p)
	{
		cout << "   Class \"Student\" method \"setAdvisor\" invoked" << endl;
		if (p != NULL)
			advisor = p;
	}
	//    C. setAdvisor(Person*)
	//       Sets/changes student's Classification, a school year, an enumerated value
	void setClassification(Classification c)
	{
		cout << "   Class \"Student\" method \"setClassification\" invoked" << endl;
		collegeYear = c;
	}
	//
	// 3. Observer methods
	//    A. getMajor()
	//       RETurns the student's Major, an enumerated value
	Discipline getMajor() const
	{
		cout << "   Class \"Student\" method \"getMajor\" invoked" << endl;
		return major;
	}
	//    B. getAdvisor()
	//       RETurns a Pointer to the student's Faculty member, as a "Person" object
	Person* getAdvisor() const
	{
		cout << "   Class \"Student\" method \"getAdvisor\" invoked" << endl;
		return advisor;
	}
	//    C. getClassification()
	//       RETurns the student's year in college, an enumerated value
	Classification getClassification()
	{
		cout << "   Class \"Student\" method \"getClassification\" invoked" << endl;
		return collegeYear;
	}
	//    D. getName()
	//       RETurns the student's name, a "string" value
	//       Note: This method overriddes the Base Class method, providing a text
	//             description before displaying the student's name obtained by
	//             invoking the Base Class member method of the same name.
	string getName()
	{
		cout << "   Class \"Student\" method \"getName\" invoked" << endl;
		return "The student's name is " + Person::getName();
	}
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
* This Class inherits from the Base Class, "Student". It thus contains all the
* functionality of that Class; i.e. it "contains" the public methods of that
* Class. The non-static data members of Class "Person" are declared "private";
* therefore, member methods of this, the inherited or "child" Class does not
* have access to them.
*
* This class adds the feature of a department associated with a "Person"
* object, in this case the "Child" object represents a college faculty member.
*
* ----------------------------- Public Interface ------------------------------
*     Method                               Description
* --------------  -------------------------------------------------------------
* Faculty         Default Constructor: Dsiplay message - Constructor invoked
* setDepartment   Set/change the "Faculty" object's department
* getDepartment   RETurns the "Faculty" object's department
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
class Faculty : public Person
{
private:
	// 1. Non-static (instance) Variable Declarations
	Discipline department;

public:
	// 1. Constructors
	//    A. Default Constructor
	Faculty()
	{	// Nothing to do but display a message that the Constructor has been invoked
		cout << "   Class \"Faculty\" Default Constructor invoked" << endl;
	}
	//
	// 2. Mutator Methods
	//    A. setDepartment(Discipline)
	//       Sets/changes object's department, a college discipline
	void setDepartment(Discipline d)
	{
		cout << "   Class \"Faculty\" method \"setDepartment\" invoked" << endl;
		department = d;
	}
	//
	// 3. Observer methods
	//    A. getDepartment()
	//       RETurns object's department, a college discipline
	Discipline getDepartment() const   // Note: Supporting "const" objects
	{
		cout << "   Class \"Faculty\" method \"getDepartment\" invoked" << endl;
		return department;
	}
};



