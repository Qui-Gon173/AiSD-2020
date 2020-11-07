#include <iostream>
#include <algorithm>

#include "Vector.h"
#include "utils.h"


int main() {
    Vector<double> vector;

    vector.append(0);
    repr(vector);  // [0]
    vector.append(1);
    repr(vector);  // [0, 1]
    vector.append(2);
    repr(vector);  // [0, 1, 2]
    vector.append(3);
    repr(vector);  // [0, 1, 2, 3]
    vector.insert(100, 4);
    repr(vector);  // [0, 1, 2, 3, 4]
    vector.insert(3, -10);
    repr(vector);  // [0, 1, 2, -10, 3, 4]
    vector.del(1);
    repr(vector);  // [0, 2, -10, 3, 4]
    std::cout << vector[2] << std::endl;  // -10
    std::cout << vector.index(3) << std::endl;  // 3

    std::cout << "len = " << vector.len() << std::endl;
    std::cout << "sum = " << get_sum(vector) << std::endl;
    std::cout << "average = " << get_average(vector) << std::endl;

    const auto min = std::min_element(vector.begin(), vector.end());
    const auto max = std::max_element(vector.begin(), vector.end());

    std::cout << "min = " << *min << std::endl;
    std::cout << "max = " << *max << std::endl;
    std::cout << "index of min = " << std::distance(vector.begin(), min) << std::endl;
    std::cout << "index of max = " << std::distance(vector.begin(), max) << std::endl;
    vector.clear();
    std::cout << "len after clear() = " << vector.len() << std::endl;

    return 0;
}
