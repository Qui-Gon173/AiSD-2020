#include <iostream>

using namespace std;
const int Size = 10;


void MassFeeling(int mass[], int Size)
{
    srand(time(0));
    for (int i = 0; i < Size; i++)
        mass[i] = 1 + rand() % 100;
}

void MassOutput(int mass[], int Size)
{
    for (int i = 0; i < Size; ++i)
        cout << mass[i] << " ";
    cout << "\n";
}

void Screening(int mass[], int Size, int i) {
    int root = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if (L < Size && mass[L] > mass[root])
        root = L;
    if (R < Size && mass[R] > mass[root])
        root = R;

    if (root != i)
    {
        swap(mass[i], mass[root]);
        Screening(mass, Size, root);
    }
}

void HeapSort(int mass[], int Size)
{
    for (int i = Size / 2 - 1; i >= 0; i--)
        Screening(mass, Size, i);

    for (int i = Size - 1; i >= 0; i--)
    {
        swap(mass[0], mass[i]);
        Screening(mass, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int mass[Size];
    MassFeeling(mass, Size);
    cout << "Массив, составленный из случайных значений:" << endl;
    MassOutput(mass, Size);

    cout << "Отсортированный пирамидальным методом массив:" << endl;
    HeapSort(mass, Size);
    MassOutput(mass, Size);

    return 0;
}