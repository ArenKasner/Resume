#pragma once

// External Definition files
#include <iostream>
#include <cstring>  // For string library functions

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
                      // "std" are utilized in this program


/*******************************************************************************
*      Class: MyString
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     04/26/2015  Initial Release
*
* Class Description
* -----------------
* This class simulates many of the most common methods (features) of the C++ "
* string" class. Three Constructors are provided, 1) Default Constructor, which
* creates an "empty", C-Style array (1 characcter, NULL), 2) A Conversion
* Constructor that accepts a C-String array (pointer to), and 3) The class
* Copy Constructor.
*
* In addition, the two versions of the Assignment Operator are included. These
* Operators along with the Copy Constructor MUST be included, since the
* "MyString" contains a "char" pointer, which is dynamically allocated, thus
* requiring a "deep" copy of the an object's C-String array to another object's
* array when a copy of one object is used to create a new object and when
* assignement of one class object to another class object is required by the
* Client code.
*
* Also added to the class are three versions of the overloaded Addition (+)
* Operator, two of which are class member methods, as the left Operand is a
* "MyString" object, while the third is a "friend" Operator method, as the
* left Operand is a C-String array pointer and the right Operand is a
* "MyString" object. The "friend" version constructs a "MyString" object as
* its RETurn value in order to support 
* One of the two member Operator methods takes another "MyString" object as its
* right Operand, while the second version takes a C-String array pointer as its
* right Operand. These two member methods also RETurn a copy of the left
* Operand "MyString" object in order to support concatention chaining in an
* expression.
*
* Finally, all of the Relational Operators are overloaded for "MyString"
* objects. They utilize the C-String method "strcmp" to determine the outcome,
* since the underlying data member for thr "MyString" class is a C-String array.
*
*
* ----------------------------- Public Interface -------------------------------
*    Method                               Description
* ------------  ----------------------------------------------------------------
* MyString      Default Constructor: "makes" an "empty" string (1 element: NULL)
* MyString      Conversion Constructor: const char* ---> MyString object
* MyString      Copy Constructor
* ~MyString     Class Destructor
* length        RETurns the length (# characters) in the "MyString" object
* operator=     Assignment Operator
* operator+     Concatenates a lteral C-String to "this" "MyString" object
* operator+     Concatenates a "MyString" object to a lteral C-String
*               (Creates/RETurns a concatenated "MyString" object)
* operator+     Concatenates a "MyString" object to "this", "MyString" object
* operator+=    Shortcut Assignment Operator: + (Concatenation)
* operator==    Equality Relational Operator
* operator!=    NOT Equal Relational Operator
* operator>     Greater Than Relational Operator
* operator<     Less Than Relational Operator
* operator>=    Greater Than OR Eqaul To Relational Operator
* operator<=    Less Than OR Eqaul To Relational Operator
* operator<<    Stream Insertion Operator
* operator>>    Stream Extracton Operator
* operator+     Concatenates a "MyString" object to a "C-String" object
*
*
* --------------------------------- Private Methods ----------------------------
*   Name                              Description
* ----------- ------------------------------------------------------------------
* copy        Copies contents of a "C-String" array to "this" "MyString" array
* copy        Copies one "MyString" object's array to "this" object's array
* concatenate Concatenates a MyString" object's array to "this" object's array
*
*
* -------------------------- Private Data Members ------------------------------
*              Data
*    Type      Type   Name                    Description
* ----------  ------  ----  ----------------------------------------------------
* non-static  char*   str   Pointer to underlying C-String array
* non-static  int     len   Number of "char"s in the array, excluding "NULL"   
*
*
* --------------------------- Public Data Members ------------------------------
*         Data
*  Type   Type    Name                    Description
* ------  ----  --------  ------------------------------------------------------
* static  int   MAX_SIZE  Buffer size for stream Extraction: Max "char"s allowed
*
********************************************************************************
*/

class MyString
{
private:
	char* str;  // Pointer to underlying C-String array
	int len;    // Number of characters stored in the array (excludes "NULL")

	// Helper Methods
	int copy(const char* C_String);
	int copy(const MyString& source);
	int MyString::concatenate(const MyString& other);

public:
	// Constructors
	MyString();
	MyString(const char* C_String);
	MyString(const MyString& other);

	// Class Destructor
	~MyString();

	// Observer Methods
	int length() const
	{
		return len;
	}

	// Member Overloaded Operators
	MyString operator=(MyString);     // Assignment
	MyString operator+(MyString);     // Addition (Concatenation)
	MyString operator+(const char*);  // Addition (Concatenation)
	MyString operator+=(MyString);    // Shortcut Assignment: + (Concatenation)

	// Overloaded, "friend" operators
	friend bool operator==(MyString, MyString);  // Equality
	friend bool operator!=(MyString, MyString);  // Inequality
	friend bool operator>(MyString, MyString);   // Greater Than
	friend bool operator<(MyString, MyString);   // Less Than
	friend bool operator>=(MyString, MyString);  // Greater Than OR Equal To
	friend bool operator<=(MyString, MyString);  // Less Than OR Equal To

	// Required "friend" Operators
	friend ostream& operator<<(ostream&, MyString);     // Stream Insertion
	friend istream& operator>>(istream&, MyString&);    // Stream Extraction
	friend MyString operator+(const char*, MyString);   // Addition (Concatenation)

	// Class "static const" Data Members
	static const int MAX_SIZE;  // Buffer size for stream Extraction

};

