#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    List list;
    std::cout << "============================== PROGRAMS START ==============================" << std::endl;
    list.adding_element(1);
    list.adding_element(2);
    list.adding_element(44);
    list.adding_element(1234);
    list.adding_element(123);
    list.adding_element(12);
    std::cout << "============================== LIST OF ELEMENTS ==============================" << std::endl;
    list.print_from_head();
    std::cout << "============================== Quantity ==============================" << std::endl;
    std::cout << "Quantity: " << list.getsize();
    std::cout << endl;
    list.cls();
    return 0;
}