#pragma once

#include <iostream>
#include <limits>

#include "VectorIterator.h"


const size_t DEFAULT_ALLOCATED_LENGTH = 32;
const size_t NOT_FOUND_INDEX = -1;
const int RESIZE_COEFFICIENT = 2;


template<typename T>
class Vector {
private:
    T* array;
    size_t length = 0;
    size_t allocated_length;

    void manage_size() {
        if (this->length < this->allocated_length) {
            return;
        }

        this->allocated_length *= RESIZE_COEFFICIENT;
        T* new_array = new T[allocated_length];
        for (size_t i = 0; i < this->length; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
public:
    typedef VectorIterator<T> iterator;
    typedef VectorIterator<const T> const_iterator;

    Vector(size_t length = DEFAULT_ALLOCATED_LENGTH) : allocated_length(length) {
        this->array = new T[length];
    }

    ~Vector() {
        delete[] array;
    }

    iterator begin() {
        return iterator(this->array);
    }
    iterator end() {
        return iterator(this->array + this->length);
    }

    const_iterator begin() const {
        return iterator(this->array);
    }
    const_iterator end() const {
        return iterator(this->array + this->length);
    }

    T operator[](size_t index) {
        return this->array[index];
    }

    size_t len() const {
        return this->length;
    }

    size_t index(T element) {
        for (size_t i = 0; i < this->length; i++) {
            if (this->array[i] == element) {
                return i;
            }
        }
        return NOT_FOUND_INDEX;
    }

    void append(T element) {
        this->manage_size();
        this->array[length++] = element;
    }

    void insert(size_t position, T element) {
        this->manage_size();

        if (position >= this->length) {
            this->append(element);
            return;
        }

        for (size_t i = this->length - 1; i >= position; i--) {
            this->array[i + 1] = this->array[i];
        }

        this->array[position] = element;
        this->length++;
    }

    void del(size_t position) {
        if (position >= this->length) {
            return;
        }

        for (size_t i = position; i < this->length - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->length--;
    }

    void clear() {
        this->length = 0;
    }
};
