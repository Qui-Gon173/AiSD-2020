#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int Array[], int size)
{
	int i, j, tmp, key;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			key = j + 1;
			if (Array[j] > Array[key])
			{
				tmp = Array[key];
				Array[key] = Array[j];
				Array[j] = tmp;
			}
		}
	}
	cout << "\nОтсортированный массив: ";
	for (i = 0; i < size; i++) 
		cout << Array[i] << " "; 
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int size, i;
	int Array[1000];
	srand(time(NULL));
	cout << "Количество элементов = ";
	cin >> size;

	cout << "Исходный массив: ";
	for (i = 0; i < size; i++) 
	{
		Array[i] = rand() % 10;
		cout << Array[i] << " ";
	}

	BubbleSort(Array, size);
	system("pause");
}