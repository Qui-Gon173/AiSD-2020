#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int y = 10;

    int* xptr = &x;
    int* yptr = &y;

    if (xptr == yptr)
        cout << "Pointers are equal\n";
    else
        cout << "Pointers are not equal\n";

    if (*xptr == *yptr) {
        cout << "Value are equal\n";
    }
    else {
        cout << "Value are not equal\n";
    }

    system("pause");
    return 0;
}