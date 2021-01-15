#include <iostream>
#include <ctime>
using namespace std;
int n, first, last;

void HoarSort(int array[], int first, int last)
{
	int base, tmp;
	int f = first, l = last;
	base = array[f]; 
	do
	{
		while (array[f] < base) f++;
		while (array[l] > base) l--;
		if (f <= l) 
		{
			tmp = array[f];
			array[f] = array[l];
			array[l] = tmp;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) HoarSort(array, first, l);
	if (f < last) HoarSort(array, f, last);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[1000];
	int n, first, last;
	srand(time(NULL));
	cout << "Кол-во элементов массива = ";
	cin >> n;
	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 10;
		cout << array[i] << " ";
	}
	first = 0; last = n - 1;
	HoarSort(array, first, last);
	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) 
		cout << array[i] << " ";
	system("pause");
}