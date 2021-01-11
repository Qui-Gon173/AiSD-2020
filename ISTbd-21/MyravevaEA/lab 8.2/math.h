#include <iostream>
#include <algorithm>
#include "Steck.h"

template <typename T>
void printSteck(Steck<T>& steck) {
    for (auto& i : steck) {
        std::cout << i << std::endl;
    }
}

template <typename T>
T sum(Steck<T>& steck) {
    T summary = 0;
    for (auto& i : steck) {
        summary += i;
    }
    return summary;
}

template <typename T>
T average(Steck<T>& steck) {
    int x = 0;
    if (steck.getNum() > 0) {
        x = sum(steck) / steck.getNum();
    }
    return x;
}

template <typename T>
T min(Steck<T>& steck) {
    const auto min = std::min_element(steck.rbegin(), steck.rend());
    return *min;
}

template <typename T>
T max(Steck<T>& steck) {
    const auto max = std::max_element(steck.rbegin(), steck.rend());
    return *max;
}
