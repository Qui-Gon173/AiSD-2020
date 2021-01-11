#include <iostream>
#include <utility>

template<typename T>
void heapsort(T array[], int arrayLength) {
    // i -- сдвиг границы отсортированной области
    for (int i = 0; i < arrayLength; i++) {
         //индекс ласт родителя = arrayLength / 2 - 1 - i / 2.
        for (int j = arrayLength/2 - 1 - i/2; j >= 0; j--) {
            if (2*j + 2 <= arrayLength - 1 - i) {
                if (array[2*j + 1] > array[2*j + 2]) { //сравнение детей
                    if (array[j] < array[2*j + 1]) { //срвнение родителя и ребенка
                        std::swap(array[j], array[2*j + 1]);
                    }
                } else {
                    if (array[j] < array[2*j + 2]) {
                        std::swap(array[j], array[2*j + 2]);
                    }
                }
            } else if (2*j + 1 <= arrayLength - 1 - i) { //четный ли массив
                if (array[j] < array[2*j + 1]) {
                    std::swap(array[j], array[2*j + 1]);
                }
            }
        }
        std::swap(array[0], array[arrayLength - 1 - i]); // сортировка по неубыванию
    }
}

int main() {
    const int ARR_LENGTH = 5;
    int array[ARR_LENGTH];

    std::cout << "Выход - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Ввод " << ARR_LENGTH << " целых чисел: ";
        for (int i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }
        heapsort(array, ARR_LENGTH);
        std::cout << "Отсортированные числа: ";
        for (int i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
