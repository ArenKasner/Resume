#include "inheritance4.h" 
#include <iostream>
using namespace std;

//Global constants used for printing enumerated
//types
const string dName[] = {
  "Archeology", "Biology", "Computer Science"
};

const string cName[] = {
  "Freshman", "Sophomore", "Junior", "Senior"
};

int main()
{
   TFaculty prof("Indiana Jones", ARCHEOLOGY, "Dr.");
   Student st("Sean Bolster", ARCHEOLOGY, &prof);
   
   cout << prof.getName()
        << " teaches " << dName[prof.getDepartment()]
        << "." << endl;

   // Get student's advisor
   Person *pAdvisor = st.getAdvisor();
   cout << st.getName() <<"\'s advisor is " 
        << pAdvisor->getName() << ".";

   return 0;
}
        
