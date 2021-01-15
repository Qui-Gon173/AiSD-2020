#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <limits>

#include "VectorIterator.h"
#include "Generator.h"

template<typename T>
class Vector {
private:
    T* arr;
    int length;
    int elements = 0;
public:

    Vector(int elements = 64) : length(elements) {
        arr = new T[elements];
    }

    // Генератор чисел показательной функции
    Vector(Generator<T>& generator) {
        length = generator.steps() * 2;
        arr = new T[length];
        for (T& item : generator) {
            push_back(item);
        }
    }

   typedef VectorIterator<T> iterator;
    typedef VectorIterator<const T> const_iter;


    ~Vector() {
        delete[] arr;
    }


    const_iter begin() const {
        return iterator(arr);
    }

    const_iter end() const {
        return iterator(arr + elements);
    }


    iterator begin() {
        return iterator(arr);
    }

    iterator end() {
        return iterator(arr + elements);
    }

    //получение значение по индексу
    T operator[](int index) {
        return arr[index];
    }

    //получение индекса элемента по значению
    int GetIndex(T element) {
        for (int i = 0; i < elements; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    //количество элементов
    int Size() const {
        return elements;
    }

    // Увеличение размера массива
    void MoreSize() {
        int length = elements * sizeof(T);

        if (elements * sizeof(T) == length) {
            T* new_array = new T[elements * 2];
            for (int i = 0; i < elements; i++) {
                new_array[i] = arr[i];
            }
            delete[] arr;
            arr = new_array;
        }
    }

    //добавление элемента в конец списка
    void push_back(T element) {
        MoreSize();
        arr[elements++] = element;
    }

    //добавление элемента в список по указанному индексу
    void insert(int position, T element) {
        MoreSize();

        if (position >= elements) {
            push_back(element);
            return;
        }

        for (int i = elements - 1; i >= position; i--) {
            arr[i + 1] = arr[i];
        }

        arr[position] = element;
        elements++;
    }

    //удаление элемента в списке по указанному индексу
    void DeleteElement(int position) {
        if (position >= elements) {
            return;
        }

        for (int i = position; i < elements - 1; i++) {
            arr[i] = arr[i + 1];
        }
        elements--;
    }

    // очистить список
    void Clear() {
        elements = 0;
    }
};


#endif // VECTOR_H_INCLUDED
