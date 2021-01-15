#include <iostream>

using namespace std;

void heap(int arr[], int n, int i)
{
    int largest = i;   

    int left = 2*i + 1;
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}


int main()
{

    setlocale(LC_ALL, "rus");

    int array[] = { 8, 6, 36, 1, 4, 9 };
    int n = sizeof(array)/sizeof(array[0]);

    heapSort(array, n);

    cout << "\nМассив после сортировки:\n";
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << " | ";
    }
    cout << endl;
    return 0;
    system("pause");
  
}