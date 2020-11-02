#include <iostream>


int main() {
    int array[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> array[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int r = 0; r < 4 - i; r++) {
            if (array[r] > array[r + 1]) {
                int temp = array[r];
                array[r] = array[r + 1];
                array[r + 1] = temp;
            }
        }
    }

    std::cout << "Sorted array: ";
	for(int i = 0; i < 5; i++) {
		std::cout << array[i] << " ";
	}
}
