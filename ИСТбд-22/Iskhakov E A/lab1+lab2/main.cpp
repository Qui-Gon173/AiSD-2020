#include <iostream>

void filling_Array(int my_array[], int countVars) {
	for (int i = 0; i < countVars; i++) {
		std::cin >> my_array[i];
	}
}

void cout_Array(int my_array[], int countVars) {
	for (int i = 0; i < countVars; i++) {
		std::cout << my_array[i] << " ";
	}
	std::cout << "\n";
}

void insert_Sort(int my_array[], int countVars)
{
	for (int i = 0; i < countVars - 1; i++) {
		int temp_index = i + 1;
		int temp_value = my_array[temp_index];
		for (int j = i + 1; j > 0; j--) {
			if (my_array[j - 1] > temp_value) {
				my_array[j] = my_array[j - 1];
				temp_index = j - 1;
			}
		}
		my_array[temp_index] = temp_value;
	}
}

int binary_Search(int my_array[], int count, int key) {
	int left_index = 0;
	int right_index = count;
	int middle_index = 0;
	while (1) {
		middle_index = (left_index + right_index) / 2;
		if (key < my_array[middle_index]) {
			right_index = middle_index - 1;
		}
		else if (key > my_array[middle_index]) {
			left_index = middle_index + 1;
		}
		else {
			return middle_index;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int my_array[100];
	int countVar;
	std::cout << "Количество переменных = ";
	std::cin >> countVar;
	std::cout << "Заполнение массива: \n";
	filling_Array(my_array, countVar);
	int key;
	std::cout << "Найти число ";
	std::cin >> key; 
	std::cout << "\n" << "Первоначальный массив" << "\n";	
	cout_Array(my_array, countVar);
	insert_Sort(my_array, countVar);
	std::cout << "Отсортированный массив" << "\n";
	cout_Array(my_array, countVar);
	std::cout << "Индекс найденного числа " << binary_Search(my_array, countVar, key);
	return 0;
}