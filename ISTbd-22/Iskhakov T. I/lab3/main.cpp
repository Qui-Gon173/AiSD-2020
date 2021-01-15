#include <iostream>

using namespace std;

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}

void QuickSort(int array[], int first, int last)
{
	int i = first, j = last;
	int tmp;
	int x = array[(first + last) / 2];
	do {
		while (array[i] < x)
			i++;
		while (array[j] > x)
			j--;

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
		
	} while (i <= j);

	if (i < last)
		QuickSort(array, i, last);
	if (first < j)
		QuickSort(array, first, j);
}



int main()
{
	const int SIZE = 10;
	int array[SIZE] = { 42, -9, 15, 78, 2, 33, 90, 26, 65, 0 };
	PrintArray(array, SIZE);
	QuickSort(array, 0, SIZE - 1);
	cout << " After using sort " << endl;
	PrintArray(array, SIZE);
	return 0;
}