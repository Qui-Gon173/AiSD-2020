#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int y = 10;
    int* xptr = &x;
    int* yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "xptr = yptr\n";
    else
        cout << "xptr != yptr\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        cout << "*xptr = *yptr\n";
    }
    else {
        cout << "*xptr != *yptr\n";
    }
    return 0;
}