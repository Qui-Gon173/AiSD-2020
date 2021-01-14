#pragma once
#include <iostream>
#include "Vector.h"


template<typename T>
void print(Vector<T>& vector) {
    std::cout << "[" << std::endl;
    for (auto& element : vector) {
        std::cout << "    " << element << "," << std::endl;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
T get_sum(Vector<T>& vector) {
    T counter = 0;
    for (auto& element : vector) {
        counter += element;
    }
    return counter;
}

template<typename T>
T get_average(Vector<T>& vector) {
    return vector.len() ? get_sum(vector) / vector.len() : 0;
};
