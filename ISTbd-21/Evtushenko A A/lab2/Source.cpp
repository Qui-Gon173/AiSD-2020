#include <iostream>
using namespace std;
// Функция Шейкер-сортировки
void shackerSort(int* mass, int count)
{
	int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла, пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				double t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
			{           
				double t = mass[i];  // меняем их местами
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}
int main() {
	int my_array[10];
	// Вводим элементы массива
	for (int i = 0; i < 10; i++) {
		cout << "my_array[" << i << "] = ";
		cin >> my_array[i];
		cout << endl;
	}
	shackerSort(my_array, 10); // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		cout << my_array[i] << " ";
	return 0;
}