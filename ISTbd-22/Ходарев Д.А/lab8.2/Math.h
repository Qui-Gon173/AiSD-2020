#pragma once
#include <iostream>
#include "Vector.h"


// Сумма всех значений 
template<typename T>
T sum(Vector<T>& vector) {
    T counter = 0;
    for (auto& element : vector) { // Проходимся по массиву
        counter = counter + element; // Суммируем с counter'ом все элементы поочередно
    }
    return counter;
}

// Среднее значение
template<typename T>
T average(Vector<T>& vector) {
    return vector.quantity() ? sum(vector) / vector.quantity() : 0;
}
