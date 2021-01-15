#include <iostream>

using namespace std;


int parent(int i) {
	return i / 2;
}


int left(int i) {
	return (2 * i + 1);
}


int right(int i) {
	return (2 * i + 2);
}


void max_heapify(int arr[], int size, int i) {
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l < size && arr[l] > arr[i])
		largest = l;
	else largest = i;
	if (r < size && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		arr[i] += arr[largest];
		arr[largest] = arr[i] - arr[largest];
		arr[i] -= arr[largest];
		max_heapify(arr, size, largest);
	}
}


void build_max_heap(int arr[], int size) {
	for (int i = size / 2; i >= 0; --i) {
		max_heapify(arr, size, i);
	}
}

void heap_sort(int arr[], int size) {
	build_max_heap(arr, size);
	for (int i = size - 1; i >= 0; --i) {
		arr[i] += arr[0];
		arr[0] = arr[i] - arr[0];
		arr[i] -= arr[0];
		size -= 1;
		max_heapify(arr, size, 0);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������������ ������ �4 \n �������� ������� ��. �����-22 \n ������� ���� \n �������� ������������� \n ������������ ������ ���������";
	cout << "�������: \n ����������� ������������� �������� ����������.\n";
	int size = 0;
	cout << "������� ������ �������: ";
	cin >> size;
	int MyArr[50] = {};
	cout << "������� �������� �������: ";
	for (int i = 0; i != size; ++i)
	cin >> MyArr[i];
	cout << "��������������� ������: ";
	heap_sort(MyArr, size);
	for (int i = 0; i != size; ++i)
	cout << MyArr[i] << ' ';
	cout << "\n";
	return 0;
}
