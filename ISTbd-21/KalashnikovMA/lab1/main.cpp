#include <iostream>
#include <cstdlib>


int search_bar(const int key, int arr[], const int arr_length) {
    arr[arr_length] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
    }

    return i < arr_length ? i : -1;
}


int main() {
    int len = 5;
    int* arr = reinterpret_cast<int*>(malloc((len + 1) * sizeof(int)));

    std::cout << "input " << len << " ints: ";
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cout << std::endl;

    while (true) {
        int key;
        std::cout << "key: ";
        std::cin >> key;
        std::cout << search_bar(key, arr, len) << std::endl;
    }
}
