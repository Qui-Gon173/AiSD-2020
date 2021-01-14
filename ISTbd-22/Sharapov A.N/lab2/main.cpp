#include <iostream>
using namespace std;


void swapElements(int arr[], int i) //ф-ция для обмена значений ячеек
{
    int buffer;
    buffer = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buffer;
}

void shakerSort(int arr[], int size) //ф-ция "шейкер"-сортировки
{
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if (arr[i - 1] > arr[i]) swapElements(arr, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
            if (arr[i - 1] > arr[i]) swapElements(arr, i);
        rightMark--;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int size = 0;
    cout << "Размер массива: ";
    cin >> size;
    int* array = new int[size];

    for (int i = 0; i < size; i++)
        cin >> array[i];
    

    shakerSort(array, size); // сортировка

    cout << "\nМассив после сортировки:\n";
    for (int i = 0; i < size; i++)
        {
            cout << array[i] << " | ";
        }
    cout << endl;
    return 0;
    system("pause");
}