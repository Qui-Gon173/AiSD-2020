#include <iostream>

void print(int size, int *array)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(int size, int *array)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            int j = i;
            while (array[j] > array[j + 1])
            {
                int box = array[j];
                array[j] = array[j + 1];
                array[j + 1] = box;
                j--;
            }
        }
    }
    print(size, array);
}

int main()
{
    const int length = 10;
    int arr[length] = { 75, 51, 35, 82, 62, 45, 30, 20, 79, 100 };
    print(length, arr);
    InsertionSort(length, arr);
}

