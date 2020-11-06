#include <iostream>
#include "Vector.h"


int main() {
    Vector<double> vector;

    vector.append(0);
    vector.repr();  // [0]
    vector.append(1);
    vector.repr();  // [0, 1]
    vector.append(2);
    vector.repr();  // [0, 1, 2]
    vector.append(3);
    vector.repr();  // [0, 1, 2, 3]
    vector.insert(100, 4);
    vector.repr();  // [0, 1, 2, 3, 4]
    vector.insert(3, -10);
    vector.repr();  // [0, 1, 2, -10, 3, 4]
    vector.del(1);
    vector.repr();  // [0, 2, -10, 3, 4]
    std::cout << vector[2] << std::endl;  // -10
    std::cout << vector.index(3) << std::endl;  // 3

    std::cout << "len = " << vector.len() << std::endl;
    std::cout << "sum = " << vector.get_sum() << std::endl;
    std::cout << "average = " << vector.get_average() << std::endl;
    std::cout << "min = " << vector.get_min() << std::endl;
    std::cout << "max = " << vector.get_max() << std::endl;
    vector.clear();
    std::cout << "len after clear() = " << vector.len() << std::endl;
    
    return 0;
}
