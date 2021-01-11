#include <iostream>
#include <utility>

typedef int element_t;

void selectSort(element_t array[], size_t arrayLength) {
    if (!arrayLength) {
        return;
    }
    for (size_t i = 0; i < arrayLength - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < arrayLength; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(array[i], array[min]);
            min = i;
        }
    }
}

int main() {
    const size_t ARR_LENGTH = 5;
    element_t array[ARR_LENGTH];
    
    while (true) {
        std::cout << "Ввод " << ARR_LENGTH << " целых чисел: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }
        selectSort(array, ARR_LENGTH);
        std::cout << "Отсортированные числа: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}