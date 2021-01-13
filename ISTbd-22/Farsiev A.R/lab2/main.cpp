#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    int key;
    int i, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;
    int arr[1000];

    cout << "size (< 1000): ";
    cin >> size;
    cout << "array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    
    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
