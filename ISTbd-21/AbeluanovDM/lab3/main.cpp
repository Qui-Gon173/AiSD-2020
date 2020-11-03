#include <iostream>


void quicksort(int array[], int left, int right) {
    int i = left;
    int y = right;
    int temp;
    int pivot = array[(i + y) / 2];

        while (i <= y) {
            while (array[i] < pivot) {
                i++;
            }
            while (array[y] > pivot) {
                y--;
            }
            if (i <= y) {
                temp = array[i];
                array[i] = array[y];
                array[y] = temp;
                i++;
                y--;
            }
        }

    if (y > left)
        quicksort(array, left, y);
    if (i < right)
        quicksort(array, i, right);
}


int main() {
    const int length = 5;
    int array[length];
    std::cout << "Before sort: "; 
    while (true) {
        for (int i = 0; i < length; i++) {
            std::cin >> array[i];
        }

        quicksort(array, 0, length - 1);

        std::cout << "Sorted: ";
        for (int i = 0; i < length; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
