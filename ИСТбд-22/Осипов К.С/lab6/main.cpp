#include <iostream>

using namespace std;

void Example1()
{
    cout << "\tExample 1\n";

    // Выбор данных из памяти с помощью разных указателей
    // Использование функций приведения типов

    unsigned long L = 12345678;
    char* cp = (char*)&L;
    int* ip = (int*)&L;
    long* lp = (long*)&L;
    float* fp = (float*)&L;

    cout << "\n&L = " << &L << endl;
    cout << "\n  L = " << L;
    cout << "\n*cp = " << *(reinterpret_cast<unsigned long*>(cp));
    cout << "\n*ip = " << *(reinterpret_cast<unsigned long*>(ip));
    cout << "\n*lp = " << *(reinterpret_cast<unsigned long*>(lp));
    cout << "\n*fp = " << *(reinterpret_cast<unsigned long*>(fp));

    cout << "\n\n";
}

void Example2()
{
    cout << "\tExample 2\n\n";

    //Операции над указателями
    int a, c, b;
    int* ca, * cb;
    int* sa, * sb, * sc;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    c = a + b;

    sb = &b;//инициализация указателей через взятие адреса
    sa = &a;
    sc = &c;
    //присваивание указателю значения выражения
    *sc = c + a - b;
    ca = sa;//присваивание указателю значения другого указателя
    cb = sb;
    *sa = 12;//присваивание указателю значения константы

    cout << "\n*ca = " << *ca;
    cout << "\n*sa = " << *sa;
    cout << "\n*cb = " << *cb;
    cout << "\n*sb = " << *sb;
    cout << "\n*sc = " << *sc;

    cout << "\nca = " << ca;
    cout << "\ncb = " << cb;
    cout << "\nsc = " << sc;

    cout << "\na = " << a;
    cout << "\nb = " << b;
    cout << "\nc = " << c;

    cout << "\n&a = " << &a;
    cout << "\n&b = " << &b;
    cout << "\n&c = " << &c;

    cout << "\n*&a = " << *&a;

    cout << "\n*cb-*ca = " << *cb - *ca;
    cout << "\n*cb+*ca = " << *cb + *ca;
    *cb += 2; //сложение с константой
    cout << "\ncb = " << cb;
    cb++; //инкремент
    cout << "\ncb = " << cb;
    ca--; //декремент
    cout << "\ncа = " << ca;
    cout << "\ncb-ca = " << cb - ca;

    cout << "\n\n";
}

void Example3()
{
    cout << "\tExample 3\n\n";

    int x = 10;
    int y = 10;
    int* xptr = &x;
    int* yptr = &y;

    //сравниваем указатели
    if (xptr == yptr)
        cout << "Pointers are equal\n";
    else
        cout << "Pointers are not equal\n";

    //сравниваем значения, на которое указывает указатель
    if (*xptr == *yptr)
        cout << "Values are equal\n\n";
    else
        cout << "Values are not equal\n\n";
}

int main() 
{
    system("chcp 1251 > NUL");

    cout << "--------------------------------------------------\n\n";
    Example1();
    cout << "--------------------------------------------------\n\n";
    Example2();
    cout << "--------------------------------------------------\n\n";
    Example3();
    cout << "--------------------------------------------------\n\n";

    system("pause");
    return 0;
}