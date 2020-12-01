#include <iostream>
#include <time.h>

using namespace std;

void quickSort(int *massiv, int left, int right)
{
	int opornii;
	int i = left;
	int j = right;
	opornii = massiv[left];
	while (left < right)
	{
		while ((massiv[right] >= opornii) && (left < right))
			right--;
		if (left != right)
		{
			massiv[left] = massiv[right];
			left++;
		}
		while ((massiv[left] <= opornii) && (left < right))
			left++;
		if (left != right)
		{
			massiv[right] = massiv[left];
			right--;
		}
	}
	massiv[left] = opornii;
	opornii = left;
	left = i;
	right = j;
	if (left < opornii)
		quickSort(massiv, left, opornii - 1);
	if (right > opornii)
		quickSort(massiv, opornii + 1, right);
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

	quickSort(massiv, 0, size - 1);

	cout << "\nОтсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		cout << massiv[i] << " ";
	}
	cout << "\n";
	system("pause");
}