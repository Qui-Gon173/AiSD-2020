#include <iostream>


void merge_sort(int array[], int buffer[], int left_w, int right_w) {
    if (right_w <= left_w) {
        return;
    }

    int middle = left_w + (right_w - left_w) / 2;
    merge_sort(array, buffer, left_w, middle);
    merge_sort(array, buffer, middle + 1, right_w);

    int left = left_w;
    int right = middle + 1;
    for (int buff_i = left_w; buff_i <= right_w; buff_i++) {
        if (left > middle) {
            buffer[buff_i] = array[right++];
        } else if (right > right_w) {
            buffer[buff_i] = array[left++];
        } else {
            if (array[left] < array[right]) {
                buffer[buff_i] = array[left++];
            } else {
                buffer[buff_i] = array[right++];
            }
        }
    }

    for (int buff_i = left_w; buff_i <= right_w; buff_i++) {

        array[buff_i] = buffer[buff_i];
    }
}


int main() {
    const int length = 8;
    int array[length];
    int buffer[length];
    
    std::cout << "Input 8 integers: ";
    for (int i = 0; i < length; i++) {
        std::cin >> array[i];
    }

    merge_sort(array, buffer, 0, length - 1);

    std::cout << "Sorted: ";
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

}
