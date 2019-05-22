/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Speing 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: KasnerProject1  (Ex: Project1)
 *             File Name: **MovieSurvey**.cpp       (Ex: payrate.cpp)
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Aren Kasner
 *
 * Assigned Project Number: Project1
 *
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     04/12/2015  Initial Release
 *   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
 *
 *
 * Program Inputs
 * --------------
 *  Device                              Description
 * --------  ------------------------------------------------------------------
 * Keyboard  ** Describe any inputs from the User; otherwise, None **
 *	user inputs in the amount of data then
 *
 * Program Outputs
 * ---------------
 *  Device                            Description
 * --------  ------------------------------------------------------------------
 * Monitor   ** Describe any Console display; otherwise, None **
 *
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
 * studentSurvey collects input then displays and sorts them
 * mathAvg		 finds the averge of the array
 * mathMed		 finds the median value of the array
 * mathMode		 finds the mode of the array
 * **** Add name and description of any other methods defined in this file ****
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program
//prototypes
void studentSurveyed(int[],int&);
double mathMed(int[],int&);
double mathAvg(int[],int&);
double mathMode(int[],int&);
/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
the program asks for the user to choose how many students are taking the survey
then asks for how many movies each student watched. Then the program displays what the 
user entered then sorts the array and displays the average, median, and the mode.
* Method: studentSurveyed() 
* Method Description
* ------------------
* this method is not seen by the user but it takes input from the user about how many
* movies the student has watched then sorts the array after displaying them.
* Method: mathAvg()
* Method Description
* ------------------
* this method is not seen by the user but it takes input from the user about how many
* movies the student has watched then sorts the array after displaying them.
* Method: mathMed()
* Method Description
* ------------------
* this method is not seen by the user but it takes input from the user about how many
* movies the student has watched then sorts the array after displaying them.
* Method: mathMode()
* Method Description
* ------------------
* this method is not seen by the user but it takes input from the user about how many
* movies the student has watched then sorts the array after displaying them.

* ** For other methods, describe the functionality of the method.
* ** This WILL take several lines for a satisfactory description!
*	the student
* Pre-Conditions
* --------------
* ** Describe any assumptions made by the method; otherwise specify: None **
*	there is an assumption that the values will be positive integers from three to ten
*	for the number of surveyed students and that the number of movies will be added will
*	be non negitive integers
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
* double	returns mode median and average
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  --------------------------------------------------------------
studentSurveyed	this function creates inputs the movies watched and sorts them
mathMed			finds the median of the array
mathAvg			finds the average of the array
mathMode		finds the mode of the array
*******************************************************************************
*/



 int main()          
{
	 // Constant "const" Vlaue Declarations
	 const int NO_ERRORS = 0;
	int students; // number of student varible
	int * studentValues; //pointer to student values
	int min = 3, max = 10;//min and max values for number of students
	double Average, Median, Mode; //Average Median Mode declarations
	bool goodValue = false; //value checker bool
	
	do
	{
	
cout << "Please enter the amount of people surveyed." << endl;
	 cin >> students;

	 if (students >= min && students <= max)
	 {
		 goodValue = true;
	 }
	 else
	 {
		 goodValue = false;
	 }
	} while (goodValue == false);

	
	studentValues = new int[students];//creates dynamic array
	studentSurveyed(studentValues,students);
	Average = mathAvg(studentValues, students);
	Median = mathMed(studentValues, students);
	Mode = mathMode(studentValues, students);
	cout << endl;

	cout << "\n The Average value is " << Average << endl;
	cout << "\n The Meadian value is " << Median << endl;
	cout << "\n The Mode value is " << Mode << endl;

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return NO_ERRORS;
}

 void studentSurveyed(int * studentArray,int &survey)
 {
	 int enteredValue;
	 int i, j, k,temp,flag = 1;
	 for (i = 0; i < survey; i++)
	 {
		
		 do
		 {
 cout << "Please enter the number of movies that student " << (i + 1) << " watched." << endl;
		 cin >> enteredValue;
		 } while (enteredValue <= -1);
		 *(studentArray + i) = enteredValue;
	 }

	 cout << "\nStudent:\t  ";
	 for (int i = 0; i < survey; i++)
	 {
		 cout << (i + 1) << " ";
	 }
	 cout << "\nNumber of Movies: ";
	 for (int i = 0; i < survey; i++)
	 {
		 cout << *(studentArray + i) << " ";
	 }

	 for ( j = 0; (j < survey)&&flag; j++)
	 {
		 flag = 0;

		 for ( k = 0; k < (survey-1); k++)
		 {
			 if (*(studentArray+k+1) > *(studentArray+k))
			 {
				 temp = *(studentArray+k);
				 *(studentArray+k) = *(studentArray+k + 1);
				 *(studentArray+k + 1) = temp;
				 flag = 1;
			 }
		 }
	 }
	 
 }
 double mathMed(int * studentArray, int &survey)
 {

	 int middle;
	 double median;
	 middle = survey / 2;


	 if (survey%2==0)
	 {
		 median = (*(studentArray + middle) + *(studentArray + (middle + 1)))/2;
	 }
	 else
	 {
		 median = *(studentArray+ (middle+1));
		 
	 }
	 return median;
	 
 }
 double mathAvg(int * studentArray, int &survey)
 {
	 int total = 0;
	 double Average;
	 for (int i = 0; i < survey; i++)
	 {
		 total += *(studentArray + i);
	 }
	 Average = total / survey;
		 return Average;
 }
 double mathMode(int * studentArray, int &survey)
 {
	 
	 int* Repetition = new int[survey];
	 int mode;
	 // alocate a new array in memory of the same size 
	 for (int i = 0; i < survey; i++) {
		 *(Repetition+i) = 0;//initialize each element to 0
		 int j = 0;
		 while ((j < i) && (*(studentArray+i) != *(studentArray+j))) {
			 if (*(studentArray+i) != *(studentArray+j)) {
				 j++;
			 }
		 }
		 (*(Repetition+j))++;
	 }
	 int iMaxRepeat = 0;
	 for (int i = 1; i < survey; i++) {
		 if (Repetition[i] > Repetition[iMaxRepeat]) {
			 iMaxRepeat = i;
		 }
	 }

	 mode = *(studentArray + iMaxRepeat);
	 delete[] Repetition;
	 return mode;
 }