// This program provides a simple demonstration of the
// vector STL template.
#include <iostream>
#include <vector>  // Needed to use vectors
using namespace std;

int main()
{ 
    vector<int> vect;   // Create a vector of int

    for (int x = 0; x < 10; x++)
       vect.push_back(x*x);

   // Print everything using iterators  
   vector<int>::iterator iter = vect.begin();
   while (iter != vect.end())
   {
     cout <<  *iter << " ";
     iter ++;
   }
   return 0;
}