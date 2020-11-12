#include <iostream>
#include <clocale>

using namespace std;

/// функция обмена значений двух аргументов
void change(int* array, int firstIndex, int secondIndex) {
	int supportElem = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = supportElem;
}

/// просеивание
void heap(int *a, int i, int n)
{
	int max = i; // инициализация наибольшего корня

	while (true)
	{
		int child = 2 * i + 1; // левый потомок

		 // если левый дочерний элемент больше корня
		if (child < n && a[child] > a[max])
		{
			max = child;
		}

		child++; // правый потомок (2 * i + 2)

		// если правый дочерний элемент больше "нового" корня
		if (child < n && a[child] > a[max])
		{
			max = child;
		}
		
		/// проверяем требуется ли вызов функции "change"
		if (max == i)
		{
			break;
		}
		else
		{
			change(a,max,i);
			max = i;
		}
	}
}

/// пирамидная сортировка
void heapsort(int *a, int n)
{
	/// построение "кучи" (перегруппируем массив)
	for (int i = n / 2; i >= 0; i--)
	{
		heap(a, i, n);
	}

	/// один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 1; i--) 
	{
		/// перемещаем текущий корень в конец
		change(a, 0, i);

		/// вызываем процедуру heap на уменьшенной куче
		heap(a, 0, i);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int lengthArray; // длина массива

	cout << "Введите количество элементов массива: ";
	cin >> lengthArray;

	/// текущий массив
	int* currentArray = (int*)malloc(lengthArray * sizeof(int)); // выделение памяти

	/// заполнение массива
	for (int i = 0; i < lengthArray; i++)
	{
		cout << "Введите элемент массива: ";
		cin >> currentArray[i];
	}

	cout << "\nИсходный массив:\n";
	for (int i = 0; i < lengthArray; i++)
	{
		cout << "currentArray[" << i << "] = " << currentArray[i] << endl;
	}

	/// вызов самой функции
	heapsort(currentArray, lengthArray);

	cout << "\nМассив после сортировки:\n";
	for (int i = 0; i < lengthArray; i++)
	{
		cout << "currentArray[" << i << "] = " << currentArray[i] << endl;
	}

	free(currentArray); // освобождение памяти
	return 0;
}