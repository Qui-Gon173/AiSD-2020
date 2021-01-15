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

void quickSort(int *a, int left, int right)
{
	int i, j, middle, tmp;
	i = left;
	j = right;
	middle = a[(i + j + 1) / 2];
	do 
	{
		while (a[i] < middle)
			i++;
		while (a[j] > middle)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}

int main()
{
	int array[ARRAY_SIZE];

	fill(array);
	
	cout << "Initial array: ";
	print(array);

	quickSort(array, 0, ARRAY_SIZE - 1);

	cout << "\n\nQuick-sorted array: ";
	print(array);


	return EXIT_SUCCESS;
}

