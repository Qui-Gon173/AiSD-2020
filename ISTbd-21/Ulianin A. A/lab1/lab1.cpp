#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int lengthArray; // длина массива

    cout << "Введите количество элементов массива: ";
    cin >> lengthArray;

    /// текущий массив
    int* currentArray = (int*)malloc(lengthArray * sizeof(int)); // выделение памяти

    int key;          // инициализация "барьера"

    for (int i = 0; i < lengthArray; i++)
    {
        cout << "Введите элемент массива: ";
        cin >> currentArray[i];
        
    }

    cout << "Введите значение барьера: ";
    cin >> key;

     /// проверка последнего элемента на 'барьер'
    if (currentArray[lengthArray - 1] == key)
    {
        cout << "Последний элемент равен значению барьера. Его Индекс =  " << (lengthArray - 1) << endl;
        return 0;
    }

    /// присвоение ключа последнему элементу
    currentArray[lengthArray - 1] = key;

    int index = 0; // счётчик для перебора элементов массива

    /// подсчёт индекса
    while (currentArray[index] != key)
    {
        index++;
    }

    /// условие вывода
    if (index < lengthArray - 1)
    {
        cout << "Индекс элемента при котором массив встретился с 'барьером' = " << index << endl;
    }
    else
    {
        cout << "Такого элемента не нашлось!" << endl;
    }

    free(currentArray); // освобождение памяти
    return 0;
}

