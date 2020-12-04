#include <iomanip>
#include <iostream>

using namespace std;

void filling_array_random(int array[], int quantity)
{
    srand((unsigned)time(0));
    for (int i = 0; i < quantity; i++)
    {
        array[i] = rand() % 10;
    }
}

void array_output(int array[], int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heap(int array[], int quantity, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if ((l < quantity) && (array[l] > array[largest])) largest = l;
    
    if ((r < quantity) && (array[r] > array[largest])) largest = r;

    if (largest != i)
    {
        swap(array[i], array[largest]);
        heap(array, quantity, largest);
    }
}

void sort_heap(int array[], int quantity)
{
    for (int i = quantity / 2 - 1; i >= 0; i--)
        heap(array, quantity, i);

    for (int i = quantity - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heap(array, i, 0);
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

    sort_heap(array, quantity);

    cout << "Sorted array: ";
    array_output(array, quantity);
}
