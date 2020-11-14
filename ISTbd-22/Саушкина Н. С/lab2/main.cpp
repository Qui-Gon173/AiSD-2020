#include <iostream>
#include <limits>
using namespace std;
void MethodSearch(int *x, int k) {
	for (int j = 0; j < k; j++) {
		int min = x[j], index = j;
		for (int i = j+1; i < k; i++) {
			if (x[i] < min) {
				min = x[i];
				index = i;
			}
		}
		x[index] = x[j];
		x[j] = min;
	}
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
	 MethodSearch(arr, n);
	 cout << "Result: ";
	 for (int j = 0; j < n; j++)
	 {
		 cout << arr[j] << " ";
	 }
	 cout << endl;
	 system("pause");
	return 0;
}