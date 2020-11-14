#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void FillArray(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
}


void ShowArray(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void selection_sort(int array[], int array_length) {
	if (!array_length) {
		return;
	}

	for (int i = 0; i < array_length - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < array_length; j++) {
			if (array[j] < array[min_i]) {
				min_i = j;
			}
		}

		if (min_i != i) {
			swap(array[i], array[min_i]);
			min_i = i;
		}
	}
}

int BinarySearch(int array[], int left, int rigth, int element)
{
	while (left <= rigth)
	{
		int m = (unsigned)left + ((unsigned)rigth - (unsigned)left) / 2;
		if (array[m] == element)
			return m;
		else if (array[m] < element)
			left = m + 1;
		else
			rigth = m - 1;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №1 (№2) \n Выполнила студентка гр. ИСТбд-22 \n Кучина Анна\n Проверил преподаватель\n Смеречинский Сергей Орестович\n\n---------------------------\n";
	cout << "Задание: \n 1)Реализовать алгоритмы линейного поиска в массиве методами: линейный поиск, линейный поиск с барьером, двоичный поиск.\n Вариант №3  \n 2) Реализовать алгоритмы сортировки: методом пузырька, шейкер-сортировкой, методом перебора, методом вставок.\n Вариант №3 \n---------------------------\n";
	int array[20];
	int count;
	int left = 0, element;
	cout << "Введите кол-во элементов массива: ";
	cin >> count;
	int rigth = count;
	cout << "Введите элементы массива: ";
	FillArray(count, array);
	cout << "Введите элемент для поиска: ";
	cin >> element;
	cout << "Введённый массив пользователем: ";
	ShowArray(count, array);
	selection_sort(array, count);
	if (BinarySearch(array, left, rigth, element) == -1)
	{
		cout << "Такого элемента не существует!\n";
	}
	else
	{
		cout << "Позиция элемента: ";
		cout << BinarySearch(array, left, rigth, element) << "\n";
	}
	cout << "Отсортированный массив пользователем: ";
	ShowArray(count, array);
}
