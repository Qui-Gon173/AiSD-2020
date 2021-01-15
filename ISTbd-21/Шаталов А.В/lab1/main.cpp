#include <iostream>
#include <algorithm>

typedef int element_t;

size_t binarySearch(element_t array[], size_t arrayLength, element_t key) {
    size_t low = 0;
    size_t high = arrayLength;

    while (low != high) {
        size_t middle = low + (high - low) / 2;
        element_t value = array[middle];

        if (value < key) {
            low = middle + 1;
        } else if (value > key) {
            high = middle;
        } else {
            return middle;
        }
    }
    return -1;
}

int main() {
    const size_t ARR_LENGTH = 5;
    element_t array[ARR_LENGTH];
    std::cout << "Ввод " << ARR_LENGTH << " целых чисел: ";
    for (size_t i = 0; i < ARR_LENGTH; i++) {
        std::cin >> array[i];
    }
    std::sort(array, array + ARR_LENGTH);
    std::cout << "Отсортированные числа: ";
    for (size_t i = 0; i < ARR_LENGTH; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    while (true) {
        std::cout << "Получить индекс числа: ";
        element_t key;
        std::cin >> key;
        std::cout << binarySearch(array, ARR_LENGTH, key) << std::endl;
    }
}
