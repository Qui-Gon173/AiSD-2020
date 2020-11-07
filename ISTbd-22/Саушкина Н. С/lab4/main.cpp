#include <iostream>
#include <math.h>
using namespace std;
void HeapSort(int* arr, int k) {
	for ( k; k >= 2; k--)
	{
		for (int i = k; i >= 2; i--)
		{
			if (i % 2 == 1)
			{
				if (arr[i - 1] < arr[(i - 1) / 2 - 1])
				{
					int tmp = arr[i - 1];
					arr[i - 1] = arr[(i - 1) / 2 - 1];
					arr[(i - 1) / 2 - 1] = tmp;
				}
			}
			else
			{
				if (arr[i - 1] < arr[i / 2 - 1])
				{
					int tmp = arr[i - 1];
					arr[i - 1] = arr[i / 2 - 1];
					arr[i / 2 - 1] = tmp;
				}
			}
		}
		int tmp = arr[k-1];
		arr[k - 1] = arr[0];
		arr[0] = tmp;

	}
	return;
}

int main() {
	int n;
	cout << "enter the size of the array:" << endl;
	cin >> n;
	int* arr = new int[n];
	cout << "enter the array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		int digit;
		cin >> digit;
		arr[i] = digit;
	}
	HeapSort(arr, n);
	
	cout << "result: ";
	for (int j = 0; j < n; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}