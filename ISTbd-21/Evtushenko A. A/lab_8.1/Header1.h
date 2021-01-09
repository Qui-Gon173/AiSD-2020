#pragma once
#include "Header.h"
template <typename T>
void Stack<T>::print()
{
    for (int i = index - 1; i >= 0; i--)
        std::cout << stackPtr[i] << " ";
    std::cout << std::endl;
}

template <class T>
void Stack<T>::print_top_stack() const
{
    std::cout << stackPtr[index];
}