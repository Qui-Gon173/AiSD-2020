#include <iostream>
#include <limits>
using namespace std;

void QuickSearch(int* a, int first, int last)
{

	int i = first, j = last;
	int tmp, x = a[(first + last) / 2];

	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		QuickSearch(a, i, last);
	if (first < j)
		QuickSearch(a, first, j);
}
int main() {
	int n;
	cout << "Enter the size of the array:" << endl;
	cin >> n;
	int* arr = new int[n];
	cout << "Enter the array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		int digit;
		cin >> digit;
		arr[i] = digit;
	}
	QuickSearch(arr, 0, n - 1);
	 cout << "Result: ";
	 for (int j = 0; j < n; j++)
	 {
		 cout << arr[j] << " ";
	 }
	 cout << endl;
	 system("pause");
	return 0;
}