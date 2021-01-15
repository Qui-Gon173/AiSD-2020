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

void swap(int* a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void sift(int* a, int left, int right)
{
	int l, r;
	l = 2 * left + 1;
	r = l + 1;
	if (l <= right)
	{
		if ((r <= right) && (a[r] > a[l]))
			l = r;
		if (a[left] < a[l])
		{
			swap(a, left, l);
			sift(a, l, right);
		}
	}
}

void makeHeap(int* a, int length, int right)
{
	sift(a, length, right);
	if (length > 0)
		makeHeap(a, length - 1, right);
}

void sortHeap(int* a, int length)
{
	swap(a, 0, length);
	sift(a, 0, length - 1);
	if (length > 1)
		sortHeap(a, length - 1);
}

void heapSort(int* a, int length)
{
	makeHeap(a, length / 2 + 1, length - 1);
	sortHeap(a, length - 1);
}

int main()
{
	int array[ARRAY_SIZE];

	fill(array);
	
	cout << "Initial array: ";
	print(array);

	heapSort(array, ARRAY_SIZE);

	cout << "\n\nHeap-sorted array: ";
	print(array);


	return EXIT_SUCCESS;
}

