#include <iostream>
#include <ctime>

using namespace std;

void ShowArray(int* arr, int size);
void RandomArray(int* arr, int size, int min, int max);

void BuildPyramid(int size, int maxIndex, int* arr);
void SortPyramid(int size, int* arr);
void Sifting(int left, int right, int* arr);
void Exchange(int i, int j, int* arr);

int main()
{
    srand(time(0));

    int size;
    cout << "Input array size: ";
    cin >> size;
    while (cin.fail() || size < 1)
    {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Input error! Repeat input: ";
        cin >> size;
    }
    cout << endl;

    int* arr = new int[size];
    RandomArray(arr, size, -100, 100);

    cout << "Sorted array:\n\n";
    BuildPyramid(size / 2 + 1, size - 1, arr);
    SortPyramid(size - 1, arr);

    ShowArray(arr, size);

    delete[] arr;
    system("pause");
    return 0;
}

void ShowArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void RandomArray(int* arr, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min);
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void BuildPyramid(int size, int maxIndex, int* arr)
{
    Sifting(size, maxIndex, arr);
    if (size > 0)
        BuildPyramid(size - 1, maxIndex, arr);
}


void SortPyramid(int size, int* arr)
{
    Exchange(0, size, arr);
    Sifting(0, size - 1, arr);
    if (size > 1)
        SortPyramid(size - 1, arr);
}

void Sifting(int left, int right, int* arr)
{
    int maxChild, current;
    maxChild = 2 * left + 1;
    current = maxChild + 1;
    if (maxChild <= right)
    {
        if (current <= right && arr[current] > arr[maxChild])
            maxChild = current;
        if (arr[left] < arr[maxChild])
        {
            Exchange(left, maxChild, arr);
            Sifting(maxChild, right, arr);
        }
    }
}

void Exchange(int i, int j, int* arr)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}