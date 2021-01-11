#pragma once
#include <iostream>
#include <algorithm>
#include "stack.h"

using namespace std;

template <typename T>
void print(Stack<T>& stack) {
    for (auto& i : stack)
        cout << i << " ";
    cout << endl;
}