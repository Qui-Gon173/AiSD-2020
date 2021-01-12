#include <iostream>
#include <algorithm>

#include "List.h"
#include "ArithmeticalGenerator.h"

using namespace std;


template <typename T>
void print(List<T>& list) {
    for (auto& value : list) {
        std::cout << value << std::endl;
    }
}

// Сумму всех значений
template <typename T>
T sum(List<T>& list) {
    T counter = 0;
    for (auto& value : list) {
        counter += value;
    }

    return counter;
}

// Среднее значение
template <typename T>
T average(List<T>& list) {
    size_t length = list.length();
    if (!length) {
        throw domain_error("Can't div by 0");
    }

    return sum(list) / length;
}


int main() {
    ArithmeticalGenerator<long> gen(3, 2, 10);
    List<long> list(gen);
    print(list);

    cout << "list.length(): " << list.length() << endl;
    cout << "sum(list): " << sum(list) << endl;
    cout << "average(list): " << average(list) << endl;

    const auto min = min_element(list.begin(), list.end());
    const auto max = max_element(list.begin(), list.end());
    cout << "list.min(): " << *min << endl;
    cout << "list.max(): " << *max << endl;
    cout << "min index = " << distance(list.begin(), min) << std::endl;
    cout << "max index = " << distance(list.begin(), max) << std::endl;

    return 0;
}
