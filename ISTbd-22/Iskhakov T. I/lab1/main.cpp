#include <iostream>

using namespace std;

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int LinearSearchWithBarrier(int array[], int size, int key)
{
    if (array[size - 1] == key)
        return size - 1;
    array[size - 1] = key;
    int keyNumber = 0;
    while (array[keyNumber] != key)
        keyNumber++;
    return (keyNumber < size - 1) ? keyNumber : -1;
}

int main()
{
    const int SIZE = 6;
    int Array[SIZE] = {4, 2, 71, 39, 26, 5};
    int key;
    PrintArray(Array, SIZE);
    cout << endl;
    cout << "Enter the key: ";
    cin >> key;
    int keyNumber = LinearSearchWithBarrier(Array, SIZE, key);
    if (keyNumber == -1)
        cout << " There is no such key" << endl;
    else
        cout << " The key has " << keyNumber << " number." << endl;
    return 0;
}