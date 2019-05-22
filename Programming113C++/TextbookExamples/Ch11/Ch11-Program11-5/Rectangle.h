#pragma once

/******************************************************************************
*      Class: Rectangle
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     03/31/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate the various requirements of
* Class methods when the class has non-static pointer data members that are
* assigned memory addresses of dynamically allocated memory for Class objects
* or arrays.
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* Rectangle        Constructor: Length and Width of the object
* setValue         Sets all array elements to specified value
* getWidth         RETurns the Width of the object
* getLength        RETurns the Length of the object
* output           Displays the Length and Width of the object
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                             *** No private methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*              Data
*    Type      Type     Name                    Description
* ----------  ------  --------  -----------------------------------------------
* non-static  double  width     Width of the "Rectangle" object
* non-static  double  length    Length of the "Rectangle" object
*
*******************************************************************************
*/
class Rectangle
{
private:
	// 1. Non-static (instance) Variable Declarations
	double width;
	double length;

public:
	// 1. Class Initializing Constructor
	Rectangle(double width, double length);
	//
	// 2. Class Observer Methods
	//    A. Method: getWidth()
	double getWidth() const
	{ return width; }
	//    B. Method: getLength()
	double getLength() const { return length; }
	//    C. Method: output()
	void output() const;
};