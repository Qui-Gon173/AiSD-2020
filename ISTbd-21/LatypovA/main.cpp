#include <iostream>
#include <algorithm>


void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    int arr[5];
    std::cout << "Array[5]: ";
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    bubble_sort(arr, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
