#include <iostream>

int main() {
    int n;
    std::cout << "Array length: ";
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cout << std::endl;
    
    for (int j = 0; j < n; j++) {
        for (int i = n / 2 - 1 - j / 2; i > -1; i--) {
            if (2 * i + 2 <= n - 1 - j) {
                if (array[2 * i + 1] > array[2 * i + 2]) {
                    if (array[i] < array[2 * i + 1]) {
                        int temp = array[i];
                        array[i] = array[2 * i + 1];
                        array[2 * i + 1] = temp;
                    }
                }
                else {
                    if (array[i] < array[2 * i + 2]) {
                        int temp = array[i];
                        array[i] = array[2 * i + 2];
                        array[2 * i + 2] = temp;
                    }
                }
            }
            else {
                if (2 * i + 1 <= n - 1 - j) {
                    if (array[i] < array[2 * i + 1]) {
                        int temp = array[i];
                        array[i] = array[2 * i + 1];
                        array[2 * i + 1] = temp;
                    }
                }
            }
        }
        int temp = array[0];
        array[0] = array[n - 1 - j];
        array[n - 1 - j] = temp;
    }

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
