#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция заполнения массива array длиной n случайными числами 
void ArrayRandFill(int array[], int n)
{
    srand((unsigned)time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }
}

//Функция вывода массива на экран
void ArrayOut(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
//Функция сортировки массива методом вставок
void ArraySort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        while (k > 0 && array[k - 1] > array[k]) {
            int  tmp = array[k - 1];
            array[k - 1] = array[k];
            array[k] = tmp;
            k -= 1;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;

    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    int* array = new int[n]; //Создание массива длиной n

    ArrayRandFill(array, n);

    cout << "Массив: ";
    ArrayOut(array, n);

    ArraySort(array, n);

    cout << "Отсортированный массив: ";
    ArrayOut(array, n);
}