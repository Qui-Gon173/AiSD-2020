#include <iostream>

int main()
{
	using namespace std;

	setlocale(LC_CTYPE, "rus");

	int massiv[] = { 3,7,11,10,9,12,2 };
	int key = 12;
	int count = 7;
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < count; i++)
	{

		cout << massiv[i] << " ";
	}
	if (massiv[count - 1] == key)
		return count - 1;
	massiv[count - 1] = key;
	int i = 0;
	while ((massiv[i] != key))
		i++;
	return(1 < count - 1) ? i : -1;
}