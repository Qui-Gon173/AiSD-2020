
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	cout << "vvedite massiv is 5 elementov:" << endl;
	const int n = 10;
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Massiv: \n";
	for (i = 0; i < n; i++) {
		cout << "arr["<<i<<"] = "<<arr[i] << "\n";
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

	//Бинарный поиск
	int a;
	cout << "\nvvedite iskombii element: ";
	cin >> a;

	int l = 0;
	int r = n - 1;
	int mid = (r + l) / 2;
	i = mid;
	bool flag = true;

	while (flag) {
		if (a == arr[mid]) {
			arr[i] = arr[mid];
			cout << "arr[" << mid << "] = " << arr[mid] << "\n";
			flag = false;
		}
		if (a < arr[mid]) {
			r = mid - 1;
			mid = (r + l) / 2;
			flag = true;
		}
		if (a > arr[mid]) {
			l = mid + 1;
			mid = (r + l) / 2;
			flag = true;
		}
	}
	for (i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}
}
