#include <iostream>
// Выбор данных из памяти с помощью разных указателей
// Использование функций приведения типов
int main() {
    unsigned long L = 12345678;
    char *cp = (char *)&L;
    int *ip = (int *)&L;
    long *lp = (long *)&L;

    std::cout << "\n&L = " << &L;
    std::cout << "\nL = " << L;
    std::cout << "\n*cp = " << *cp;
    std::cout << "\n*ip = " << *ip;
    std::cout << "\n*lp = " << *lp;
}
