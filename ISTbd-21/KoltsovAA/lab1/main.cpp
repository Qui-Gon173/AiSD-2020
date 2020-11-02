#include <iostream>
#include <algorithm>

typedef int element_t;


size_t binary_search(element_t array[], size_t array_length, element_t key) {
    size_t left = 0;
    size_t right = array_length;

    while (left != right) {
        size_t middle = left + (right - left) / 2;
        element_t value = array[middle];
    
        if (value < key) {
            left = middle + 1;
        } else if (value > key) {
            right = middle;
        } else {
            return middle;
        }
    }

    return -1;
}


int main() {
    const size_t ARR_LENGTH = 5;
    element_t array[ARR_LENGTH];
    std::cout << "Input " << ARR_LENGTH << " integers: ";
    for (size_t i = 0; i < ARR_LENGTH; i++) {
        std::cin >> array[i];
    }

    std::sort(array, array + ARR_LENGTH);
    std::cout << "Sorted: ";
    for (size_t i = 0; i < ARR_LENGTH; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Exit - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Get index of value: ";
        element_t key;
        std::cin >> key;
        std::cout << binary_search(array, ARR_LENGTH, key) << std::endl;
    }
}
