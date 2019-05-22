/******************************************************************************
 * Bellevue Class: PROG 113
 *           Term: Spring 2015
 *     Instructor: Robert Main
 *
 * Solution/Project Name: PROG113_MidtermExam
 *             File Name: MidtermExam.cpp
 *
 * This file defines the entry point method, main(), for a C++ Console
 * application. When the executable file is selected for execution, the OS
 * will transfer execution to the first line of code in method main(). Other
 * methods called from main() may be defined here as well.
 *
 * Programmer: Aren Kasner
 *
 * Revision     Date                        Release Comment
 * --------  ----------  ------------------------------------------------------
 *   1.0     05/xx/2015  Initial Release
 *
 * File Methods
 * ------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * main          Program entry point method
 *
 * UDT Classes Utilized
 * --------------------
 *     Name                             Description
 * ------------  --------------------------------------------------------------
 * Mail          Base class: Common services for a mail item of any type
 * Package       Sub-class:  Fixed cost, adds delivery days feature
 *
 * Program Inputs
 * --------------
 *  None
 *
 * Program Outputs
 * ---------------
 *   Stream Type                             Description
 * ---------------  -----------------------------------------------------------
 * Console Monitor  Display of various objects of type "Mail" and "Package"
 *
 ******************************************************************************
 */
// External Definition files
// The first inclusion file MUST always be declared and MUST be first in the list
#include "stdafx.h"  // Defines IDE required external definition files
#include <iostream>  // Defines objects and classes used for stream I/O
#include <iomanip>   // Defines I/O Manipulators needed here

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

/******************************************************************************
 * Class Name: Mail
 * Base Class: None
 *
 * This file defines the members of the class: Mail
 * These members include class variable data members, class constant, static
 * data members, and class method declarations only and/or class method
 * declarations and definitions.
 *
 * Class Description
 * -----------------
 *
 * Class Data Members
 * ------------------
 *     Name        Scope     Type                   Description
 * ------------  ---------  ------  --------------------------------------------
 * TYPE_SIZE     private    char[]  Size of C-Style array: Mail Type    (static)
 * FIRST_CLASS   private    char[]  C-Style string array: "First Class" (static)

 *                ***** add required data member(s) here *****
 *
 * Class Methods
 * -------------
 *           Name          Scope                   Description
 * ----------------------  ------  --------------------------------------------
 * Mail()                  public  Class Default Constructor: First Class, 1 weight
 * Mail(char*,double,int)  public  Class Initializing Constructor
 * Mail(const Mail&)       public  Class Copy Constructor
 * ~Mail()                 public  Class Destructor
 * getCost()               public  RETurn total cost to mail item
 * operator=(const Mail&)  public  Assignment Operator
 * operator+(int)          public  Addition Operator: Add ounces to item
 * operator<<()            public  Insertion Operator: "string" description
 *
 ******************************************************************************
 */
class Mail
{
	// Public Interface
public:
	// Class Constructor(s)
	Mail();
	Mail(const char* type, double perOunceCost, int weight);
	Mail(const Mail& other);

	// Class Destructor
	~Mail()
	{ }  // Nothing to do, included for completeness

	// Mutator Methods
	Mail operator=(const Mail& rValue);
	Mail operator+(int ounces);

	// Observer Methods
	double getCost() const;
	friend ostream& operator<<(ostream& stream, const Mail letter);

protected:
	// Class "static, const" Constant Values
	static const int TYPE_SIZE = 30;
	static const char FIRST_CLASS[];
	static const double DEFAULT_COST;
	// **** Add any other "static, const" values here ****

	// Variable Declarations
	char type[TYPE_SIZE];	// C-Style "string" array (Required!)
	double cost;
	int weight;
	//  ****** Add required class data member(s) here ******

};

ostream& operator<<(ostream& stream, const Mail letter)
{
	
	return stream << "Mail Class: " <<letter.type<< endl
				  << "    Weight: "<<letter.weight << " oz."<< endl
				  << "Total Cost: $" << letter.getCost();
}

Mail::Mail()
{
	strcpy_s(this->type, FIRST_CLASS);
	this->cost = DEFAULT_COST;
	this->weight = 1;

}

Mail::Mail(const char* type, double perOunceCost, int weight)
{
	strcpy_s(this->type, type);
	this->cost = perOunceCost;
	this->weight = weight;

}

Mail::Mail(const Mail& other)
{
	strcpy_s(this->type, other.type);
	this->cost = other.cost;
	this->weight = other.weight;
}

Mail Mail::operator=(const Mail& rValue)
{	
	
	strcpy_s(this->type,rValue.type);
	this->weight = rValue.weight;
	this->cost = rValue.cost;
	return *this;
}
Mail Mail::operator+(int ounces)
{
	Mail temp = *this;
	temp.weight = temp.weight + ounces;
	return temp;
}

double Mail::getCost() const
{
	double total_cost;
	total_cost = this->weight*this->cost;
	return total_cost;
}

// Class "static, const" Value Declarations
// 1. Description of first class mail item
const char Mail::FIRST_CLASS[] = "First Class";
const double Mail::DEFAULT_COST = .49;
// Define the external methods for class "Mail" here



/******************************************************************************
 * Class Name: Package
 * Base Class: Mail
 *
 * This file defines the members of the class: Package
 * These members include class variable data members, class constant, static
 * data members, and class method declarations only and/or class method
 * declarations and definitions.
 *
 * Class Description
 * -----------------
 *
 * Class Data Members
 * ------------------
 * Name   Scope    Type                     Description
 * ---- --------- ------ ------------------------------------------------------
 *                ***** add required data member(s) here *****
 *
 * Class Methods
 * -------------
 *           Name            Scope                   Description
 * -----------------------  -------  ------------------------------------------
 * Package(double,int,int)  public   Class Initializing Constructor
 * Package(const Package&)  public   Class Copy Constructor
 * ~Package()               public   Class Destructor
 * operator<<()             public   Overloaded, friend Insertion Operator
 *
 ******************************************************************************
 */
class Package : public Mail
{
	// Public Interface
public:
	// Class Constructor(s)
	Package(double cost, int weight, int days);
	Package(const Package& other);
	double getCost() const;
	
	// Class Destructor
	~Package()
	{ }  // Nothing to do, included for completeness

	// Mutator Methods
	// None

	// Observer Methods
	friend ostream& operator<<(ostream& stream, const Package package);

private:
	// Class static, "const" Constant Values
	static const char EXPRESS_MAIL[];
	static const int TYPE_SIZE = 30;
	// Variable Declarations
	//  ****** Add required class data member(s) here ******

	int days;
	
};

ostream& operator<<(ostream& stream, const Package package)
{
	cin.clear();
	return stream << "Mail Class: "<<package.type <<endl
				  << "    Weight: "<<package.weight <<" oz."<<endl
				  << "Total Cost: $ "<<package.getCost() <<endl
				  << "  Delivery: " <<package.days <<" days";
}

Package::Package(double cost, int weight, int days)
{
	strcpy_s(this->type,EXPRESS_MAIL);
	this->cost = cost;
	this->weight = weight;
	this->days = days;
}

Package::Package(const Package& other)
{

	strcpy_s(this->type, other.type);
	this->cost = other.cost;
	this->weight = other.weight;
	this->days = other.days;

}

double Package::getCost() const
{	
	
	double package_cost = this->cost;
	
	cout << showpoint << fixed << setprecision(2);
	
	return package_cost;
	
}

// Class "static, const" Value Declarations
// 1. Description of first class mail item
const char Package::EXPRESS_MAIL[] = "Express Mail";

// Define the external methods for class "Package" here



/******************************************************************************
 * Method: main()
 * 
 * Method Description
 * ------------------
 * This Client program will test the various requirements for creating,"
 * copying, adding an "int" value to an object, and assigning one object"
 * to another object. The objects are of two types, 1) A base class,"
 * "Mail", and 2) A derived class (sub-class), "Package".
 *
 * Method Arguments
 * ----------------
 * None
 * 
 * Pre-Conditions
 * --------------
 * None
 *
 * Return Value (Post-Condition)
 * -----------------------------
 * Type                              Description
 * ----  ---------------------------------------------------------------
 * int   Program Status to OS: 0 - No errors
 *
 ***************************************************************************
 */
int main()          
{
	// Constant "const" Value Declaration
	const int ADDITIONAL_WEIGHT = 5;      // Ounces
	const double PACKAGE_COST = 7.50;     // Dollars
	const int PACKAGE_WEIGHT = 42;        // Ounces
	const int PACKAGE_DELIVERY_TIME = 3;  // Days

	// Initialized Variable Declarations
	// 1. A "Mail" object, default type (First class, 1 weight, @ .49 per ounce)
	Mail mailItem1;
	// 2. A copy of the default "Mail" object
	Mail mailItem2(mailItem1);
	// 3. An object of type "Package"
	Package package1(PACKAGE_COST, PACKAGE_WEIGHT, PACKAGE_DELIVERY_TIME);
	// 4. A copy of the "Package" object
	Package package2(package1);


	// Describe the program to the User
	cout <<   "                       PROG-113: Midterm Exam\n\n"
		 <<   "This Client program will test the various requirements for creating,"
		 << "\ncopying, adding an \"int\" value to an object, and assigning one object"
		 << "\nto another object. The objects are of two types, 1) A base class,"
		 << "\n\"Mail\", and 2) A derived class (sub-class), \"Package\".\n" << endl;


	// Test the Insertion Operator for class "Mail"
	cout << "\"mailItem1\":\n" << mailItem1 << endl;
	cout << "\n\"mailItem2\", a copy of \"mailItem1\":\n"
		 << mailItem2 << endl;

	// Test the Addition and Assignment Operators, class "Mail"
	mailItem1 = mailItem1 + ADDITIONAL_WEIGHT;
	cout << "\nAdding " << ADDITIONAL_WEIGHT << " weight. to weight of \"mailItem1\":\n"
		 << mailItem1 << endl;
	cout << "\n\"mailItem2\", AFTER adding weight to \"mailItem1\":\n"
		 << mailItem2 << endl;

	cout << "\n\"package1\":\n" << package1 << endl;

	cout << "\n\"package2\", a copy of \"package1\":\n" << package2 << endl;
	
	cout << "\nCost of \"mailItem1\": " << mailItem1.getCost() << endl;
	cout <<   "Cost of \"mailItem2\": " << mailItem2.getCost() << endl;
	cout <<   "Cost of \"package1\":  " << package1.getCost() << endl;



	// This prevents the Visual Studio Console Window from closing during
	// debug mode and allows you to select and copy the results displayed in
	// the Console window.
	cout << endl;  // Inserts a blank line before the prompt occurs
	system("pause");

	return 0;

}	// End method: main()
