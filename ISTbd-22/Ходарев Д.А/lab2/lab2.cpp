#include <iostream>

using namespace std;

int main()
{
	const int length = 10;
	int arr[length] = { 1, 2, 3, 9, 8, 7, 4, 5, 6, 0 };

	// Метод пузырька.
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int x = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = x;
			}
		}
	}

	// Вывод массива.
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
