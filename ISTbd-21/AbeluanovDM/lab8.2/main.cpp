#include <iostream>
#include <algorithm>

#include "ExpGenerator.h"
#include "Vector.h"
#include "Math.h"

// Извините, но лень писать памятку для программиста... Всё впринципе осталось по старому, кроме некоторых функций, а так же добавились некоторые (гернератор например)

int main() {

    std::cout << "\nArray: ";
    ExpGenerator<double> generator(2, 0, 2, 5);
    Vector<double> vector(generator);

    vector.insert(3, 1000);
    vector.delete_element(2);

    const auto max = std::max_element(vector.begin(), vector.end());
    const auto min = std::min_element(vector.begin(), vector.end());

    print(vector);

    std::cout << std::endl;

    std::cout << "\nIndex of element (64) = " << vector.index(64) << "\nElement of index (3) = " << vector[3] << std::endl;
    std::cout << "\nQuantity of elements = " << vector.quantity() << "\nSum of elements = " << sum(vector) << "\nAverage of elements = " << average(vector) << std::endl;


    std::cout << "\nMin element = " << *min << "\nMax element = " << *max << std::endl;

    std::cout << "Index of min element = " << std::distance(vector.begin(), min) << std::endl;
    std::cout << "Index of max element = " << std::distance(vector.begin(), max) << std::endl;
    vector.cls();
    std::cout << "Quantity after clear the array = " << vector.quantity() << std::endl;

}
