// This program demonstrates some C++ string class
// constructors.
#include <iostream>
#include <string>
using namespace std; 

int main() 
{
   string greeting;                // Default constructor
   string name("William Smith");   // Convert constructor
	
   greeting = "Hello ";
   cout << greeting << name << endl;
   return 0;
}