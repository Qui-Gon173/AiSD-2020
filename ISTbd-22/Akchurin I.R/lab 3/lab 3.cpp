#include <iostream>
using namespace std;
const int Size = 10;

void HoarSort(int mass[], int L, int R) {
    int i = L, j = R;
    double tmp, center = mass[(L + R) / 2];

    while (i <= j) {
        while (mass[i] < center)
            i++;
        while (mass[j] > center)
            j--;


        if (i <= j)
        {
            if (i < j)
            {
                tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
            i++;
            j--;
        }
    }


    if (L < j)
        HoarSort(mass, L, j);
    if (i < R)
        HoarSort(mass, i, R);
}

int main()
{
    setlocale(LC_ALL, "rus");

    int mass[Size];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < Size; i++) {
        cin >> mass[i];
    }

    cout << "Отсортированный методом Хоара массив:" << endl;
    HoarSort(mass, 0, Size - 1);
    for (int i = 0; i < Size; i++) {
        cout << mass[i] << " ";
    }

    return 0;
}
