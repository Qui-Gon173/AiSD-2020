#include <iostream>
#include <algorithm>

#include "Vector.h"
#include "Func.h"
#include "FibGenerator.h"



int main() {

    FibGenerator<unsigned long> gen(12);

    Vector <unsigned long> vector(gen);

    print(vector);

    std::cout << "length = " << vector.len() << std::endl;
    std::cout << "sum = " << get_sum(vector) << std::endl;
    std::cout << "average = " << get_average(vector) << std::endl;

    const auto min = std::min_element(vector.begin(), vector.end());
    const auto max = std::max_element(vector.begin(), vector.end());

    std::cout << "minimum = " << *min << std::endl;
    std::cout << "maximum = " << *max << std::endl;
    std::cout << "min index = " << std::distance(vector.begin(), min) << std::endl;
    std::cout << "max index = " << std::distance(vector.begin(), max) << std::endl;
    vector.clear();
    std::cout << "length = " << vector.len() << std::endl;

    return 0;
}

