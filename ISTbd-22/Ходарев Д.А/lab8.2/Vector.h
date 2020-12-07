#pragma once
#include <iostream>
#include <limits>

#include "VectorIter.h"
#include "Generator.h"

template<typename T>
class Vector {
private:
    T* array;
    size_t length;
    size_t num_elements = 0;
public:
    Vector(size_t all_elements = 64) : length(all_elements) {
        array = new T[all_elements];
    }

    // Генератор чисел показательной функции
    Vector(Generator<T>& generator) {
        length = generator.len() * 2; // Размер
        array = new T[length];  // Массив по размеру
        for (T& item : generator) {  // Добавление чисел
            adding_back(item);
        }
    }

    using iterator = VectorIter<T>;
    using c_iter = VectorIter<const T>;

    ~Vector() {
        delete[] array;
    }

    // Вычисление начала для const
    c_iter begin() const {
        return iterator(array);
    }
    // Вычисление конца для const
    c_iter end() const {
        return iterator(array + num_elements);
    }

    // Вычисление начала
    iterator begin() {
        return iterator(array);
    }
    // Вычисление конца
    iterator end() {
        return iterator(array + num_elements);
    }

    T operator[](size_t search_index) {
        return array[search_index];
    }
    size_t search_index(T element) {
        for (size_t i = 0; i < num_elements; i++) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }

    size_t quantity() const {
        return num_elements;
    }

    void adding_elements() {
        size_t length = num_elements * sizeof(T);

        if (num_elements * sizeof(T) == length) {
            T* new_array = new T[num_elements * 2];
            for (size_t i = 0; i < num_elements; i++) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
    }

    void adding_back(T element) {
        adding_elements();
        array[num_elements++] = element;
    }

    void adding_element(size_t position, T element) {
        adding_elements();

        if (position >= num_elements) {
            adding_back(element);
            return;
        }

        for (size_t i = num_elements - 1; i >= position; i--) {
            array[i + 1] = array[i];
        }

        array[position] = element;
        num_elements++;
    }

    void delete_element(size_t position) {
        if (position >= num_elements) {
            return;
        }

        for (size_t i = position; i < num_elements - 1; i++) {
            array[i] = array[i + 1];
        }
        num_elements--;
    }

    void print() {
        for (size_t i = 0; i < num_elements; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};
