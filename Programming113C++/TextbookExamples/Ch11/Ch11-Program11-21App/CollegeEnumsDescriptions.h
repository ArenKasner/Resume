#pragma once

/******************************************************************************
*      File: CollegeEnumsDescriptions.h
*
* Programmer: Robert Main
*
* Revision     Date                          Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     04/10/2015  Initial Release
*
* File Description
* ----------------
* This file declars two enumerations utilized by college Classes derived from
* the Base Class, "Person". The enumeration values are "int" values, starting
* with value: 0.
* The corresponding array of "string" descriptions for each enumeration are
* also included here.
*
* The current Classes utilizing these enumerations are:
* 1. Student
* 2. Faculty
*
*******************************************************************************
*/
// External Definition files
#include <string>

// Namespaces utilized in this program
using namespace std;  // Announces to the compiler that members of the namespace
// "std" are utilized in this program


// 1. College Discipline Categories
enum Discipline
{
	ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE
};

const string dName[] =
{ "Archeology", "Biology", "Computer Science" };
//
//
// 2. Student's Classification (Year in college)
enum Classification
{
	FRESHMAN, SOPHOMORE, JUNIOR, SENIOR
};

const string cName[] =
{ "Freshman", "Sophomore", "Junior", "Senior" };
