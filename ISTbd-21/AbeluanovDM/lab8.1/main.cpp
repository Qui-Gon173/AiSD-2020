/*  Пока без менюшки но всё же... 
    Руководство погром-места: 

    Короче, чтобы добавить элемент в конец массива - vector.supplement(значение)
    Потом, чтобы добавить элемент по позиции - vector.insert(позиция, значение)
    А что бы удалить элемент по позиции - vector.delete_element(позиция)
    Чтобы найти элемент по индексу - std::cout << vector[0] << " " << vector[индекс] << std::endl;
    Ну и наконец, чтобы найти индекс элемента - std::cout << vector.index(значение) << std::endl;

    *Названия функций полная х...*
*/

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

}