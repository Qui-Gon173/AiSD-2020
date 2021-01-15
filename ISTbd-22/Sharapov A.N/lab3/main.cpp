#include <iostream>

using namespace std;

void hoarSort(int array[], int first, int last)
{

    int left = first, right = last;
    double tmp, x = array[(first + last) / 2];

    do {
        while (array[left] < x)
            left++;
        while (array[right] > x)
            right--;

        if (left <= right)
        {
            if (left < right)
            {
                tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
            }
            left++;
            right--;
        }
    } while (left <= right);

    if (left < last)
        hoarSort(array, left, last);
    if (first < right)
        hoarSort(array, first, right);
}


int main()
{
    setlocale(LC_ALL, "rus");

    int size = 0;
    cout << "Размер массива: ";
    cin >> size;
    int* array = new int[size];

    for (int i = 0; i < size; i++)
        cin >> array[i];

    hoarSort(array, 0, size - 1);

    cout << "\nМассив после сортировки:\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " | ";
    }
    cout << endl;
    return 0;
    system("pause");
    
}

