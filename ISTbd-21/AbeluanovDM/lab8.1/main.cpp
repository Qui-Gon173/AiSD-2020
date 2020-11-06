
#include <iostream>
#include "Vector.h"

int main() {
    Vector<double> vector(2); 
    vector.insert(0, 1);
    vector.supplement(2);
    vector.supplement(4);
    std::cout << "Supp array 1: ";
    vector.print();
    vector.insert(10, 10); // Проверка на добавление элемента на позицию, которая на много больше размера массива
    std::cout << "Inserted 1 element to array (1): ";
    vector.print();
    vector.supplement(2);
    vector.supplement(5);
    std::cout << "Supp array 2(idk for what...):   "; // Вспомнил! Я просто закрыл 10 числами с права
    vector.print();
    vector.insert(2, 100);
    std::cout << "Inserted 1 element to array (2): ";
    vector.print();
    vector.delete_element(2);
    std::cout << "Deleted 1 element of array (1):  ";
    vector.print();

    std::cout << "\nElement of index: " << vector[0] << " " << vector[5] << std::endl;
    std::cout << "Index of element: " << vector.index(10) << std::endl;

    std::cout << "Quantity of elements: " << vector.quantity() << std::endl;
    std::cout << "Sum of all elements: " << vector.sum() << std::endl;
    std::cout << "Average: " << vector.average() << std::endl;
    std::cout << "Min: " << vector.min() << std::endl;
    std::cout << "Max: " << vector.max() << std::endl;

    vector.cls();
    std::cout << "Quantity of clear array: " << vector.quantity() << "\nClear array itself: ";
    vector.print();

}
