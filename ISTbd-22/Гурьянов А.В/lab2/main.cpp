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

void bubble_Sort(int array[], int nVar)
{
    int i, j, temp;
    for (i = 0; i < nVar; i++)
        for (j = 0; j < nVar - 1; j++)
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j]=array[j + 1];
                array[j + 1]=temp;
            }
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
    cout << "Bubble sorting..." << endl;
    bubble_Sort(array, nVar);
    cout << "Bubble sorted array: ";
    print_Array(array, nVar);
    return 0;
}