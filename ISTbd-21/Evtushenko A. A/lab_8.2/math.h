#include <iostream>
#include <algorithm>
#include "stack.h"

using namespace std;

template <typename T>
T sum(Stack<T>& stack) {
    T result = 0;
    for (auto& i : stack) {
        result += i;
    }
    return result;
}

template <typename T>
T min(Stack<T>& stack) {
    const auto min = min_element(stack.rbegin(), stack.rend());
    return *min;
}

template <typename T>
T max(Stack<T>& stack) {
    const auto max = max_element(stack.rbegin(), stack.rend());
    return *max;
}

template <typename T>
T average(Stack<T>& stack) {
    return stack.getNumElement() ? sum(stack) / stack.getNumElement() : 0;
}

template <typename T>
void completion(Stack<T>& stack) {
    T a = 0;
    for (auto& i : stack)
        i = a;
    a = a + 12;
}
