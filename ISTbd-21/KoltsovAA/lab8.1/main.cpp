#include <iostream>
#include "List.h"


int main() {
    List<double> list;
    list.append(new double(3.14));
    list.append(new double(13.37));
    list.append(new double(1.5));
    list.append(new double(6.0));
    list.append(new double(3.2));

    list.print_all();

    double* to_add = new double;
    double* after = new double;
    std::cout << "Add: ";
    std::cin >> *to_add;
    std::cout << "After: ";
    std::cin >> *after;

    list.insert_after(after, to_add);
    list.print_all();

    std::cout << "Average: " << list.get_average() << std::endl;
}
