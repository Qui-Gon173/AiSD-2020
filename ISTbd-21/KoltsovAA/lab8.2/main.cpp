#include <iostream>
#include <algorithm>

#include "Vector.h"
#include "utils.h"
#include "ExpotentialGenerator.h"


int main() {
    ExpotentialGenerator<double> gen(2, 0, 1, 15);
    Vector<double> vector(gen);

    vector.insert(3, -3.14);

    repr(vector);

    std::cout << "vector[2] = " << vector[2] << std::endl;
    std::cout << "index of 1024 = " << vector.index(1024) << std::endl;

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
