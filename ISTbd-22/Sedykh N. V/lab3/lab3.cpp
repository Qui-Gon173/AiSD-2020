#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// функция заполнения массива "array" длиной "quantity" случайными числами 
void filling_array_random(int array[], int quantity)
{
    srand((unsigned)time(0));
    for (int i = 0; i < quantity; i++)
    {
        array[i] = rand() % 10;
    }
}

//функция вывода массива на экран
void array_output(int array[], int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void array_sortHoare(int* array, int left, int right)
{
    int pivot, count;
    int l = left, r = right;
    pivot = array[(l + r) / 2]; //вычисление основного(опорного) элемента
    do
    {
        while (array[l] < pivot) l++;
        while (array[r] > pivot) r--;
        if (l <= r)
        {
            count = array[l];
            array[l] = array[r];
            array[r] = count;
            l++;
            r--;
        }
    } while (l < r);
    if (left < r) {
        array_sortHoare(array, left, r);
    }
    if (l < right) {
        array_sortHoare(array, l, right);
    }
}
int main()
{
    int quantity;

    cout << "Enter the number of elements in the array: ";
    cin >> quantity;

    int* array = new int[quantity];

    filling_array_random(array, quantity);

    cout << "Array: ";
    array_output(array, quantity);

    array_sortHoare(array, 0, quantity - 1);

    cout << "Sorted array: ";
    array_output(array, quantity);
}
