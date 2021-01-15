#include <iostream>

using namespace std;

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}

void SiftDown(int array[], int root, int bottom)
{
	int maxChild; 
	int done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    
			maxChild = root * 2;   
		else if (array[root * 2] > array[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (array[root] < array[maxChild])
		{
			int temp = array[root]; 
			array[root] = array[maxChild];
			array[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}


void HeapSort(int array[], int size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
		SiftDown(array, i, size - 1);
	for (int i = size - 1; i >= 1; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		SiftDown(array, 0, i - 1);
	}
}


int main()
{
	const int SIZE = 10;
	int array[SIZE] = { 12, 44, 59, 3, 16, 40, 97, 24, 0, -1 };
	PrintArray(array, SIZE);
	HeapSort(array, SIZE);
	cout << " After using sort " << endl;
	PrintArray(array, SIZE);
	return 0;
}
