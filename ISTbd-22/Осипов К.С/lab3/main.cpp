#include <iostream>
#include <ctime>

#define MIN_ELEM -100
#define MAX_ELEM 100

using namespace std;

void QuickSort(int* arr, int left, int right)
{
    int i, j, middle, tmp;
    i = left;
    j = right;
    middle = arr[(i + j + 1) / 2];
    do 
    {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j) 
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

int main()
{
    srand(time(0));
    //
    // Ввод размера массива
    //
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
    // Сортировка массива
    //
    cout << "Sorted array:\n\n";
    QuickSort(arr, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    delete[] arr;
    system("pause");
	return 0;
}
