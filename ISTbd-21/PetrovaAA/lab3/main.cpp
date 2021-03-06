// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#define SIZE 1000

int array[SIZE];
int size, diapazon;

void RandomArray(int array[], int size, int diapazon)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % diapazon;
	}
}

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

void QuickSort(int array[], int left, int right)
{
	int pivot; 
	int left_border = left; 
	int right_border = right; 

	pivot = array[left];
	while (left < right) 
	{
		while ((array[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			array[left] = array[right]; 
			left++; 
		}
		while ((array[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			array[right] = array[left]; 
			right--; 
		}
	}
	array[left] = pivot; 
	pivot = left;
	left = left_border;
	right = right_border;
	if (left < pivot) 
		QuickSort(array, left, pivot - 1);
	if (right > pivot)
		QuickSort(array, pivot + 1, right);
}



int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	std::cout << "АЛГОРИТМ БЫСТРОЙ СОРТИРОВКИ ХОАРА" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	std::cout << "Введите диапазон значений: ";
	std::cin >> diapazon;

	std::cout << "Исходный массив: ";

	RandomArray(array, size, diapazon);

	PrintArray(array, size);

	QuickSort(array, 0, size-1);

	std::cout << "Исходный массив: ";

	PrintArray(array, size);

    return 0;
}

