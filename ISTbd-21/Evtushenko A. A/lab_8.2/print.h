#pragma once
#include <iostream>
#include <algorithm>
#include "stack.h"

template <typename T>
void print(Stack<T>& stack) {
    for (auto& i : stack)
        std::cout << i << " ";
    std::cout << std::endl;
}