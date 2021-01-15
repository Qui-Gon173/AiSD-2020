
#include <iostream>
#include <ctime>

using namespace std;

//функция сортировки
void hoar(int* x, int first, int last)
{
	int mid; 
	int temp;
	int f = first;
	int l = last;
	mid = x[(f + l) / 2];
	do
	{
		while (x[f] < mid) 
			f++;
		while (x[l] > mid) 
			l--;
		if (f <= l) 
		{
			temp = x[f];
			x[f] = x[l];
			x[l] = temp;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) hoar(x, first, l);
	if (f < last) hoar(x, f, last);
}

int main()
{
	const int n = 10;
	int first; 
	int last;
	int* arr = new int[n];
	//srand(time(NULL));
	cout << "Massiv: \n";
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	first = 0; 
	last = n - 1;
	hoar(arr, first, last);
	cout << endl << "Sortirovka Hoara: \n";
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	} 
	delete[]arr;
	return 0;
}