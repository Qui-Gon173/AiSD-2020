#include <iostream>
#include <ctime>
using namespace std;


void creatPiramid(int array[], int size, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; //  2*i + 1 - левый
	int r = 2 * i; //  2*i - правый 

 // Если левый дочерний элемент больше корня
	if (l < size && array[l] > array[largest])
		largest = l;

	// Если правый дочерний элемент больше самого большого элемента сейчас
	if (r < size && array[r] > array[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(array[i], array[largest]);

		// Рекурсивно преобразуем до конца данное поддерево
		creatPiramid(array, size, largest);
	}
}

void piramidSort(int array[], int size)
{
	// Перегруппируем массив
	for (int i = size/2 - 1; i >= 0; i--)
		creatPiramid(array, size, i);
 
	// Просеиваем сквозь пирамиду
	for (int i = size - 1; i >= 0; i--)
	{
		swap(array[0], array[i]);
		creatPiramid(array, i, 0);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[1000], size;
	srand(time(0));
	cout << "Кол-во элементов массива = ";
	cin >> size;
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
		cout << array[i] << " ";
	}
	piramidSort(array, size);
	cout << endl << "Отсортированный массив: " ;
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	system("pause");
}

