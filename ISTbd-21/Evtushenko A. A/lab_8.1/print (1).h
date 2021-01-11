#pragma once
#include "stack.h"
using namespace std;

template <typename T>

void Stack<T>::print()
{
    for (int i = index - 1; i >= 0; i--)
        cout << pStack[i] << " ";
    cout << endl;
}

template <class T>
void Stack<T>::print_top_stack() const
{
    cout << pStack[index];
}