#include <iostream>

int main() {
    int n;
    std::cout << "Array length: "; 
    std::cin >> n; // А какой там размер у массива?
    int array[n];
    for (int i = 0; i < n; i++) { // Вы_ВВОД
        std::cin >> array[i];
    }

    std::cout << std::endl;
    
    for (int j = 0; j < n; j++) { // Проходимся по массиву
        for (int i = n / 2 - 1 - j / 2; i > -1; i--) { // находим последнего родителя для j -> | n / 2 - 1 - j |
            if (2 * i + 2 <= n - 1 - j) { // Если массив чётный
                if (array[2 * i + 1] > array[2 * i + 2]) {
                    if (array[i] < array[2 * i + 1]) { // проверка левого ребенка к родителю и/или свап
                        int temp = array[i];
                        array[i] = array[2 * i + 1];
                        array[2 * i + 1] = temp;
                    }
                }
                else {
                    if (array[i] < array[2 * i + 2]) { // проверка правого ребенка к родителю и/или свап
                        int temp = array[i];
                        array[i] = array[2 * i + 2];
                        array[2 * i + 2] = temp;
                    }
                }
            }
            else {
                if (2 * i + 1 <= n - 1 - j) { // Если массив нечётный
                    if (array[i] < array[2 * i + 1]) { // проверка левого ребенка к родителю и/или свап
                        int temp = array[i];
                        array[i] = array[2 * i + 1];
                        array[2 * i + 1] = temp;
                    }
                }
            }
        }
        // что бы сделать отсортированный массив по возростанию, так как при обычной пирамидальной сортировке массив сортируется по убыванию.
        int temp = array[0];
        array[0] = array[n - 1 - j];
        array[n - 1 - j] = temp;
    }

    for (int i = 0; i < n; i++) { // ВывАд
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
