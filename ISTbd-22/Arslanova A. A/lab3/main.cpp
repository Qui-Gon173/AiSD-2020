#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void Filling(int cnt, int arr[])
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
}


void Res(int cnt, int arr[])
{
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void sortXoapa(int array[], int last)
    {
        int i = 0, j = last, temp, center;
        center = array[last >> 1];

    do {
        while (array[i] < center) i++;
        while (array[j] > center) j--;

        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++; j--;
        }
    }
    while (i <= j);
    if (j > 0) sortXoapa(array, j);
    if (last > i) sortXoapa(array + i, last - i);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №3 \n Выполнил студент гр. ИСТбд-22 \n Арсланова Эмилия\n Проверил преподаватель \n Смеречинский Сергей Орестович\n";
	cout << "Задание: Реализовать алгоритм сортировки методом Хоара.\n";
    int MyArr[20];
    int cnt;
    int element;
	cout << "Введите кол-во элементов массива: ";
	cin >> cnt;
	cout << "Введите элементы массива: ";
	Filling(cnt, MyArr);
	cout << "Введите элемент для поиска: ";
	cin >> element;
	cout << "Введённый массив пользователем:  ";
	Res(cnt, MyArr);
    int last = cnt - 1;
    sortXoapa(MyArr, last);
	cout << "Отсортированный массив пользователем:";
	Res(cnt, MyArr);
}
