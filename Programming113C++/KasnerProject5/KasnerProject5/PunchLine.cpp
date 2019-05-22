/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Spring 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: Solution-Project5
 *             File Name: PunchLine.cpp
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 *       Programmer: Aren Kasner
 * Assigned Project: 5
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     MM/DD/2014  Initial Release
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ---------------  -----------------------------------------------------------
 * main             Program entry point method
 * displayAllLines  Display all lines in the joke file
 * displayLastLine  Display the last line (punch line) in the punchline file
 * 
 *
 * Classes Utilized
 * ----------------
 *      Name                             Description
 * ---------------  -----------------------------------------------------------
 * None
 *
 * Program Inputs
 * --------------
 *    Data Type                             Description
 * ---------------  -----------------------------------------------------------
 * None
 *
 * Program Outputs
 * ---------------
 *    Data Type                             Description
 * ---------------  -----------------------------------------------------------
 * 
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <string>    // Defines Class: string
#include <iostream>  // Defines objects and classes used for stream I/O
#include <fstream>   // Defines Classes: ifstream and ofstream

// Namespaces utilized in this program

using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program
int displayAllLines(ifstream& punchLineFile);

int displayLastLine(ifstream& jokeFile);
/******************************************************************************
 * Method: main()
 * 
 * Method Description
 * ------------------
 * 
 *
 * Method Arguments
 * ----------------
 *   Type        Name                        Description
 * --------  -------------  ------------------------------------------------
 * None
 * 
 * Return Value
 * ------------
 *   Type                              Description
 * --------  ---------------------------------------------------------------
 * void
 *
 ***************************************************************************
 */
 int main()          
{
	// Uninitialized Variable Declarations
	// 1.Names of files, and file stream objects
	string fileName1, fileName2;
	// 2. File objects
	ifstream jokeFile, punchlineFile;

	
	// Desribe the assigned project to the User
	cout << "               PROG-113: Project #5\n"
		 << "This program will print a joke and its punch line.\n\n";

   
	// Open the files
	// 1. The joke file
	// Get the file names from the user
	cout << "Enter the name of the joke file (ex. joke.txt): ";
	cin  >> fileName1;
	jokeFile.open(fileName1.data());  
	if (!jokeFile)
	{
		cout << "  The file " << fileName1 << " could not be opened." << endl;
	}

	else
	{	// 2. the punchline file
		cout << "Enter name of punch line file (ex. punchline.txt): ";
		cin  >> fileName2;
		punchlineFile.open(fileName2.data());  
		if (!punchlineFile)
		{
			cout << "  The file " << fileName2 << " could not be opened." << endl;
			jokeFile.close();
		}

		else
		{	// Both files were successfully opened for reading...
			cout << endl << endl; 
			// Call method to display contents of the joke file
			displayAllLines(jokeFile);
   
			// Call method to display the last line in the punch line file
			displayLastLine(punchlineFile); 
			cout << endl;

			// Finally, close the files
			jokeFile.close();
			punchlineFile.close();
		}
	}


	// This prevents the Console Window from closing during debug mode
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return 0;
}


 int displayAllLines(ifstream& jokeFile)
 {
	 if (jokeFile.peek() == 'O')
	 {
		 char ch = jokeFile.get();
		 while (ch != EOF)
		 {
			 cout << ch;
			 ch = jokeFile.get();
		 }
	 }
	 else
	 {
		 string value;
		 while (jokeFile.peek() != 'Q')
		 {
			 jokeFile.get();
		 }
		 getline(jokeFile, value, '\n');
		 cout << value << endl;
	 }
	return 0;
}

int displayLastLine(ifstream& punchLineFile)
{

	string value;
		char ch ='0';

	if (punchLineFile.peek()=='a')
	{
		while (punchLineFile.peek() != '.')
		{

			punchLineFile.get();

		}
		punchLineFile.get();
		punchLineFile.get();
		
	}
	else
	{
			while (punchLineFile.peek() != 'A')
		{	
			
			punchLineFile.get();

		}
		
	}
	getline(punchLineFile, value);
		cout << value << endl;
	
		return 0;
}
