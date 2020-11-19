#include <iostream>

using namespace std;
void FillArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cin >> array[i];
	}
}

void ShowArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

int parent(int i) {
	return i / 2;
}

int left(int i) {
	return (2 * i + 1);
}

int right(int i) {
	return (2 * i + 2);
}

void max_pyramid(int array[], int size, int i) {
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l < size && array[l] > array[i])
		largest = l;
	else largest = i;
	if (r < size && array[r] > array[largest])
		largest = r;
	if (largest != i) {
		array[i] += array[largest];
		array[largest] = array[i] - array[largest];
		array[i] -= array[largest];
		max_pyramid(array, size, largest);
	}
}

void build_max_heap(int array[], int size) {
	for (int i = size / 2; i >= 0; --i) {
		max_pyramid(array, size, i);
	}
}

void heap_sort(int array[], int size) {
	build_max_heap(array, size);
	for (int i = size - 1; i >= 0; --i) {
		array[i] += array[0];
		array[0] = array[i] - array[0];
		array[i] -= array[0];
		size -= 1;
		max_pyramid(array, size, 0);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №3  \n Выполнила студентка гр. ИСТбд-22 \n Кучина Анна  \n Проверил преподаватель  \n Смеречинский Сергей Орестович\n---------------------------\n ";
	cout << " Задание: \n   Реализовать пирамидальный алгоритм сортировки.\n---------------------------\n";
	int size = 0;
	cout << " Введите размер массива:  ";
	cin >> size;
	int array[50] = {};
	cout << " Введите элементы массива:  ";
	FillArray(array, size);
	cout << " Введите элементы массива:  ";
	heap_sort(array, size);
	ShowArray(array, size);
	cout << "\n ";
	return 0;
}