#include <iostream>
using namespace std;
int LinSearch(int *x, int k, int key) {
	int i;
	for ( i = 0; i < k; i++) 
		if (x[i] == key)
			break;	
	return i < k ? i : -1;
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
	int num;
	cout << "Enter the number you want to find:" << endl;
	cin >> num;
	int result = LinSearch(arr, n, num);
	if (result ==-1) cout << "Element not found" << endl;
	else cout << "The element is in the " <<result +1 << " position" << endl;
	return 0;
}