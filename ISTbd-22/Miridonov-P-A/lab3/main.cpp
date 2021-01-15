#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void ArrayFill(int count, int array[])
{
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
    }
}


void ArrayOut(int count, int array[])
{
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void HoareSort(int array[], int last)
{
    int i = 0, j = last, center;
    center = array[last >> 1];

    do {
        while (array[i] < center) i++;
        while (array[j] > center) j--;

        if (i <= j)
        {
            swap(array[i], array[j]);
            i++; j--;
        }
    } while (i <= j);
    if (j > 0) HoareSort(array, j);
    if (last > i) HoareSort(array + i, last - i);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int array[20];
    int n;
    int left = 0, element;
    cout << " Введите количество элементов массива:   ";
    cin >> n;
    int right = n;
    cout << " Введите элементы массива:   ";
    ArrayFill(n, array);
    cout << " Массив:   ";
    ArrayOut(n, array);
    int last = n - 1;
    HoareSort(array, last);
    cout << " Отсортированный массив пользователем:   ";
    ArrayOut(n, array);
}