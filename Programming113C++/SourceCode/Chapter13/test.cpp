#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{   
   string name("file.txt");
   fstream f(name, ios::out);
   f << "aha";
   f.close();
   
   cout << "file opened.";
   return 0;
}


ifstream()
ofstream()
fstream()