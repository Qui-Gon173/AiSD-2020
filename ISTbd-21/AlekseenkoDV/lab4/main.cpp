#include <iostream>

using namespace std;

void SiftingDown(int array[], int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root*2 <= bottom) && (!done))
    {
        if (root*2 == bottom)
            maxChild = root*2;
        else if (array[root*2] > array[root*2 + 1])
            maxChild = root*2;
        else
            maxChild = root * 2 + 1;
        if (array[root] < array[maxChild])
        {
            int tmp = array[root];
            array[root] = array[maxChild];
            array[maxChild] = tmp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heapSort(int array[], int size)
{
    for (int i = (size/2) - 1; i >= 0; i--)
        SiftingDown(array, i, size - 1);
    for (int i = size - 1; i >= 0; i--)
    {
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        SiftingDown(array, 0, i - 1);
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

int main()
{
    const int SIZE = 7;
    int array[SIZE] = {3, 6, 7, 5, 3, 5, 6};
    cout << endl << "Не отсортированный массив: ";
    PrintArray(array, SIZE);
    heapSort(array, SIZE);
    cout << endl << "Отсортированный массив: ";
    PrintArray(array, SIZE);
    return 0;
}