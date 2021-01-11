#include <iostream>

int main()
{
    int x = 10;
    int y = 10;
    int *xptr = &x;
    int *yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        std::cout << "xptr == yptr\n";
    else
        std::cout << "xptr != yptr\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr) {
        std::cout << "*xptr == *yptr\n";
    } else {
        std::cout << "*xptr != *yptr\n";
    }
}
