#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<double> vector(2);
    vector.adding_element(0, 4);
    vector.adding_element(1, 44);
    vector.adding_element(2, 35);
    vector.print();
    vector.adding_element(1, 18);
    vector.adding_back(3);
    vector.adding_back(8);
    vector.print();
    vector.adding_element(10, 10); 
    vector.print();
    vector.adding_back(7);
    vector.adding_back(68);
    vector.adding_back(6);
    vector.print();
    vector.adding_element(2, 73);
    vector.print();
    vector.delete_element(2);
    vector.print();

    cout << endl;
    cout << "index: " << vector.search_index(10) << std::endl;
    cout << "search_index: " << vector[0] << " " << vector[9] << std::endl;
    vector.print();

}