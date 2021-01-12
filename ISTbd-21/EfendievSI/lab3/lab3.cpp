#include <iostream>

void print(int size, int* array)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int QuickSort(int *array, int left, int right)
{
    int l = left;
    int r = right;
    int p = (left + right) / 2;

    while (l <= r)
    {
        while (array[l] < array[p]) l++;
        while (array[r] > array[p]) r--;
        if (l <= r)
        {
            int box = array[l];
            array[l] = array[r];
            array[r] = box;
            l++;
            r--;
        }
        if (left < r) QuickSort(array, left, r);
        if (l < right) QuickSort(array, l, right);
    }
    return *array;
}

int main()
{
    const int length = 10;
    int arr[length] = { 40, 69, 40, 100, 23, 84, 98, 76, 79, 69 };

    print(length, arr);
    QuickSort(arr, 0, length - 1);
    print(length, arr);
}
