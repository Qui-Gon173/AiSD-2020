#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 10;
    int* xptr = &x;
    int* yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "ptr == ptr\n";
    else
        cout << "ptr != ptr\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        cout << "val == val\n";
    } else {
        cout << "val != val\n";
    }

    return 0;
}
