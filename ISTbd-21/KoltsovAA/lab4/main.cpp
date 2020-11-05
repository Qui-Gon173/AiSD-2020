#include <iostream>
#include <utility>


template<typename T>
void heapsort(T array[], int array_length) {
    // i -- сдвиг границы отсортированной области (с конца)
    for (int i = 0; i < array_length; i++) {
        /**
         * Для каждого родителя, начиная с последнего
         * в неотсортированной области
         * индекс ласт родителя = array_length / 2 - 1 - i / 2.
         * 
         * Смысл вообще в том, чтобы проверить каждого родителя
         * и каждого ребенка родителя и сделать так, чтобы
         * родитель всегда был больше потомка. Для этого находим
         * самого "взрослого" сына и ставим его на трон отца.
         * 
         * Еще формулы.
         * Для родителя (Р) с индексом n
         * левый ребенок (ЛР) = 2*n + 1,
         * правый ребенок (ПР) = 2*n + 2.
         */
        for (int j = array_length/2 - 1 - i/2; j >= 0; j--) {
            // если ПР существует в
            // неотсортированной области
            if (2*j + 2 <= array_length - 1 - i) {
                // если ЛР больше ПР
                if (array[2*j + 1] > array[2*j + 2]) {
                    // если Р меньше ЛР (который > ПР)
                    if (array[j] < array[2*j + 1]) {
                        std::swap(array[j], array[2*j + 1]);
                    }
                } else { // иначе ПР > ЛР
                    if (array[j] < array[2*j + 2]) {
                        std::swap(array[j], array[2*j + 2]);
                    }
                }
            // иначе проверяем, что хоть ЛР существует
            } else if (2*j + 1 <= array_length - 1 - i) {
                if (array[j] < array[2*j + 1]) {
                    std::swap(array[j], array[2*j + 1]);
                }
            }
        }

        // сортировка по неубыванию
        std::swap(array[0], array[array_length - 1 - i]);
    }
}


int main() {
    const int ARR_LENGTH = 5;
    int array[ARR_LENGTH];

    std::cout << "Exit - Ctrl+C" << std::endl;
    while (true) {
        std::cout << "Input " << ARR_LENGTH << " integers: ";
        for (int i = 0; i < ARR_LENGTH; i++) {
            std::cin >> array[i];
        }

        heapsort(array, ARR_LENGTH);

        std::cout << "Sorted: ";
        for (int i = 0; i < ARR_LENGTH; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}
