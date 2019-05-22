#pragma once 

/******************************************************************************
*      Class: Length
* Base Class: None
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/02/2015  Initial Release
*
* Class Description
* -----------------
* This Class is an example class to demonstrate overloading various arithmetic
* and logical comparison Operators. The overloaded Operators are declared as
* "friend" methods, but may also be declared as instance methods, as the order
* in which the Operands are processed, i.e. left/right, is not important.
*
* The arguments of the overloaded Operators are declared as "Length" objects.
* This is done so that an expression such as:
*     Length one(3,4);
*     Length two = 2 + one;
* will compile ("2" is NOT a "Length" object!). To allow this, a Constructor
* that takes an "int" value is supplied. Thus, when the compiler encounters
* the addition statement above, it will be able to construct a "Length" object,
* which than then be passed to the overloaded Addition Operator as the "lValue".
*
*
* ----------------------------- Public Interface ------------------------------
*  Public Methods                          Description
* ---------------  ------------------------------------------------------------
* Length           Default Constructor: "lengthInches" set to 0.0
*
*
* --------------------------------- Private Methods ---------------------------
*      Name                              Description
* --------------- -------------------------------------------------------------
*                          *** No private Methods ***
*
*
* -------------------------- Private Data Members -----------------------------
*             Data
*    Type     Type        Name                    Description
* ----------  ----  ----------------  -----------------------------------------
* non-static  int   lengthInches      Length of object, in inches
*
*
* --------------------------- Public Data Members -----------------------------
*             Data
*    Type     Type        Name                    Description
* ----------  ----  ----------------  -----------------------------------------
* static      int   INCHES_PER_FOOT   Conversion factor: Inches per foot
*
*
* -------------------------- Friend Declarations ------------------------------
* Granted    Allowed
*  Class     Method                       Allowed Activity
* -------  ----------  --------------------------------------------------------
* All      operator+    Adds two "Length" objects, RETurning sum of lengths
* All      operator-    Subtracts "Length" objects, RETurning difference
* All      operator<    Boolean of "left" Operand "less than" "right Operand
* All      operator==   Boolean of "left" Operand "eqaul to" "right Operand
* All      operator!=   Boolean of "left" Operand "not eqaul to" "right Operand
*
*******************************************************************************
*/class Length
{
private:
	// 1. Non-static (instance) Variable Declarations
	int lengthInches;

public:
	// 1. Constructors
	//    A. Class Default Constructor
	Length() : lengthInches(0)
	{ }
	//    B. Initializing Constructor
	//       Specify in feet and inches
	Length(int feet, int inches);
	//    C. Initializing Constructor
	//       Specify inches only
	Length(int inches) : lengthInches(0)
	{
		setLength(0, inches);
	}
	//
	// 2. Class Mutator Methods
	//    A. Method: setLength(int,int)
	//       Specified as feet and inches
	void setLength(int feet, int inches);
	//
	// 3. Class Observer Methods
	//    A. Method: getFeet()
	//       Number of whole feet
	int getFeet() const
	{ return lengthInches / INCHES_PER_FOOT; }
	//    B. Method: getInches()
	//       Number of inches remaining
	int getInches() const
	{ return lengthInches % INCHES_PER_FOOT; }
	//
	//
	// 4. "Friend" Method Declarations
	friend Length operator+(Length l, Length r);
	friend Length operator-(Length l, Length r);
	friend bool operator<(Length l, Length r);
	friend bool operator==(Length l, Length r);
	friend bool operator!=(Length l, Length r);
	//
	// 5. Class "static const" Value Declarations
	//    Note: Initialization of "const int" values may occur in the Class Definition.
	//          This is the ONLY "const" data type which may be initialized in the
	//          Class definition.
	static const int INCHES_PER_FOOT = 12;
};
