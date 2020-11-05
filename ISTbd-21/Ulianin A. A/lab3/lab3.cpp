#include <iostream>
#include <clocale>

using namespace std;

/// функция быстрой сортировки (сортировка методом Хоара)
void quickSort(int * massiv, int left, int right) {
    
    int i = left; // указатель в начало массива
    int j = right; // указатель в конец массива

    int mid = massiv[(i + j) / 2]; // центральный (опорный) элемент массива

    int tmp = 0; // буфер обмена

    /// деление массива
    while (i <= j)
    {
        /// в левой части массива оставляем элементы, которые меньше центрального
        while (massiv[i] < mid)
        {
            i++; // сдвигаем левую часть массива
        }

        /// в правой части массива оставляем элементы, которые больше центрального
        while (massiv[j] > mid)
        {
            j--; // сдвигаем правую часть массива
        }

        /// меняем элементы местами
        if (i <= j)
        {
            tmp = massiv[i];
            massiv[i] = massiv[j];
            massiv[j] = tmp;

            i++;
            j--;
        }
    }

    /// рекурсивный вызов сортировки для левой части массива
    if (left < j)
    {
        quickSort(massiv, left, j);
    }

    /// рекурсивный вызов сортировки для правой части массива
    if (i < right) 
    {
        quickSort(massiv, i, right);
    }
}


int main() {
    
    setlocale(LC_ALL, "ru");

    int lengthArray; // длина массива

    cout << "Введите количество элементов массива: ";
    cin >> lengthArray;

    /// текущий массив
    int* currentArray = (int*)malloc(lengthArray * sizeof(int)); // выделение памяти
    
    /// заполнение массива
    for (int i = 0; i < lengthArray; i++)
    {
        cout << "Введите элемент массива: ";
        cin >> currentArray[i];
    }
    
    /// вызов самой функции
    quickSort(currentArray, 0, lengthArray - 1);
    
    cout << "\nМассив после сортировки:\n";
    for (int i = 0; i < lengthArray; i++) 
    {
        cout << "currentArray[" << i << "] = " << currentArray[i] << endl;
    }
    
    free(currentArray); // освобождение памяти
    return 0;
}