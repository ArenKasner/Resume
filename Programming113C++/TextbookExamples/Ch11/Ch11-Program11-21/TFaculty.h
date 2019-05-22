#pragma once

/******************************************************************************
*      Class: TFaculty
* Base Class: Faculty
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/12/2015  Initial Release
*
* Class Description
* -----------------
* This Class inherits from the Base Class "Faculty", which itself inherits from
* the "Person" Base Class. This class add a "title" feature to the "Faculty"
* Class. In addition, it provides an overridden, Base Class "Person"  method,
* "getName" to RETurn a "string" that includes the faculty member's title to
* that or the member's name, which is obtained by explicitly invoking the Base
* Class method.
*
*
* ----------------------------- Public Interface ------------------------------
*  Method                               Description
* --------  -------------------------------------------------------------------
* TFaculty  Initializing Constructor
* getName   Overrides the Base Class method to prefix the name with a title
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* --------- -------------------------------------------------------------------
* setTitle  Validates/sets the object's "title" data member
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
// External Definition files
#include <string>
#include "Faculty.h"

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


class TFaculty: public Faculty
{
private:
	// 1. Non-static (instance) Variable Declarations
	string title;
	//
	// 2. Private "Helper" Methods
	//    A. setTitle
	//       Set's the Faculty object's title
	void setTitle(string title);

public:
	// 1. Constructors
	//    A. Initializing/Conversion Constructor
	TFaculty(string fname, Discipline d, string title);
	//
	// 2. Observer Methods
	//    A. getName
	//       Overrides (and utilizes) the Base Class, "Person" method
	string getName() const;
};


    

