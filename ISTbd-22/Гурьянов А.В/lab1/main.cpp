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

int linear_Search_With_Barrier(int array[], int nVar, int key)
{
    if (array[nVar - 1] == key)
        return nVar - 1;
    array[nVar - 1] = key;
    int keyIndex = 0;
    while (array[keyIndex] != key)
        keyIndex++;
    return (keyIndex < nVar - 1) ? keyIndex : -1;
}

int main()
{
    int nVar;
    cout << "Enter the number of array elements: ";
    cin >> nVar;
    int *array = new int[nVar];
    generate_Random_Array(array, nVar);
    cout << "Array: ";
    print_Array(array, nVar);
    int key;
    cout << "Enter key: ";
    cin >> key;
    int keyIndex = linear_Search_With_Barrier(array, nVar, key);
    if (keyIndex == -1)
        cout << "Key not found." << endl;
    else
        cout << "Key index: " << keyIndex << endl;
    return 0;
}