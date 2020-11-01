#include <iostream>
#include <algorithm>


void hoarsort(int array[], size_t left, size_t right)
{
    size_t i = left;
    size_t j = right;

    int pivot = array[i + (j - i) / 2];

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
    const size_t arrayLength = 10;
    int array[arrayLength];

    std::cout << "Input " << arrayLength << " numbers: ";
    for (size_t i = 0; i < arrayLength; i++) {
        std::cin >> array[i];
    }

    hoarsort(array, 0, arrayLength - 1);

    std::cout << "Sorted: ";
    for (size_t i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
}
