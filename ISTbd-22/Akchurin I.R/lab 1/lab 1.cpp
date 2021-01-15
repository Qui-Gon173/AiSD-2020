#include <iostream>
using namespace std;
const int Size = 5;

int LinearSearch(int mass[], int key, int Size) {
    for (int i = 0; i < Size; i++)
        if (key == mass[i])
            return i;
    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int mass[Size], key, result;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < Size; i++) {
        cin >> mass[i];
    }
    cout << "Введите искомое значение: " << endl;
    cin >> key;
    result = LinearSearch(mass, key, Size);
    if (result == -1)
        cout << "Элемент не найден";
    else cout << "Искомый элемент массива находится на " << result + 1 << "-м месте";

    return 0;
}
