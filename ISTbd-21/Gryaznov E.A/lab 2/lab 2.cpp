#include <iostream>
#include <time.h>


using namespace std;

void InsertSort(int size, int massiv[])
{
	int i, j, temp;
	for (i = 0; i < size; i++)
	{
		temp = massiv[i];
		for (j = i - 1; j >= 0 && massiv[j] > temp; j--)
			massiv[j + 1] = massiv[j];
		massiv[j + 1] = temp;
	}
	cout << "\nОтсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		cout << massiv[i] << " ";
	}
	cout << "\n";
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	int massiv[100];
	int size;
	srand(time(0));
	cout << "Количество элементов: ";
	cin >> size;
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++)
	{
		massiv[i] = rand() % 10;
		cout << massiv[i] << " ";
	}
	InsertSort(size, massiv);

	system("pause");
}