#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL,"ru");

    int lengthArray; // длина массива

    cout << "Введите количество элементов массива: ";
    cin >> lengthArray;

    /// текущий массив
    int* currentArray = (int*)malloc(lengthArray * sizeof(int)); // выделение памяти

    for (int i = 0; i < lengthArray; i++)
    {
        cout << "Введите элемент массива: ";
        cin >> currentArray[i];
    }

    int tmp = 0; // буфер обмена
    int left = 0; // левая граница
    int right = (lengthArray - 1); // правая граница

    /// выполнение цикла пока левая граница не сомкнётся с правой
    while (left < right)
    {
        /// двигаемся слева направо
        for (int i = left; i < right; i++)
        {
            ///если следующий элемент меньше текущего, меняем их местами
            if (currentArray[i] > currentArray[i + 1])
            {
                tmp = currentArray[i];
                currentArray[i] = currentArray[i + 1];
                currentArray[i + 1] = tmp;
            }
        }

        right--; // сдвигаем правую границу на предыдущий элемент

        /// двигаемся справа налево
        for (int i = right; i > left; i--)
        {
            ///если предыдущий элемент меньше текущего, меняем их местами
            if (currentArray[i - 1] > currentArray[i])
            {
                tmp = currentArray[i];
                currentArray[i] = currentArray[i - 1];
                currentArray[i - 1] = tmp;
            }
        }

        left++; // сдвигаем левую границу на следующий элемент
    }

    cout << "\nМассив после сортировки:\n";

    for (int i = 0; i < lengthArray; i++)
    {
        cout << "currentArray[" << i << "] = " << currentArray[i] << endl;
    }

    free(currentArray); // освобождение памяти
    return 0;
}