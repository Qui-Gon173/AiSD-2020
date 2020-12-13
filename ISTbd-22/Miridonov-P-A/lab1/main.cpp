#include <iostream>
#include <conio.h>

using namespace std;

int main()
{

    setlocale(LC_ALL, "ru-RU");
    // задаем массив и числа
    const int n = 15; // задаем размерность массива
    int array[n] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int a = 0;
    //вывод массива
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        cout << " || ";
    }
    int number = 9; // задаем переменную для поиска нужного числа.
    if (number > n) // проверка от неправильного ввода числа
    {
        cout << "Задайте корректное число!" << endl;
        return 0;
    }
    else {
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] == number) // делаем проверку, равен ли наш массив к переменной  got
        {
            array[a++] = i;
        }
    }
    if (a != 0) // делаем проверку на совпадение нужного нам индекса массива.
    {
        for (int i = 0; i < a; i++)
        {
            cout << "\nЧисло " << number << " с индексом в массиве: " << array[i] << endl;
        }
    }
    else {
        cout << "Массив не найден" << endl;
    }
    return 0;
}
