#include <iostream>
#include <utility>


void heapsort(int array[], int array_length) {
    for (int i = 0; i < array_length; i++) {
        for (int j = array_length / 2 - 1 - i / 2; j >= 0; j--) {
            if (2 * j + 2 <= array_length - 1 - i) {
                if (array[2 * j + 1] > array[2 * j + 2]) {
                    if (array[j] < array[2 * j + 1]) {
                        std::swap(array[j], array[2 * j + 1]);
                    }
                } else {
                    if (array[j] < array[2 * j + 2]) {
                        std::swap(array[j], array[2 * j + 2]);
                    }
                }
            } else if (2 * j + 1 <= array_length - 1 - i) {
                if (array[j] < array[2 * j + 1]) {
                    std::swap(array[j], array[2 * j + 1]);
                }
            }
        }
        std::swap(array[0], array[array_length - 1 - i]);
    }
}


int main() {
    size_t size;

    std::cout << "size = ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "array of " << size << " ints: ";
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    heapsort(arr, size);

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
