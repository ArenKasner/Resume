/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Spring 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: **KasnerProject2**  (Ex: Project1)
 *             File Name: **KasnerPalindromeTest**.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Aren Kasner
 *
 * Assigned Project Number: Project2 **See Syllabus, for example: 2A**
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     04/19/2015  Initial Release
 *   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard		the user inputs a string into the program ** Describe any inputs from the User; otherwise, None **
 *			
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   computer outputs the word and shows computing the weather it is a 
			 palindrome or not.
 *
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
 * **** Add name and description of any other methods defined in this file ****
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <string>
#include <locale>

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program
class Pstring :public string
{

	
	char *ptr;
	int stringSize;
	void subError() const;//handles subscript out of range
	
public:
	Pstring(string value,int length);

	Pstring(const Pstring &obj);

	char &operator[](int) const;
//	bool operator==(char) const; not working yet
};

Pstring::Pstring(string value,int length) //makes array
{
	
	stringSize = length;
	ptr = new char[stringSize];
	for (int i = 0; i < length; i++)
	{
		/*if (ptr[i]<65)
		{
			i++;
		}
		else if (ptr[i]<90&&ptr[i]>64)
		{
			
		}
		else{*/ ptr[i] = value[i]; //}

	}
}
Pstring::Pstring(const Pstring &obj) //copy constructor flips word makes it 
									 //easier to work with
{

	stringSize = obj.size();
	ptr = new char[stringSize];
	for (int i = 0; i < stringSize; i++)
	{
		ptr[i] = obj.ptr[(stringSize-1)-i];
	}

}

void Pstring::subError() const
{
	cout << "ERROR: Subscript out of range";
}
char &Pstring::operator[](int sub) const
{
	if (sub<0||sub>=stringSize)
	{
		subError();
	}
	return ptr[sub];
}
//
//bool Pstring::operator==(char valueA)  //const not working yet
//{	
//	const static int lowerMin = 97;
//	const static int lowerMax = 122;
//	const static int upperMin = 65;
//	const static int upperMax = 90;
//	if (valueA)
//	{
//
//	}
//}
//prototype
bool isPalindrome(string,int);
/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* The Program welcomes the user and then asks for a string to check if it is a 
* palindrome. Then the program computes and displays weather the word is a
* palindrome or not.
* Method: isPalindrome()
* The method creates two Pstring objects and then compares them. It does this
* by displaying the words and then returning false as soon as they are not
* and true after it has finished if they are.
* Method Description
* ------------------
* ** For method main(), describe the application program from the client's
* ** perspective, which includes any User inputs required and expected
* ** Console output, and any other pertinent information about the program.
* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*
* Pre-Conditions
* --------------
* An assumption is made that a string is entered
* ** Describe any assumptions made by the method; otherwise specify: None **
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
* bool       isPalindrome  checks weather the word is a palindrome or not
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* isPalindrome()	the method checks if it is a palindrome or not.
*******************************************************************************
*/
 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;

	 
	// !! Insert your code here (remove this comment line) !!
	 string possiblePalindrome;
	 int length;
	 bool goodWord;
	 cout << "welcome to the palindrome tester." << endl;
	 cout << "Please enter a palindrome" << endl;
	 getline(cin, possiblePalindrome);
	 cout << "\n\n" << possiblePalindrome <<"\n"<< endl;
	 
	 length = possiblePalindrome.size(); //gets for loop lengths
	 
	 goodWord = isPalindrome(possiblePalindrome,length);
	
	 if (goodWord == true)
	 {
		 cout << "\nThe word "<<possiblePalindrome<<" is a palindrome.";
	 }
	 else
	 {
		 cout << "\nThe word " << possiblePalindrome << " is NOT a palindrome. sorry";

	 }
	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}
 bool isPalindrome(string value,int length)
 {
	 Pstring front(value,length);
	 Pstring back(front);
	 for (int i = 0; i < length; i++)
	 {
		 
		 if (front[i] == back[i])//checking equality
		 {
			 cout << front[i] << " Equals " << back[i] << endl;
		 }
		 else
		 {
			 cout << front[i] << " Does Not Equal " << back[i] << endl;
			 return false; //breaks loop and returns false
		 }
	 }
	 return true; //returns true if letters all equal
 }
