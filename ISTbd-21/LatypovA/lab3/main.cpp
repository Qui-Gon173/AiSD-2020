#include <iostream>
#include <utility>


template<typename T>
void hoarsort(T array[], size_t left, size_t right) {
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
        hoarsort(array, left, j);
    if (i < right)
        hoarsort(array, i, right);
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

    hoarsort(arr, 0, size - 1);

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
