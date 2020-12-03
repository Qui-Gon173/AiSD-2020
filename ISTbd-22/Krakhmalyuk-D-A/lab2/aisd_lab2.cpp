#include <iostream>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 64;

void fill(int* a)
{
	srand(time(NULL));
	for (int i = 0; i < ARRAY_SIZE; i++)
		a[i] = rand() % 228;
}

void print(int* a)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << ' ';
}

void bubbleSort(int* a)
{
	int i, j, tmp;
	for (i = 1; i < ARRAY_SIZE; i++)
	{
		for (j = 0; j < ARRAY_SIZE - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main()
{
	int array[ARRAY_SIZE];

	fill(array);
	
	cout << "Initial array: ";
	print(array);

	bubbleSort(array);

	cout << "\n\nBubble-sorted array: ";
	print(array);


	return EXIT_SUCCESS;
}

