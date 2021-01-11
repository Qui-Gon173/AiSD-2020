// Выбор данных из памяти с помощью разных указателей
// Использование функций приведения типов
#include <iostream>
using namespace std;

int main() {
    unsigned long L = 12345678;
    char* cp = (char*)&L;
    int* ip = (int*)&L;
    long* lp = (long*)&L;

    cout << "\n&L = " << &L;
    cout << "\nL = " << L;
    cout << "\n*cp = " << *cp;
    cout << "\n*ip = " << *ip;
    cout << "\n*lp = " << *lp;

    return 0;
}
