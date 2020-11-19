#include <iostream>
#include <utility>
using namespace std;

void hoarsort(int array[], int low, int high) {
    if (low > high) {
        return;
    }

    int i = low;
    int j = high;

    int piv = array[(i + j) / 2];

    while (i <= j) {
        while (array[i] < piv) {
            i++;
        }
        while (array[j] > piv) {
            j--;
        }
        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            if (!j) {
                break;
            }
            j--;
        }
    }

    if (j > low)
        hoarsort(array, low, j);
    if (i < high)
        hoarsort(array, i, high);
}


int main() {
    int size;
    int array[1000];

    cout << "size (max 1000): ";
    cin >> size;

    cout << "array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    hoarsort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
