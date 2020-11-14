#include <iostream>
#include <algorithm>
#include "Stack.h"

template <typename T>
T sum(Stack<T>& stack) {
    T summary = 0;
    for (auto& i : stack) {
        summary += i;
    }
    return summary;
}

template <typename T>
void printStack(Stack<T>& stack) {
    for (auto& i : stack)
        std::cout << i << " ";
    std::cout << std::endl;
}

template <typename T>
T average(Stack<T>& stack) {
    return stack.getTop() ? sum(stack) / stack.getTop() : 0;
}

template <typename T>
T min(Stack<T>& stack) {
    const auto min = std::min_element(stack.rbegin(), stack.rend());
    return *min;
}

template <typename T>
T max(Stack<T>& stack) {
    const auto max = std::max_element(stack.rbegin(), stack.rend());
    return *max;
}

template <typename T>
void fill(Stack<T>& stack) {
    T a = 0;
    for (auto& i : stack)
        i = a;
        a = a + 12;
}