#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <iostream>
#include "Vector.h"


// Сумма всех значений
template<typename T>
T summ(Vector<T>& vector) {
    T counter = 0;
    for (auto& element : vector) {
        counter = counter + element;
    }
    return counter;
}

// Вывод
template<typename T>
void print(Vector<T>& vector) {
    for (auto& element : vector) {
        std::cout << element << " ";
    }
}

// Среднее значение
template<typename T>
T medium(Vector<T>& vector) {
    return vector.Size() ? summ(vector) / vector.Size() : 0;
}


#endif // MATH_H_INCLUDED
