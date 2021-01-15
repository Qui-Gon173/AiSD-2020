#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    int x = 10;
    int y = 10;
    int* xptr = &x;
    int* yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "Values are equal\n";
    else
        cout << "Values are not equal\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        cout << "Values are equal\n";
    }
    else {
        cout << "Values are not equal\n";
    }
    system("pause");
    return 0;
}