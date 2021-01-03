#include <iostream>
#include <conio.h>

using namespace std;
void ArrayRandFill(int array[], int n)
{
    srand((unsigned)time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }
}
void ArrayOut(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}
int Search(int number, int n, int array[], int a)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == number) // делаем проверку, равен ли наш массив переменной number
        {
            array[a++] = i;
        }
    }
    if (a != 0) // делаем проверку на совпадение нужного нам индекса массива.
    {
        for (int i = 0; i < a; i++)
        {
            cout << "Число " << number << " с индексом в массиве: " << array[i] << endl;
        }
    }
    else {
        cout << "Число не найдено" << endl;
        return - 1;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 10;
    int array[n];
    int a = 0;
    int number;
    ArrayRandFill(array,n);
    cout << "Массив:"<<endl;
    ArrayOut(array, n);
    cout << "\nВведите число для поиска" << endl;
    cin >> number; // считываем число для поиска
    Search(number,n,array,a);
    return 0;
}
