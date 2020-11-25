#include <iostream>
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");

    int x = 10;
    int y = 10;
    int* xptr = &x;
    int* yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "Указатели равны: xptr = yptr\n";
    else
        cout << "Указатели неравны: xptr != yptr\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        cout << "Значения равны: *xptr = *yptr\n";
    }
    else {
        cout << "Значения неравны: *xptr != *yptr\n";
    }

    return 0;
}