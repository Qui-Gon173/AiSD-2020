#include <iostream>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 228;

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

int linearSearch(int* a, int key)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (a[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int array[ARRAY_SIZE], key, keyIndex;

	fill(array);
	
	cout << "Array: ";
	print(array);

	cout << "\nEnter the key [0, 227]: ";
	cin >> key;

	keyIndex = linearSearch(array, key);
	if (keyIndex != -1)
		cout << "\nThe key was found at the position " << keyIndex;
	else
		cout << "\nThe key was not found";


	return EXIT_SUCCESS;
}

