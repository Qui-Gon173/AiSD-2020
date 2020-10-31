#include <iostream>
#include <utility>

typedef int element_t;


void selection_sort(element_t array[], size_t array_length) {
    if (!array_length) {
        return;
    }

    for (size_t i = 0; i < array_length - 1; i++) {
        size_t min_i = i;
        for (size_t j = i + 1; j < array_length; j++) {
            if (array[j] < array[min_i]) {
                min_i = j;
            }
        }

        if (min_i != i) {
            std::swap(array[i], array[min_i]);
            min_i = i;
        }
    }
}


int main() {
    const size_t ARR_LENGTH = 5;
    element_t array[ARR_LENGTH];
    
    std::cout << "Exit - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Input " << ARR_LENGTH << " integers: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }

        selection_sort(array, ARR_LENGTH);

        std::cout << "Sorted: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
