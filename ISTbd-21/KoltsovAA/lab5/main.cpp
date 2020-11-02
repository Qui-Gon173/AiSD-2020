#include <iostream>
#include <utility>

template<typename T>
void merge_sort(T array[], T buffer[], size_t left_wall, size_t right_wall) {
    if (right_wall <= left_wall) {
        return;
    }

    size_t middle = left_wall + (right_wall - left_wall) / 2;
    merge_sort(array, buffer, left_wall, middle);
    merge_sort(array, buffer, middle + 1, right_wall);

    size_t left = left_wall;
    size_t right = middle + 1;
    for (size_t buffe_index = left_wall;
         buff_index <= right_wall; buff_index++) {

        if (left > middle) {
            buffer[buff_index] = array[right++];
        } else if (right > right_wall) {
            buffer[buff_index] = array[left++];
        } else {
            if (array[left] < array[right]) {
                buffer[buff_index] = array[left++];
            } else {
                buffer[buff_index] = array[right++];
            }
        }
    }

    for (size_t buff_index = left_wall;
        buff_index <= right_wall; buff_index++) {

        array[buff_index] = buffer[buff_index];
    }
}


int main() {
    const size_t ARR_LENGTH = 8;
    int array[ARR_LENGTH];
    int buffer[ARR_LENGTH];
    
    std::cout << "Exit - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Input " << ARR_LENGTH << " integers: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }

        merge_sort(array, buffer, 0, ARR_LENGTH - 1);

        std::cout << "Sorted: ";
        for (size_t i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
