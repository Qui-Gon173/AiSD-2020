#include <iostream>


int main() {
    int a, c, b;
    int* ca, * cb;
    int* sa, * sb, * sc;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    c = a + b;

    sb = &b; //инициализация указателей через взятие адреса
    sa = &a;
    sc = &c;
    //присваивание указателю значения выражения
    *sc = c + a - b;
    ca = sa; //присваивание указателю значения другого указателя
    cb = sb;
    *sa = 12; //присваивание указателю значения константы

    std::cout << "\n*ca = " << *ca;
    std::cout << "\n*sa = " << *sa;
    std::cout << "\n*cb = " << *cb;
    std::cout << "\n*sb = " << *sb;
    std::cout << "\n*sc = " << *sc;

    std::cout << "\nca = " << ca;
    std::cout << "\ncb = " << cb;
    std::cout << "\nsc = " << sc;

    std::cout << "\na = " << a;
    std::cout << "\nb = " << b;
    std::cout << "\nc = " << c;

    std::cout << "\n&a = " << &a;
    std::cout << "\n&b = " << &b;
    std::cout << "\n&c = " << &c;

    std::cout << "\n*&a = " << *&a;

    std::cout << "\n*cb-*ca = " << *cb - *ca;
    std::cout << "\n*cb+*ca = " << *cb + *ca;
    *cb += 2; //сложение с константой
    std::cout << "\ncb = " << cb;
    cb++; //инкремент
    std::cout << "\ncb = " << cb;
    ca--; //декремент
    std::cout << "\nca = " << ca;
    std::cout << "\ncb-ca = " << cb - ca;
}
