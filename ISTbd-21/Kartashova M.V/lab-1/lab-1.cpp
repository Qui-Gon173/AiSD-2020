#include <iostream>
#include <ctime>
using namespace std;

int LineSearch(int Array[], int size, int key)
{
	int i;
	for (i = 0; i < size; i++)
		if (Array[i] == key) 
			return i;
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, size;
	int key, Array[1000];
	srand(time(NULL));
	cout << "Размер массива = "; 
	cin >> size;
	cout << "Искомый элемент (от 0 до 9) = "; 
	cin >> key;
	cout << "Исходный массив: ";
	for (i = 0; i < size; i++)
	{
		Array[i] = rand() % 10;
		cout << Array[i] << " ";
	}
	if (LineSearch(Array, size, key) == -1) cout << "\nЭлемент не найден";
	else cout << "\nНомер элемента: " << LineSearch(Array, size, key) + 1 << endl;
	system("pause");
}
