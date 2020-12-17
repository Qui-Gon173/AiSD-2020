#include <iostream>
#include "list.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    List lst;
    lst.new_node(1);
    lst.new_node(12345);
    lst.new_node(1234);
    lst.new_node(123);
    lst.new_node(12);
    cout << endl << "Общее количество элементов в списке - " << lst.getsize() << endl;
    cout << endl << "Стартовый список от начала до конца" << endl << "-------------------" << endl;;
    lst.print_list_ahead();
    lst.creation_node_in_target_place(2,55);
    cout << endl << "Стартовый список с конца до начала" << endl << "-------------------" << endl;;
    lst.print_list_back();
    lst.delete_target_element(3);
    cout << endl << "Общее количество элементов в списке - " << lst.getsize() << endl;
    lst.search_by_value(123);
    cout << "Сумма всех элементов списка - ";
    cout << lst.sum_values_list();
    cout << endl << "Среднее значение элементов списка - ";
    cout << lst.mid_value();
    cout << endl << "Mинимальный элемент - ";
    cout<<lst.find_min_value();
    cout << endl << "Mаксимальный элемент - ";
    cout<<lst.find_max_value();
    lst.clear();
    return 0;
}