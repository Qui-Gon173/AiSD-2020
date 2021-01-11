// аисд лаба 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void iswap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int main()
{
	int i;
	const int n = 7;
	int arr[n];
	srand(time(NULL));
	cout << "Massiv: \n";
	for (i = 0; i < n; i++)
	{
		arr[i] = rand()%100;
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	//Сортировка
	int step = 0;
	bool flag;

	while (step + 2 < n) {
		flag = false;
		for (i = 0; i < n; i++) {
			if (2 * i + 2 + step < n) {
				if ((arr[i + step] > arr[2 * i + 1 + step]) || (arr[i + step] > arr[2 * i + 2 + step])) {
					if (arr[2 * i + 1 + step] < arr[2 * i + 2 + step]) {
						swap(arr[i + step], arr[2 * i + 1 + step]);
						flag = true;
					}
					else {
						swap(arr[i + step], arr[2 * i + 2 + step]);
						flag = true;
					}

				}
				if (arr[i * 2 + 2 + step] < arr[i * 2 + 1 + step])
				{
					swap(arr[i * 2 + 1 + step], arr[i * 2 + 2 + step]);
					flag = true;
				}
			}
			else if (i * 2 + 1 + step < n)
			{
				if (arr[i + step] > arr[i * 2 + 1 + step])
				{
					swap(arr[i + step], arr[i * 2 + 1 + step]);
					flag = true;
				}

			}

			if (!flag) {
				step++;
			}

		}
	}

	cout << "sortirovka: \n";
	for (i = 0; i < n; i++) {

		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	i = 0;

}

