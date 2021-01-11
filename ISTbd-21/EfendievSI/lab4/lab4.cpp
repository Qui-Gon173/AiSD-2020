#include <iostream>

void print(int size, int* array)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void SiftDown(int* array, int root, int bottom)
{
    int done = 0;
    int MaxChild;

    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            MaxChild = root * 2;
        else if (array[root * 2] > array[root * 2 + 1])
            MaxChild = root * 2;
        else
            MaxChild = root * 2 + 1;
        if (array[root] < array[MaxChild])
        {
            int temp = array[root]; 
            array[root] = array[MaxChild];
            array[MaxChild] = temp;
            root = MaxChild;
        }
        else
            done = 1;
    }
}

void HeapSort(int size, int* array)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        SiftDown(array, i, size - 1);
    }
    for (int i = size - 1; i >= 1; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        SiftDown(array, 0, i - 1);
    }
}

int main()
{
    const int length = 10;
    int arr[length] = { 41, 29, 46, 57, 23, 45, 62, 70, 88, 9 };
    print(length, arr);
    HeapSort(10, arr);
    print(length, arr);
}