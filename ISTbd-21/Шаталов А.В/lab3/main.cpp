#include <iostream>
#include <utility>

template<typename T>
void quickSort(T array[], size_t low, size_t high) {
    if (low > high) {
        return;
    }

    size_t i = low;
    size_t j = high;

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
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main() {
    const size_t ARR_LENGTH = 5;
    int array[ARR_LENGTH];

    std::cout << "Выход - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Ввод " << ARR_LENGTH << " целых чисел: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }
        quickSort(array, 0, ARR_LENGTH - 1);
        std::cout << "Отсортированные числа: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
