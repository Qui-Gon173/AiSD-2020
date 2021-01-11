#include <iostream>
#include "list.h"

int main() {
    List list;
    cout << "==================== LAB 8.1 ====================" << endl;
    cout << "=================== TASK  4_4 ===================" << endl;
    list.add_element_from_back(50);
    list.add_element_from_back(51);
    cout << "[LIST]: ";
    list.print();
    cout << "[ADD ELEMENT FROM BACK]: ";
    list.add_element_from_back(36);
    list.add_element_from_back(17);
    list.print();
    cout << "[ADD ELEMENT WITH INDEX 1]: ";
    list.add_element_by_index(365, 1);
    list.print();
    cout << "[DELETE ELEMENT WITH INDEX 3]: ";
    list.delete_element_by_index(3);
    list.print();
    cout << "[SEARCH INDEX WITH VALUE 365]: ";
    list.search_index(365);

    cout << "==================== MATH ====================" << endl;
    cout << "[THE LENGTH OF THE LIST]: " << list.getLength() << endl;
    cout << "[AVARAGE]: " << list.avarage() << endl;
    cout << "[SUM]: " << list.sum() << endl;
    cout << "[MAX]: " << list.max() << endl;
    cout << "[MIN]: " << list.min() << endl;

    return 0;
}