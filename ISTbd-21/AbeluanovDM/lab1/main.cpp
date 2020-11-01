#include <iostream>


int linesearch(int array[], int key) {
    for(int i = 0; i < 10; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> array[i];
    }   
    int x;
    std::cin >> x;
    std::cout << linesearch(array, x);
}