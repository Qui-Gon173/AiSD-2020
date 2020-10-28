#include <iostream>
using namespace std;
void LinSearch() {
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
	int i = 0;
	bool flag = false;
	for (i = 0; i < n; i++) {
		if (arr[i] == num)
		{
			flag = true;
			cout << "The element is in the " << i + 1 << " position" << endl;
			break;
		}
	}
	if (flag == false) cout << "Element not found" << endl;
}
int main() {
	LinSearch();
	return 0;
}