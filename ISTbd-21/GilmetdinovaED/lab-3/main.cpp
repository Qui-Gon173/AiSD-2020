#include <iostream>

using namespace std;

void Hoar_sort(int* massiv, int first, int last)
{

	int i = first, j = last;//указатель на начало и конец массива
	int tmp = 0; // буфер обмена
	int x = massiv[(first + last) / 2];//опорный элемент

   //сортировка
	do {
		while (massiv[i] < x)//начиная с 1 элемента сравниваются значения с центральным элементом
			i++;
		while (massiv[j] > x)//начиная с последнего элемента сравниваются значения с центральным элементом
			j--;

		if (i <= j) // обмен элементов
		{
				tmp = massiv[i];
				massiv[i] = massiv[j];
				massiv[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)// Рекурсивно вызываем сортировку для левой и правой части массива
		Hoar_sort(massiv, i, last);
	if (first < j)
		Hoar_sort(massiv, first, j);
}
int main()
{
	int sizeArr;
	cout << "Enter the size of the array:" << endl;
	cin >> sizeArr;
	int* arr = new int[sizeArr];
	cout << "Enter the array elements:" << endl;
	for (int i = 0; i < sizeArr; i++)
	{
		cin >> arr[i];
	}
	Hoar_sort(arr, 0, sizeArr - 1);
	 cout << "Result: ";
	 for (int j = 0; j < sizeArr; j++)
	 {
		 cout << arr[j] << " ";
	 }
	 cout << endl;

	return 0;
}
