#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
   // Constructor.
   SearchableVector(int s) : SimpleVector<T>(s)	
   	{ }
   // Copy constructor.		
   SearchableVector(SearchableVector &);
	// Additional constructor. 
   SearchableVector(SimpleVector<T> &obj):
           SimpleVector<T>(obj){ }
   int findItem(T);
};

//******************************************
// Definition of the copy constructor.     *
//******************************************
template <class T>
SearchableVector<T>::
SearchableVector(SearchableVector &obj) : 
SimpleVector<T>(obj)
{
}

//******************************************
// findItem takes a parameter of type T    *
// and searches for it within the array.   *
//******************************************
template <class T>
int SearchableVector<T>::findItem(T item)
{
   for (int count = 0; count < this->size(); count++)
   {
      if (this->operator[](count) == item)
         return count;
   }
   return -1;
}
#endif