#pragma once
#include <iostream>
#include "Vector.h"
// Вывод
template<typename T>
void print(Vector<T>& vector) {
    for (auto& element : vector) {  // Проходимся по массиву
        std::cout << element << " "; // Выводим
    }
}