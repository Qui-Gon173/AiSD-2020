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

void Sort(int arr[], int array_length)
{
    if (!array_length) {
        return;
    }

    for (int i = 0; i < array_length - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < array_length; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }

        if (min_i != i) {
            swap(arr[i], arr[min_i]);
            min_i = i;
        }
    }
}

int DvSort(int arr[], int left, int rigth, int element)
{
	while (left <= rigth)
	{
		int m = (unsigned)left + ((unsigned)rigth - (unsigned)left) / 2;
		if (arr[m] == element)
			return m;
		else if (arr[m] < element)
			left = m + 1;
		else
			rigth = m - 1;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №1 (и №2) \n Выполнила студент гр. ИСТбд-22 \n Арсланова Эмилия\n Проверил преподаватель \n Смеречинский Сергей Орестович\n";
	cout << "Задание:\n 1) Реализовать алгоритм линейного поиска в массиве методом двоичного поиска (Вариант №3).  \n 2) Реализовать алгоритм сортировки методом перебора (Вариант №3). \n\n";
	int MyArr[20];
	int cnt;
	int left = 0, element;
	cout << "Введите кол-во элементов массива: ";
	cin >> cnt;
	int rigth = cnt;
	cout << "Введите элементы массива: ";
	Filling(cnt, MyArr);
	cout << "Введите элемент для поиска: ";
	cin >> element;
	cout << "Введённый массив пользователем:  ";
	Res(cnt, MyArr);
	Sort(MyArr, cnt);
	if (DvSort(MyArr, left, rigth, element) == -1)
	{
		cout << "Такого элемента не существует!\n";
	}
	else
	{
		cout << "Позиция элемента:  ";
		cout << DvSort(MyArr, left, rigth, element) << "\n";
	}
	cout << "Отсортированный массив пользователем:";
	Res(cnt, MyArr);
}

