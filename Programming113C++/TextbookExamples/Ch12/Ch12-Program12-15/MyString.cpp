/******************************************************************************
*      Class: MyString
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/26/2015  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*   Methods                          Description
* -----------  ----------------------------------------------------------------
* MyString     Default Constructor
* MyString     Conversion Constructor: const char* ---> MyString object
* MyString     Copy Constructor
* operator=    Assignment Operator
* operator+=   Shortcut Assignment Operator: + (Concatenation)
* operator==   Equality Relational Operator
* operator!=   NOT Equal Relational Operator
* operator>    Greater Than Relational Operator
* operator<    Less Than Relational Operator
* operator>=   Greater Than OR Eqaul To Relational Operator
* operator<=   Less Than OR Eqaul To Relational Operator
* operator<<   Stream Insertion Operator
* operator>>   Stream Extracton Operator
*
*
* --------------------------------- Private Methods ---------------------------
*   Name                              Description
* ----------- -----------------------------------------------------------------
* copy        Copies contents of a "C-String" array to "this" "MyString" array
* copy        Copies one "MyString" object's array to "this" object's array
* concatenate Concatenates a MyString" object's array to "this" object's array
*
*
* ----------------------- Data Member Initializations -------------------------
* Type      Name                           Description
* ----  ------------  ---------------------------------------------------------
* int   MAX_SIZE      Buffer size for stream Extraction: Max "char"s allowed
*
*******************************************************************************
*/

// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "MyString.h"


// Initialization of Class, "static const" Data Members
// 1. Buffer size for stream Extraction Operator
const int MyString::MAX_SIZE = 256;


//**************************************************
// Default Constructor                             *
//                                                 *
// 1. Creates a "char" array, size 1               *
// 2. Store "NULL" character in the single element *
// 3. Set length: 0                                *
//**************************************************
MyString::MyString() : str(NULL), len(0)
{
	// An empty "MyString" object must define an underlying
	// C-String array of 1 character to hold the required "NULL"
	// character to indicate an empty "Mystring" object.
	str = new char[1];
	// Then set the one and only element to the ASCII "NULL"
	// character code.
	str[0] = '\0';
}


//****************************************************
// Conversion Constructor (const char* --> MyString) *
//                                                   *
// 1. Creates a "char" array the size of the source  *
//    C-String                                       *
// 2. Copy the argument C-String characters to the   *
//    new C-String array for "this" new object       *
//                                                   *
// Precondition: array is "NULL" terminated          *
//****************************************************
MyString::MyString(const char* sptr)
{
	// Use the C-String method, "strlen" to determine the
	// number of characters in the source, C-String array
	len = strlen(sptr);

	// Create "this" object's C-String array to accommodate
	// the source, C-String array' contents, plus 1 for
	// the required C-String terminator character
	str = new char[len + 1];

	// Now copy the source C-String array contents into
	// "this" array.
	copy(sptr);
}


//*****************************************************
// Copy Constructor                                   *
//                                                    *
// 1. Creates a "char" array the size of the "right"  *
//    Operand's C-String array.                       *
// 2. Copy the "right" Operand's C-String contents    *
//    to the new C-String array for "this" new object *
//*****************************************************
MyString::MyString(const MyString& right)
{
	// Create "this" object's C-String to be the same length
	// as the C-String array in the "MyString" object being copied,
	// including room for the required "NULL" terminating character.
	str = new char[right.len + 1];
	// Use the "Helper" method to copy the contents of the object
	// being copied into "this" C-String array.
	len = copy(right);

}


//*****************************************************
// Class Destructor                                   *
//                                                    *
// Reliquishes dynamically allocated memory for the   *
// object's underlying, C-String array.               *
//*****************************************************
MyString::~MyString()
{
	// Deallocate the dynamically allocated memory for
	// the C-String array.
	delete[] str;
}



//************************************************
// Overloaded = Operator (Assignment)            *
//************************************************
MyString MyString::operator=(MyString right)
{
	// Note: There will be an array of at least size 1 defined
	// 1: Empty string, just the NULL terminator
	delete[] str;

	str = new char[right.len + 1];
	len = copy(right);

	return *this;
}


//*******************************************************************
// Overloaded + Operator  (Member Concatenate Operator)             *
//                                                                  *
// Creates a local copy of the left, "MyString" Operand and then    *
// concateneates the right, "MyString" object to to it.             *
//                                                                  *
// Returns a copy of the local, concatenated, "MyString" object.    *
//*******************************************************************
MyString MyString::operator+(MyString right)
{
	// Now create a new array, assigning its pointer
	// the object's "str" pointer
	char* newString = new char[len + right.len + 1];

	for (int index = 0; index < len; ++index)
	{
		*(newString + index) = *(str + index);
	}

	for (int index = 0; index < right.len; ++index)
	{
		*(newString + len + index) = *(right.str + index);
	}

	*(newString + len + right.len) = '\0';

	return MyString(newString);
}


//*******************************************************************
// Overloaded + Operator  (Member Concatenate Operator)             *
//                                                                  *
// Creates a local copy of the left, "MyString" Operand and then    *
// concateneates the right, "C-String" array contents to to it.     *
//                                                                  *
// Returns a copy of the local, concatenated, "MyString" object.    *
//*******************************************************************
MyString MyString::operator+(const char* right)
{
	int rightLength = strlen(right);

	char* newString = new char[len + rightLength + 1];

	for (int index = 0; index < len; ++index)
	{
		*(newString + index) = *(str + index);
	}

	for (int index = 0; index < rightLength; ++index)
	{
		*(newString + len + index) = *(right + index);
	}

	*(newString + len + rightLength) = '\0';

	return MyString(newString);
}


//*******************************************************************
// Overloaded += Operator  (Member Assignment/Concatenate Operator) *
//                                                                  *
// Concatenates the "str", C-String member of the right Operand to  *
// the "str" member of the calling (this) object.                   *
//                                                                  *
// Returns a copy of the concatenated, "this" object.               *
//*******************************************************************
MyString MyString::operator+=(MyString right)
{
	// Save a copy of the pointer to the "old" array
	char* temp = str;

	// Now create a new array, assigning its pointer
	// the object's "str" pointer
	str = new char[len + right.len + 1];

	// Set the new array to the contents of the
	// "old" array.
	len = copy(temp);

	// Now concatenate the right Operand's C-String
	// to the "new" C-String array
	len += concatenate(right);

	// Finally, "delete" the object's "old" C-String array
	delete[] temp;  // Note: array size is at least 1!

	// The Asignment Operator MUST RETurn a copy of
	// "this" object
	return *this;
}


//*********************************************************
// Overloaded == operator  (Equality)                     *
//*********************************************************
bool operator==(MyString left, MyString right)
{
	// Use the C-String method "strcmp" to determine
	// 0: left equals right
	return strcmp(left.str, right.str) == 0;
}


//*********************************************************
// Overloaded != operator.                                *
//*********************************************************
bool operator!=(MyString left, MyString right)
{
	return strcmp(left.str, right.str) != 0;

	// The following could also be used:
	//  	return !(left == right);
}


//********************************************************
// Overloaded > operator.                                *
//********************************************************
bool operator>(MyString left, MyString right)
{
	//   0: left equals right
	// < 0: left is less than right
	// < 0: left is greater than right
	return (strcmp(left.str, right.str) > 0);

	// The following could also be used:
	//  	return !(left <= right);
}


//***********************************************************
// Overloaded < operator.                                   *
//***********************************************************
bool operator<(MyString left, MyString right)
{
	//   0: left equals right
	// < 0: left is less than right
	// < 0: left is greater than right
	return (strcmp(left.str, right.str) < 0);

	// The following could also be used:
	//  	return !(left >= right);
}


//*****************************************************
// Overloaded >= operator.                            *
//*****************************************************
bool operator>=(MyString left, MyString right)
{
	return (strcmp(left.str, right.str) >= 0);
}


//**********************************************************
// Overloaded <= operator.                                 *
//**********************************************************
bool operator<=(MyString left, MyString right)
{
	return  (strcmp(left.str, right.str) <= 0);
}


//*************************************************
// Overloaded stream insertion operator (<<).     *
//*************************************************
ostream &operator<<(ostream& stream, MyString obj)
{
	// Class "ostream" inserts all "char" pointer characters
	// into the stream until a "NULL" character is found
	stream << obj.str;

	return stream;
}


//****************************************************
// Overloaded stream extraction operator (>>)        *
//                                                   *
// Note: This version reads all characters from the  *
//       stream until the "Enter" key OR the maximum *
//       allowed number of characters is reached.    *
//****************************************************
istream &operator>>(istream& stream, MyString& obj)
{
	// Read the C-String from the stream 
	char buffer[MyString::MAX_SIZE];
	stream.getline(buffer, MyString::MAX_SIZE);

	// 1. Invoke the Convert constructor (C-String to "MyString")
	// 2. Assign "temp" object to the right Operand
	//    using the overloaded assignment Operator
	obj = buffer;

	return stream;
}


//*******************************************************************
// Overloaded += Operator  (Member Assignment/Concatenate Operator) *
//                                                                  *
// Creates a local copy of the left, "MyString" Operand and then    *
// concateneates the right, "MyString" object to to it.             *
//                                                                  *
// Returns a copy of the local, concatenated, "MyString" object.    *
//*******************************************************************
MyString operator+(const char* left, MyString right)
{
	int leftLength = strlen(left);
	int rightLength = right.len;

	char* newString = new char[leftLength + rightLength + 1];

	for (int index = 0; index < leftLength; ++index)
	{
		*(newString + index) = *(left + index);
	}

	for (int index = 0; index < rightLength; ++index)
	{
		*(newString + leftLength + index) = *(right.str + index);
	}

	*(newString + leftLength + rightLength) = '\0';

	return MyString(newString);
}


//*****************************************************************
// Helper Method: copy(const char*)                               *
//                                                                *
// Copies the "char"s in the C-String array to "this" object's    *
// C-String array.                                                *
//                                                                *
// Pre-Condition:                                                 *
// "this" C-String array is large enough to accommodate all       *
// the elements in the argument's array plus the "NULL" character *
//                                                                *
// RETurns: Length of the C-String argument array                 *
//*****************************************************************
int MyString::copy(const char* C_String)
{
	int size = strlen(C_String);

	for (int i = 0; i < size; ++i)
		*(str + i) = *(C_String + i);
	*(str + size) = '\0';

	return size;

}


//*****************************************************************
// Helper Method: copy(const MyString&)                           *
//                                                                *
// Copies the "char"s in the "MyString" argument's C-String array *
// to "this" object's C-String array.                             *
//                                                                *
// Pre-Condition:                                                 *
// "this" C-String array is large enough to accommodate all       *
// the elements in the argument's C-String array, includng the    *
// "NULL" character.                                              *
//                                                                *
// RETurns: Length of "this" C-String argument array              *
//*****************************************************************
int MyString::copy(const MyString& source)
{
	int size = source.len;

	for (int i = 0; i < size; ++i)
		*(str + i) = *(source.str + i);
	*(str + size) = '\0';

	return size;

}


//*****************************************************************
// Helper Method: copy(const MyString&)                           *
//                                                                *
// Concatenates the "MyString" argument's C-String array to the   *
// end of "this" object's C-String array.                         *
//                                                                *
// Pre-Condition:                                                 *
// "this" C-String array is large enough to accommodate all of    *
// the additional elements in the argument's C-String array,      *
// includng the "NULL" character                                  *
//                                                                *
// RETurns: Length of "this" C-String argument array after the    *
// concatenation.                                                 *
//*****************************************************************
int MyString::concatenate(const MyString& other)
{
	int newSize = len + other.len;

	for (int i = 0; i < other.len; ++i)
		*(str + len + i) = *(other.str + i);

	*(str + newSize) = '\0';

	return newSize;
}
