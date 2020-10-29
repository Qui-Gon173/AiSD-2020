#include <iostream>

using namespace std;

int main()
{
    /// текущий массив
    int currentArray[] = {-1, 2, 5, 3, -3, 5, 12, 9, 0, 6};

    int key = 9;          // инициализация "барьера" с установлением значения
    int lengthArray = 10; // длина массива

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
}
