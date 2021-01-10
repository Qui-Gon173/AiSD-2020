#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	cout << "vvedite massiv is 10 elementov:" << endl;
	const int n = 10;
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Massiv: \n";
	for (i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}
	int temp;
	int j;
	//Сортировка методом пузырьк
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
	cout << "\nSortirovka: \n";
	for (i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}
}