#include <iostream>
#include <utility>

template<typename T>
void merge_sort(T array[], T buffer[], size_t left, size_t right) {
    if (right <= left) {
        return;
    }

    size_t middle = left + (right - left) / 2;
    merge_sort(array, buffer, left, middle);
    merge_sort(array, buffer, middle + 1, right);

    size_t current_left_index = left;
    size_t current_right_index = middle + 1;
    for (size_t current_buffer_index = left; current_buffer_index <= right; current_buffer_index++) {
        if (current_left_index > middle) {
            buffer[current_buffer_index] = array[current_right_index++];
        } else if (current_right_index > right) {
            buffer[current_buffer_index] = array[current_left_index++];
        } else {
            if (array[current_left_index] < array[current_right_index]) {
                buffer[current_buffer_index] = array[current_left_index++];
            } else {
                buffer[current_buffer_index] = array[current_right_index++];
            }
        }
    }

    for (size_t current_buffer_index = left; current_buffer_index <= right; current_buffer_index++) {
        array[current_buffer_index] = buffer[current_buffer_index];
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
