#include "intstack.h"
//************************************
// Constructor                       *
//************************************
IntStack::IntStack(int capacity)
{
    this->capacity = capacity;
    stackArray = new int[capacity];
    top = 0;
}         

//***********************************
// Adds a value to the stack        *
//***********************************
void IntStack::push(int value) 
{
    if (top == capacity) throw IntStack::Overflow();
    stackArray[top] = value;
    top++;
}

//****************************************
// Determines whether the stack is empty *
//****************************************
bool IntStack::isEmpty() const
{
    if (top == 0)
        return true;
    else
        return false;
}

//************************************************
// Removes a value from the stack and returns it *
//************************************************
void IntStack::pop(int &value)
{
    if (isEmpty()) throw IntStack::Underflow();
    top --;
    value = stackArray[top];
}

