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
	int array[20];
	int count;
	int left = 0, element;
	cout << "Введите кол-во элементов массива:  ";
	cin >> count;
	int rigth = count;
	cout << "Введите элементы массива:  ";
	zapolnenie(count, array);
	cout << "Введённый массив пользователем:  ";
	vivod(count, array);
	int last = count - 1;
	sortXoapa(array, last);
	cout << "Отсортированный массив пользователем:  ";
	vivod(count, array);
}