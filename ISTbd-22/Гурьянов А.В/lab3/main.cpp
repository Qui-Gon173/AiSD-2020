#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate_Random_Array(int array[], int nVar)
{
    srand((unsigned)time(0));
    for (int i = 0; i < nVar; i++)
    {
        array[i] = rand() % 10;
    }
}

void print_Array(int array[], int nVar)
{
    for (int i = 0; i < nVar; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void quicksort(int array[], int nVar, int left, int right)
{
    int i, j, middle, temp;
    i = left;
    j = right;
    middle = array[(i+j+1)/2];
    do {
        while (array[i] < middle)
            i++;
        while (array[j] > middle)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
            temp = 0;
        }
    } while (i <= j);
    if (left < j)
        quicksort(array, nVar, left, j);
    if (i < right)
        quicksort(array, nVar, i, right);
}

int main()
{
    int nVar;
    cout << "Enter the number of array elements: ";
    cin >> nVar;
    int *array = new int[nVar];
    generate_Random_Array(array, nVar);
    cout << "Initial array: ";
    print_Array(array, nVar);
    cout << "Quicksorting..." << endl;
    quicksort(array, nVar, 0, nVar - 1);
    cout << "Qucksorted array: ";
    print_Array(array, nVar);
    return 0;
}