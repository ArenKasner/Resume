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
*
* File Description
* ----------------
* This file contains the external class method definitions and the initialization
* of any constant, "const" values declared at Class scope.
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* Rectangle        Constructor: Length and Width of the object
* output           Displays the Length and Width of the object
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                            *** No private methods ***
*
*
* ----------------------- Data Member Initializations -------------------------
*               Data
*    Type       Type       Name                    Description
* ----------  --------  ----------  -------------------------------------------
*                         *** No Initializations ***
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"
#include "Rectangle.h"  // For Class Definition: Rectangle
#include <iostream>
using namespace std;


// External Class Method Definitions
// 1. Method: Rectangle(double,double)
//    Initializes object's data members with validated values; 0.0, otherwise
Rectangle::Rectangle(double width, double length) : width(0), length(0)
{
	if (width > 0 && length > 0)
	{
		this->width = width;
		this->length = length;
	}
}
//
// 2. Method: output()
//    Dsiplays object's data members
void Rectangle::output() const
{
	cout << "Width is " << width << ", "
		 << "Length is " << length << endl;
}
