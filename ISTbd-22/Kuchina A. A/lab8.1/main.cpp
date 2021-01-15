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
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    cout << endl << "��������� ������ �� ������ �� �����" << endl << "-------------------" << endl;;
    lst.print_list_ahead();
    lst.creation_node_in_target_place(2,55);
    cout << endl << "��������� ������ � ����� �� ������" << endl << "-------------------" << endl;;
    lst.print_list_back();
    lst.delete_target_element(3);
    cout << endl << "����� ���������� ��������� � ������ - " << lst.getsize() << endl;
    lst.search_by_value(123);
    cout << "����� ���� ��������� ������ - ";
    cout << lst.sum_values_list();
    cout << endl << "������� �������� ��������� ������ - ";
    cout << lst.mid_value();
    cout << endl << "M���������� ������� - ";
    cout<<lst.find_min_value();
    cout << endl << "M����������� ������� - ";
    cout<<lst.find_max_value();
    lst.clear();
    return 0;
}