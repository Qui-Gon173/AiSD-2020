#include <iostream>
#include "List.h"

using namespace std;


int main() {
    List<long> list;

    list.insert(10, 2222);
    list.del(0);

    list.insert(10, 0);
    list.insert(10, 1);
    list.insert(10, 2);
    list.insert(10, 3);
    list.insert(10, 4);
    list.insert(10, 5);

    list.insert(2, 1002);
    list.insert(0, 1000);
    size_t last = list.length() - 1;
    list.insert(last, 1000 + last);

    list.print();
    cout << "sum = " << list.sum() << endl;
    cout << "average = " << list.average() << endl;

    cout << endl;
    list.del(0);
    list.print();

    cout << endl;
    list.del(0);
    list.del(list.length() - 1);
    list.print();
    cout << "min = " << list.min() << endl;
    cout << "max = " << list.max() << endl;

    cout << endl;
    list.del(3);
    list.print();

    cout << "index of 2 is " << list.index(2) << endl;
    cout << "index of 1337 is " << list.index(1337) << endl;

    cout << endl << "clear..." << endl;
    list.clear();
    list.print();
    cout << "???" << endl;

    return 0;
}
