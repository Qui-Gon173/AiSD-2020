#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate_Random_Array(int array[], int nVar)
{
    srand((unsigned)time(0));
    for (int i = 0; i < nVar; i++)
        array[i] = rand() % 10;
}

void print_Array(int array[], int nVar)
{
    for (int i = 0; i < nVar; i++)
        cout << array[i] << " ";
    cout << endl;
}

void exchange(int array[], int i, int j)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sift(int array[], int left, int right)
{
    int l, r;
    l = 2 * left + 1;
    r = l + 1;
    if (l <= right) {
        if ((r <= right) && (array[r] > array[l]))
            l = r;
        if (array[left] < array[l])
        {
            exchange(array, left, l);
            sift(array, l, right);
        }
    }
}

void build_Heap(int array[], int nVar, int right)
{
    sift(array, nVar, right);
    if (nVar > 0)
        build_Heap(array, nVar - 1, right);
}

void sort_Heap(int array[], int nVar)
{
    exchange(array, 0, nVar);
    sift(array, 0, nVar - 1);
    if (nVar > 1)
        sort_Heap(array, nVar - 1);
}

void heapsort(int array[], int nVar)
{
    build_Heap(array, nVar / 2 + 1, nVar - 1);
    sort_Heap(array, nVar - 1);
}


int main()
{
    int nVar;
    cout << "Enter the number of array elements: ";
    cin >> nVar;
    int* array = new int[nVar];
    generate_Random_Array(array, nVar);
    cout << "Initial array: ";
    print_Array(array, nVar);
    cout << "Heapsorting..." << endl;
    heapsort(array, nVar);
    cout << "Heapsorted array: ";
    print_Array(array, nVar);
    return 0;
}