#include <iostream>
#include <utility>


template<typename T>
void quicksort(T array[], size_t left, size_t right) {
    if (left > right) {
        return;
    }

    size_t i = left;
    size_t j = right;

    T pivot = array[i + (j - i) / 2];

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            if (!j) {
                break;
            }
            j--;
        }
    }

    if (j > left)
        quicksort(array, left, j);
    if (i < right)
        quicksort(array, i, right);
}


int main() {
    const size_t ARR_LENGTH = 5;
    int array[ARR_LENGTH];
    
    std::cout << "Exit - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Input " << ARR_LENGTH << " integers: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }

        quicksort(array, 0, ARR_LENGTH - 1);

        std::cout << "Sorted: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
