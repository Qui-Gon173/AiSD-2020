#include <iostream>
#include <vector>
#include <algorithm>
#include "Generator.h"
#include "Math.h"
#include "Vector.h"

int main() {

    std::cout << "\nArray: ";
    Generator<unsigned long> generator(3, 1, 1, 5);
    Vector<unsigned long> vector(generator);

    const auto max = std::max_element(vector.begin(), vector.end());
    const auto min = std::min_element(vector.begin(), vector.end());

    print(vector);

    std::cout << std::endl;

    std::cout << "\nIndex of element 27 = " << vector.GetIndex(27)  << std::endl;
    std::cout << "\nElement of index 4 = " << vector[4] << std::endl;

    std::cout << "\nSum of elements = " << summ(vector) << std::endl;
    std::cout << "\nAverage of elements = " << medium(vector)<< std::endl;
    std::cout << "\nMax element = " << *max << std::endl;
    std::cout << "\nMin element = " << *min << std::endl;
    std::cout << "Index of min element = " << std::distance(vector.begin(), min) << std::endl;
    std::cout << "Index of max element = " << std::distance(vector.begin(), max) << std::endl;
    std::cout << "\n New array: "<<std::endl;
    vector.insert(3, 1000);
    vector.DeleteElement(2);
    print(vector);
    std::cout << std::endl;
    vector.Clear();
    std::cout << "Quantity after clear the array = " << vector.Size() << std::endl;
    return 0;

}
