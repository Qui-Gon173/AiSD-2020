#include <iostream>


void heapsort(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) { //i - сдвиг границы отсортированной области
        for (int j = arrayLength / 2 - 1 - i / 2; j >= 0; j--) {
            if (2 * j + 2 <= arrayLength - 1 - i) { //arrayLength - 1 - i - последний родитель
                if (array[2 * j + 1] > array[2 * j + 2]) { //сравнение детей
                    if (array[j] < array[2 * j + 1]) { //срвнение родителя и ребенка
                        std::swap(array[j], array[2 * j + 1]);
                    }
                }
                else {
                    if (array[j] < array[2 * j + 2]) {
                        std::swap(array[j], array[2 * j + 2]);
                    }
                }
            }
            else if (2 * j + 1 <= arrayLength - 1 - i) { //если массив нечетный
                if (array[j] < array[2 * j + 1]) {
                    std::swap(array[j], array[2 * j + 1]);
                }
            }
        }
        std::swap(array[0], array[arrayLength - 1 - i]); //смена 1 и последнего для сортировки по возрастанию
    }
}


int main() {
    const int arrayLength = 5;
    int array[arrayLength];

    std::cout << "Enter " << arrayLength << " numbers: ";
    for (int i = 0; i < arrayLength; i++) {
        std::cin >> array[i];
    }

    heapsort(array, arrayLength);

    std::cout << "Sorted list: ";
    for (int i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
}