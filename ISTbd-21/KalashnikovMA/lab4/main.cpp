#include <iostream>
#include <utility>
using namespace std;

void heapsort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size / 2 - 1 - i / 2; j >= 0; j--) {
            if (2 * j + 2 <= size - 1 - i) {
                if (arr[2 * j + 1] > arr[2 * j + 2]) {
                    if (arr[j] < arr[2 * j + 1]) {
                        swap(arr[j], arr[2 * j + 1]);
                    }
                } else {
                    if (arr[j] < arr[2 * j + 2]) {
                        swap(arr[j], arr[2 * j + 2]);
                    }
                }
            } else if (2 * j + 1 <= size - 1 - i) {
                if (arr[j] < arr[2 * j + 1]) {
                    swap(arr[j], arr[2 * j + 1]);
                }
            }
        }

        swap(arr[0], arr[size - 1 - i]);
    }
}

int main() {
    int arr[1000];
    int size;

    cout << "size: ";
    cin >> size;
    cout << "array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapsort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
