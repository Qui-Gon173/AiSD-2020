// lab4.cpp: определяет точку входа для консольного приложения.
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

void CreatingHeap(int array[], int root, int bottom)
{
	int maximum; 
	int flag = 0; 
				  
	while ((root * 2 <= bottom) && (!flag))
	{
		if (root * 2 == bottom)    
			maximum = root * 2;    
									
		else if (array[root * 2] > array[root * 2 + 1])
			maximum = root * 2;
		else
			maximum = root * 2 + 1;
		
		if (array[root] < array[maximum])
		{
			int temp = array[root];
			array[root] = array[maximum];
			array[maximum] = temp;
			root = maximum;
		}
		else
			flag = 1; 
	}
}
void HeapSorting(int array[], int size)
{

	for (int i = (size / 2) - 1; i >= 0; i--)
		CreatingHeap(array, i, size - 1);

	for (int i = size - 1; i >= 1; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		CreatingHeap(array, 0, i - 1);
	}
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

	HeapSorting(array, size);

	std::cout << "Отсортированный массив: ";

	PrintArray(array, size);

    return 0;
}

