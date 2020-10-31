#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void zapolnenie(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
}


void vivod(int count, int array[])
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void sort(int array[], int count)
{
	int temp = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < (count - 1); i++)
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				exit = false;
			}
	}
}

int dvouka(int array[], int left, int rigth, int element)
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
	cout << "\x1b[33mЛабораторная работа №1 (№2)\x1b[32m \n Выполнил студент гр. ИСТбд-22\x1b[33m \n Тагашев Иван\x1b[32m \n Проверил преподаватель\x1b[33m \n Смеречинский Сергей Орестович\n\x1b[0m";
	cout << "\x1b[33mЗадание: \n \x1b[34m1)Реализовать алгоритмы линейного поиска в массиве методами: линейный поиск, линейный поиск с барьером, двоичный поиск.\n Вариант №3  \n 2) Реализовать алгоритмы сортировки: методом пузырька, шейкер-сортировкой, методом перебора, методом вставок.\n Вариант №1 \n\n\x1b[0m";
	int array[20];
	int count;
	int left = 0, element;
	cout << "\x1b[31mВведите кол-во элементов массива:  \x1b[0m";
	cin >> count;
	int rigth = count;
	cout << "\x1b[31mВведите элементы массива:  \x1b[0m";
	zapolnenie(count, array);
	cout << "\x1b[31mВведите элемент для поиска:  \x1b[0m";
	cin >> element;	
	cout << "\x1b[32mВведённый массив пользователем:  \x1b[0m";
	vivod(count, array);
	sort(array, count);
	if (dvouka(array, left, rigth, element) == -1)
	{
		cout << "Такого элемента не существует!\n";
	}
	else
	{
		cout << "\x1b[32mПозиция элемента:  \x1b[0m";
		cout << dvouka(array, left, rigth, element) << "\n";
	}
	cout << "\x1b[32mОтсортированный массив пользователем:  \x1b[0m";
	vivod(count, array);
}
