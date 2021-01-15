#include <iostream>
using namespace std;
const int Size = 5;

void BubleSort(int mass[], int Size) {
    int temp = 0;
    for (int i = 0; i < Size - 1; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int mass[Size];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < Size; i++) {
        cin >> mass[i];
    }

    cout << "Отсортированный методом пузырька массив:" << endl;
    BubleSort(mass, Size);
    for (int i = 0; i < Size; i++) {
        cout << mass[i] << " ";
    }

    return 0;
}