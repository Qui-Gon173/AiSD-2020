#pragma once
#include <iostream>
#include <limits>

#include "VectorIter.h"
#include "ExpGenerator.h"


template<typename T>
class Vector {
private:
    T* array;
    size_t length;
    size_t all_elements = 0;
public:
    // Размер массива
    Vector(size_t all_elements = 64) : length(all_elements) {
        array = new T[all_elements];
    }

    // Генератор чисел показательной функции
    Vector(ExpGenerator<T>& generator) {
        length = generator.moves() * 2; // Размер
        array = new T[length];  // Массив по размеру
        for (T& item : generator) {  // Добавление чисел
            supplement(item);   
        }
    }

    using iterator = VectorIter<T>;
    using c_iter = VectorIter<const T>;
    
    // Деструктор
    ~Vector() {
        delete[] array;
    }

    // Вычисление начала для const
    c_iter begin() const {
        return iterator(array);
    }
    // Вычисление конца для const
    c_iter end() const {
        return iterator(array + all_elements);
    }

    // Вычисление начала
    iterator begin() {
        return iterator(array);
    }
    // Вычисление конца
    iterator end() {
        return iterator(array + all_elements);
    }

    // Поиск по индексу массива
    T operator[](size_t index) {
        return array[index]; // Тупо возвращаем элемент(индекса)
    }

    // Поиск индекса по элементу (находит только первый из всех)
    size_t index(T element) {
        for (size_t i = 0; i < all_elements; i++) {
            if (array[i] == element) {
                return i; // Возвращаем индекс элемента который нашли способом выше (2 строчки линейного поиска)
            }
        }
        return -1;
    }

    // Кол-во элементов в массиве
    size_t quantity() const {
        return all_elements;
    }

    // Увеличение размера массива
    void append() {
        size_t length = all_elements * sizeof(T);

        if (all_elements * sizeof(T) == length) { // Если кол-во элементов равно массиву, делаем ресайз 
            T* new_array = new T[all_elements * 2]; // Создаём новый массив с размером в 2 раза больше
            for (size_t i = 0; i < all_elements; i++) {
                new_array[i] = array[i];
            }
            delete[] array; // Высвобождаем память на старом массиве
            array = new_array; 
        }
    }

    // Добавление в конец массива
    void supplement(T element) {
        append();
        array[all_elements++] = element; // Добавляем элемент в массив
    }

    // Добавление элемента по позиции
    void insert(size_t position, T element) {
        append();

        if (position >= all_elements) { // Если указана позиция >= чем количество элементов в массиве, то новый элемент запишется в конец. 
            supplement(element);
            return;
        }

        for (size_t i = all_elements - 1; i >= position; i--) { // Вычисление позиции
            array[i + 1] = array[i];
        }

        array[position] = element;  // Само добавление элемента по позиции
        all_elements++; // Чтобы не съедало последний элемент при добавлении в середину\начало массива
    }

    // Удаление элемента по позиции
    void delete_element(size_t position) {
        if (position >= all_elements) {
            return;
        }

        for (size_t i = position; i < all_elements - 1; i++) {  // тут как бы сдвиг и замена значения(i) на значение(i + 1)
            array[i] = array[i + 1];
        }
        all_elements--; // шоб небыло дублирования последнего элемента
    }

    // Очистка контейнера
    void cls() {
        all_elements = 0;
    }
};
