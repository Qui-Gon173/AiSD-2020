#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int y = 10;
    int *xptr = &x;
    int *yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "pointers are equal\n";
    else
        cout << "pointers are not equal\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        cout << "the values are equal to\n";
    }
    else {
        cout << "these values are not equal\n";
    }
    system("pause");
    return 0;
}