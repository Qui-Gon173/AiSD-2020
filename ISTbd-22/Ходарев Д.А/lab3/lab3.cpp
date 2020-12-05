#include <iostream>
#include <ctime>

using namespace std;

const int length = 10;

// Инициализация массива.
int valuesArray(int* array) {
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 9 + 1;
	}
	return *array;
}

// Вывод массива.
void coutArray(int* array) {
	cout << endl;
	cout << "Массив: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// Быстрая сортировка.
int quickSort(int *array, int first_index, int last_index) {
	int first = first_index, last = last_index;
	int pivot = rand() % (length - 1) + 1;

	while (first <= last) {
		while (array[first] < array[pivot]) first++;
		while (array[last] > array[pivot]) last--;
		if (first <= last) {
			int box = array[first];
			array[first] = array[last];
			array[last] = box;
			first++;
			last--;
		}
		if (first_index < last) quickSort(array, first_index, last);
		if (first < last_index) quickSort(array, first, last_index);
	}

	return *array;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int array[length];

	valuesArray(array);
	coutArray(array);
	quickSort(array, 0, length - 1);
	coutArray(array);
	return 0;
}