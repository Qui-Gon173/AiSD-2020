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

void array_sort(int array[], int quantity)
{
    for (int i = 0; i < quantity; i++) 
    {
        int k = i;
        while (k > 0 && array[k - 1] > array[k]) {
            int  tmp = array[k - 1];
            array[k - 1] = array[k];
            array[k] = tmp;
            k -= 1;
        }
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

    array_sort(array, quantity);

    cout << "Sorted array: ";
    array_output(array, quantity);
}
