#include <iostream>
#include <ctime>

using namespace std;
const int length = 10;

void PrintArray(int *array) {
    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int CreateArray(int *array) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 9 + 1;
    }
    return *array;
}

void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
          // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}

void heapSort(int* numbers, int array_size)
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int main()
{
    int array[length];
    CreateArray(array);
    PrintArray(array);
    heapSort(array, 10);
    PrintArray(array);
    return 0;
}