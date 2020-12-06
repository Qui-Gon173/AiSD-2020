#include <iostream>
#include <algorithm>

#include "Stack.h"
#include "FibGenerator.h"

using namespace std;


// Печать стэка
template <typename T>
void print(Stack<T>& stack) {
    for (auto& value : stack) {
        std::cout << value << std::endl;
    }
}

// Сумму всех значений
template <typename T>
T sum(Stack<T>& stack) {
    T counter = 0;
    for (auto& value : stack) {
        counter += value;
    }

    return counter;
}

// Среднее значение
template <typename T>
T average(Stack<T>& stack) {
    size_t length = stack.length();
    if (!length) {
        throw domain_error("Can't div by 0");
    }

    return sum(stack) / length;
}


int main() {
    FibGenerator<long> gen(10);
    Stack<long> stack(gen);
    print(stack);

    cout << "stack.length(): " << stack.length() << endl;
    cout << "sum(stack): " << sum(stack) << endl;
    cout << "average(stack): " << average(stack) << endl;

    const auto min = min_element(stack.begin(), stack.end());
    const auto max = max_element(stack.begin(), stack.end());
    cout << "stack.min(): " << *min << endl;
    cout << "stack.max(): " << *max << endl;
    cout << "min index = " << distance(stack.begin(), min) << std::endl;
    cout << "max index = " << distance(stack.begin(), max) << std::endl;

    try {
        cout << "stack.top(): " << stack.top() << endl;
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    return 0;
}
