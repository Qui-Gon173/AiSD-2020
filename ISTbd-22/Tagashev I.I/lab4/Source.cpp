#include <iostream>

using namespace std;

//Возврат индекса родителя узла
int parent(int i) {
	return i / 2;
}
//Возврат левого дочернего узла
int left(int i) {
	return (2 * i + 1);
}
//Возврат правого дочернего узла
int right(int i) {
	return (2 * i + 2);
}
//Свойства пирамиды
void max_heapify(int array[], int size, int i) {
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
		max_heapify(array, size, largest);
	}
}
//Построение пирамиды
void build_max_heap(int array[], int size) {
	for (int i = size / 2; i >= 0; --i) {
		max_heapify(array, size, i);
	}
}
//Пирамидальная сортировка
void heap_sort(int array[], int size) {
	build_max_heap(array, size);
	for (int i = size - 1; i >= 0; --i) {
		array[i] += array[0];
		array[0] = array[i] - array[0];
		array[i] -= array[0];
		size -= 1;
		max_heapify(array, size, 0);
	}
}
//Основная функция
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "\x1b[33mЛабораторная работа №4 \x1b[32m \n Выполнил студент гр. ИСТбд-22\x1b[33m \n Тагашев Иван\x1b[32m \n Проверил преподаватель\x1b[33m \n Смеречинский Сергей Орестович\n\x1b[0m";
	cout << "\x1b[33mЗадание: \n \x1b[34m Реализовать пирамидальный алгоритм сортировки.\n"; 
	int size = 0;
	cout << "\x1b[32mВведите размер массива: \x1b[32m";
	cin >> size;
	int array[50] = {};
	cout << "\x1b[32mВведите элементы массива: \x1b[32m";
	for (int i = 0; i != size; ++i)
		cin >> array[i];
	cout << "\x1b[32mВведите элементы массива: \x1b[32m";
	heap_sort(array, size);
	for (int i = 0; i != size; ++i)
		cout << array[i] << ' ';
	cout << "\n\x1b[0m";
	return 0;
}