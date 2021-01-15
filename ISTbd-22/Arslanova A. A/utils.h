#pragma once
#include <iostream>
#include "List.h"

typedef unsigned char long_t;

void print(List& list) {
    for (auto& item : list) {
        std::cout << static_cast<int>(item) << std::endl;
    }
}

int sum(List& list) {
    int counter = 0;
    for (auto& item : list) {
        counter += item;
    }

    return counter;
}

float average(List& list) {
    size_t size = list.GetSize();
    return size ? sum(list) / size : 0;
}
