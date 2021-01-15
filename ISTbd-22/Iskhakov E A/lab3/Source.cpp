#include <iostream>

void filling_array(int* array, int n) {
	std::cout << "Filling Array:\n";
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}
	std::cout << std::endl;
}
	
void cout_array(int* array, int n) {
	std::cout << "Sorted array:\n";
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void sorting(int array[], int last)
{
	int i = 0, j = last, temp, center;
	center = array[last >> 1];

	do {
		while (array[i] < center) i++;
		while (array[j] > center) j--;

		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) sorting(array, j);
	if (last > i) sorting(array + i, last - i);
}

int main() {
	int count;
	std::cin >> count;
	int * my_array = new int [count];
	int left = 0, right = count;
	filling_array(my_array, count);
	int last = count - 1;
	sorting(my_array, last);
	cout_array(my_array, count);
}