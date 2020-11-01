#include <iostream>

int main() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> array[i];
    }

    std::cout << std::endl;
    
    for (int j = 0; j < 10; j++) {
        for (int i = 10 / 2 - 1 - j / 2; i > -1; i--) {
            if (2 * i + 2 <= 10 - 1 - j) {
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
                if (2 * i + 1 <= 9 - j) {
                    if (array[i] < array[2 * i + 1]) {
                        int temp = array[i];
                        array[i] = array[2 * i + 1];
                        array[2 * i + 1] = temp;
                    }
                }
            }
        }
        int temp = array[0];
        array[0] = array[9 - j];
        array[9 - j] = temp;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
