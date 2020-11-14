#include <iostream>

using namespace std;

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}


void SelectionSort(int array[], int size)
{
	int minIndex, temp;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}

int main()
{
	const int SIZE = 10;
	int array[SIZE] = {12, 44, 59, 3, 16, 40, 97, 24, 0, -1};
	PrintArray(array, SIZE);
	SelectionSort(array, SIZE);
	cout << " After using sort " << endl;
	PrintArray(array, SIZE);
	return 0;
}
