#include <iostream>
#include <ctime>

#define MIN_ELEM -100
#define MAX_ELEM 100

using namespace std;

void BubbleSort(int *x, int size)
{
    int tmp;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (x[j] > x[j + 1])
            {
                tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
    }
    cout << "Sorted array\n\n";
    for (int i = 0; i < size; i++)
        cout << x[i] << " ";
    cout << endl << endl;
}

int BinarySearch(int *x, int size, int key)
{
    BubbleSort(x, size);
    bool found = false;
    int upBorder = size - 1, lowBorder = 0;
    int middle = (upBorder + lowBorder) / 2;
    while (!found && upBorder >= lowBorder)
    {
        if (key == x[middle])
            found = true;
        else if (key < x[middle])
            upBorder = middle - 1;
        else
            lowBorder = middle + 1;
        middle = (upBorder + lowBorder) / 2;
    }
    return found ? middle : -1;
}

int main()
{
    srand(time(0));
    int key, result, size;
    //
    // Ввод размера массива
    //
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
    //
    // Заполнение массива
    //
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = MIN_ELEM + rand() % (MAX_ELEM - MIN_ELEM);
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    //
    // Ввод ключа поиска
    //
    cout << "Input key element: ";
    cin >> key;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Input error! Repeat input: ";
        cin >> key;
    }
    cout << endl << endl;
    //
    // Вывод результата
    //
    result = BinarySearch(arr, size, key);
    if (result != -1)
        cout << "The key element is at " << result << " position in the sorted array\n";
    else
        cout << "Element is not found\n";
    delete []arr;
    system("pause");
    return 0;
}

