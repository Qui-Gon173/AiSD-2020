#include <iomanip>
#include <iostream>
using namespace std;

void ArrayRandFill(int array[], int amount)
{
    srand((unsigned)time(0));
    for (int i = 0; i < amount; i++)
    {
        array[i] = rand() % 10;
    }
}

void ArrayOut(int array[], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Heap(int array[], int amount, int i)
{
    int largestElement = i;

    int a = 2 * i + 1;
    int b = 2 * i + 2;

    if ((a < amount) && (array[a] > array[largestElement])) largestElement = a;

    if ((b < amount) && (array[b] > array[largestElement])) largestElement = b;

    if (largestElement != i)
    {
        swap(array[i], array[largestElement]);
        Heap(array, amount, largestElement);
    }
}

void HeapSort(int array[], int amount)
{
    for (int i = amount / 2 - 1; i >= 0; i--)
        Heap(array, amount, i);

    for (int i = amount - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        Heap(array, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int amount;

    cout << "Введите количество элементов в массиве: ";
    cin >> amount;

    int* Array = new int[amount];

    ArrayRandFill(Array, amount);

    cout << "Массив: ";
    ArrayOut(Array, amount);

    HeapSort(Array, amount);

    cout << "Отсортированный массив: ";
    ArrayOut(Array, amount);
}