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
	cout << "\x1b[32mВведённый массив пользователем:  \x1b[0m";
	vivod(count, array);
	int last = count - 1;
	sortXoapa(array, last);
	cout << "\x1b[32mОтсортированный массив пользователем:  \x1b[0m";
	vivod(count, array);
}
