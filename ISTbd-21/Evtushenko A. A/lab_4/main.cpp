#include <iostream>

void filling_array(int* array, int n) {
	std::cout << "Filling Array:\n";
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}
	std::cout << std::endl;
}


void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1; //лев
	int r = 2 * i + 2; //прав

	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	//строим кучку
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	//уменьшаем кучку
	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void cout_array(int* array, int n) {
	std::cout << "Sorted array:\n";
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int* my_array = new int[50];
	int count;
	std::cout << "Enter the number of values: ";
	std::cin >> count;
	filling_array(my_array, count);
	heapSort(my_array, count);
	cout_array(my_array, count);
}