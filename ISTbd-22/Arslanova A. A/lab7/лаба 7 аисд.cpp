// лаба 6.3 аисд.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    int y;
    cin >> x;
    cin >> y;
    int* xptr = &x;
    int* yptr = &y;

    if (xptr == yptr)
        cout << "Указатели равны\n";
    else
        cout << "Указатели неравны\n";

    if (*xptr == *yptr) {
        cout << "Значения равны\n";
    }
    else {
        cout << "Значения неравны\n";
    }
    system("pause");
    return 0;
}