#include <iostream>
#include <time.h>

using namespace std;
// Функция "просеивания" через кучу - формирование кучи
void Sifting(int *massiv, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду,
			maxChild = root * 2;    // запоминаем левый потомок
		  // иначе запоминаем больший потомок из двух
		else if (massiv[root * 2] > massiv[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (massiv[root] < massiv[maxChild])
		{
			int temp = massiv[root]; // меняем их местами
			massiv[root] = massiv[maxChild];
			massiv[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
// Функция сортировки на куче
void HeapSort(int *massiv, int size)
{
	// Формируем нижний ряд пирамиды
	for (int i = (size / 2) - 1; i >= 0; i--)
		Sifting(massiv, i, size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = size - 1; i >= 1; i--)
	{
		int temp = massiv[0];
		massiv[0] = massiv[i];
		massiv[i] = temp;
		Sifting(massiv, 0, i - 1);
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	int massiv[100];
	int size;
	srand(time(0));
	cout << "Количество элементов: ";
	cin >> size;
	
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++)
	{
		massiv[i] = rand() % 10;
		cout << massiv[i] << " ";
	}

	HeapSort(massiv, size); // вызов функции сортировки

	cout << "\nОтсортированный массив: ";
	for (int i = 0; i < size; i++)
		cout << massiv[i] << " ";
	cout << endl;

	return 0;
}
