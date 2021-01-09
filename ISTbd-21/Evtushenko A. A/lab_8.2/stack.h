#pragma once
#include <cassert>
#include <iostream>
#include "stackIter.h"


template <typename T>
class Stack {
private:
    T* stackPtr;              
    int size;    
    int index;                     
    void increased_length();
public:
    Stack(int = 64);                 
    Stack(Generator<T>& gen) {
        size = gen.len() * 2;
        stackPtr = new T[size];
        for (T& element : gen) { 
            add_element(element); 
        }
    }
    ~Stack();    

    void add_element(const T&);
    T delete_element();           
    const T& search_n_element(int = 1) const; 
    int getStackLength() const;
    T* getPtr() const;   
    int getNumElement() const;
    void add_more_elements(T*, size_t);
    void print_top_stack() const;
    void add_element_from_new_stack(Stack<T>&, int);
    T* extracting_elements(int);
    T min();
    T max();
    void cls();

    typedef StackIter<T> iterator;
    typedef StackIter<const T> const_iterator;

    iterator begin() {
        return iterator(stackPtr + index - 1);
    };
    iterator end() {
        return iterator(stackPtr - 1);
    };

    iterator rbegin() {
        return iterator(stackPtr + index - 1);
    };
    iterator rend() {
        return iterator(stackPtr - 1);
    };

    const_iterator begin() const {
        return const_iterator(stackPtr + index - 1);
    };
    const_iterator end() const {
        return const_iterator(stackPtr - 1);
    };
};

template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) {
    stackPtr = new T[size]; 
    index = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] stackPtr; 
}

template <typename T>
void Stack<T>::add_element(const T& value) {
    // проверяем размер стека
    if (index == size) {
        increased_length();
    }
    stackPtr[index++] = value; 
}

//Вставка несколькиx значений
template <typename T>
void Stack<T>::add_more_elements(T* array, size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        add_element(array[i]);
    }
}

template <typename T>
void Stack<T>::increased_length() {
    T* buffer = new T[this->getStackLength() * 2];
    index = this->getNumElement();

    for (int i = 0; i < index; i++)
        stackPtr[i] = this->getPtr()[i];
    delete[] stackPtr;
    stackPtr = buffer;
}

template <typename T>
T* Stack<T>::extracting_elements(int n) {
    assert(index > n);
    T* array = new T[n - 1];

    for (size_t i = 0; i < n - 1; i++) {
        array[i] = this->delete_element();
    }
    return array;
}

template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& newStack, int n) {
    int otherTop = newStack.getNumElement();
    assert(n < otherTop);

    for (size_t i = 0; i < n; i++) {
        this->add_element(newStack.delete_element());
    }
}

template <class T>
const T& Stack<T>::search_n_element(int nom) const {
    // Проверка
    assert(nom <= index);

    return stackPtr[index - nom]; 
}

template <class T>
void Stack<T>::print_top_stack() const {
    std::cout << stackPtr[index];
}

template <typename T>
int Stack<T>::getStackLength() const {
    return size;
}

template <typename T>
T* Stack<T>::getPtr() const {
    return stackPtr;
}

template <typename T>
int Stack<T>::getNumElement() const {
    return index;
}

template <typename T>
T Stack<T>::delete_element() {
    assert(index > 0); 

    return stackPtr[--index];
}

template <typename T>
void Stack<T>::cls() {
    this->index = 0;
}