#include <iostream>

using namespace std;


int parent(int i) {
	return i / 2;
}

int left(int i) {
	return (2 * i + 1);
}

int right(int i) {
	return (2 * i + 2);
}

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

void build_max_heap(int array[], int size) {
	for (int i = size / 2; i >= 0; --i) {
		max_heapify(array, size, i);
	}
}

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

int main() {
	setlocale(LC_ALL, "Russian");
	int size = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	int array[50] = {};
	cout << "Введите элементы массива: ";
	for (int i = 0; i != size; ++i)
		cin >> array[i];
	cout << "Введите элементы массива: ";
	heap_sort(array, size);
	for (int i = 0; i != size; ++i)
		cout << array[i] << ' ';
	cout << "\n";
	return 0;
}