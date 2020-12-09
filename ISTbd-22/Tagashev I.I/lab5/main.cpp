#include <fstream>
#include <iostream>

using namespace std;

void merge(int* a, int l, int m, int r)
{
    int i, j, k;
    int lsize = m - l + 1, rsize = r - m;
    int* left_array = new int[lsize];
    int* right_array = new int[rsize];

    for (i = 0; i < lsize; ++i)
        left_array[i] = a[l + i];
    for (j = 0; j < rsize; ++j)
        right_array[j] = a[m + 1 + j];

    i = 0, j = 0, k = l;

    while (i < lsize && j < rsize) {
        if (left_array[i] <= right_array[j])
            a[k++] = left_array[i++];
        else
            a[k++] = right_array[j++];
    }

    while (i < lsize)
        a[k++] = left_array[i++];
    while (j < rsize)
        a[k++] = right_array[j++];

}


void mergesort(int* a, int l, int r)
{
    if (l >= r)
        return;

    int m = (r + l) / 2;

    mergesort(a, l, m);
    mergesort(a, m + 1, r);

    merge(a, l, m, r);
}

void printArray(int* a, int len) {
    for (int i = 0; i < len; i++)
        cout << a[i] << "  ";
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("input.txt");
    int count;
    fin >> count;
    cout << "Количество элементов: " << count << '\n';
    int* array = new int[count];
    for (int i = 0; i < count; ++i)
        fin >> array[i];
    cout << "Первоначальный массив: " << '\n';
    printArray(array, count);
    mergesort(array, 0, count - 1);
    cout << "Отсортированный массив: " << '\n';
    printArray(array, count);
    delete[] array;
    return 0;
}