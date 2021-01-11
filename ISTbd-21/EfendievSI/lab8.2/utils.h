#pragma once

#include <iostream>
#include "List.h"


void print(List& list) {
    for (auto& item : list) {
        std::cout << static_cast<int>(item) << " ";
    }
    cout << endl;
}


int sum(List& list) {
    int counter = 0;
    for (auto& item : list) {
        counter += item;
    }

    return counter;
}


float average(List& list) {
    size_t size = list.getSize();
    return size ? sum(list) / size : 0;
}