#pragma once

/******************************************************************************
*       Template: VectorTemplateMethods.h       (Ex: Car)
*  Base Template: ** None **  Supply Base Template name if inheritance applies
*
* This file defines the members of the Template: VectorTemplateMethods
* These members include Template variable data members, Template constant, static
* data members, and Template method declarations only and/or Template method
* declarations and definitions.
*
* Programmer: Aren Kasner
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     06/04/2015  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
* Template Description
* -----------------
* The template describes the vector methods in the client vector problem
* it accumilates the function and reverses and shifts the elements in the vector 
* ** Describe the Template defined here, including it's purpose  **
* ** This may take several lines to describe                  **
*
*
* ----------------------------- Public Interface ------------------------------
*      Method                               Description
* ----------------  -----------------------------------------------------------
*  accum			sums the vector
* rotateLeft		rotates vector values left in postion
* rotateRight		rotates vector values right in postion
* output			prints values of the vector
* reverse			reverses values of the vector
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
#include <vector>
#include <string>
class EmptyVectorException{ };
using namespace std;	 


	template <class T>
	 T accum(vector <T> vect)
	 {
		 if (vect.size()==0)
		 {
			 throw EmptyVectorException();
		 }
			 T init = T();

			 typename vector<T>::iterator iter = vect.begin();
			
			 while (iter != vect.end())
			 {

				 init = init + *iter;
				 ++iter;
			 }

			 return init;
		 
		 
			 
		 
	}
	template <class T>
	 void rotateRight(vector<T>& vect)
	 {
		 if (vect.size() == 0)
		 {
			 throw EmptyVectorException();
		 }
		 int end = vect.size();
			 for (int i = end-1; i>0; i--)
			 {
				 swap(vect[i], vect[i-1]);
			 }
		}
	  template <class T>
	 void rotateLeft(vector <T>& vect)
	{
		if (vect.size() == 0)
		{
			throw EmptyVectorException();
		}
			int end = vect.size();
			for (int i = 0; i < end - 1; i++)
			{
				swap(vect[i], vect[i+1]);
			}
			
		}

	 template <class T>
	void output(vector <T> vect)
	{
		
				typename vector<T>::iterator iter = vect.begin();
			while (iter != vect.end())
		{
				cout << *iter << " ";
				++iter;


			}
		}
		
	
	 template <class T>
	 void reverse(vector<T>& vect)
	 {
		 if (vect.size()==0)
		 {
			 throw EmptyVectorException();
		 }
			 int SIZE = vect.size();

			 for (int i = 0; i < SIZE - 1; i++)
			 {
				 swap(vect[i], vect[SIZE - i - 1]);
			 }
	 }
		 
	 

