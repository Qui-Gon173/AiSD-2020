#pragma once
#include <cassert>
#include <iostream>
#include "stackIter.h"

using namespace std;

template <typename T>
class Stack {
private:
    T* pStack;              
    int num_elements;    
    int index;                     
    void increased_length();
public:
    Stack(int = 64);                 
    Stack(Generator<T>& gen) {
        num_elements = gen.len() * 2;
        pStack = new T[num_elements];
        for (T& element : gen) { 
            add_element(element); 
        }
    }
    ~Stack();    

    T delete_element();
    T* getPtr() const;
    const T& search_n_element(int = 1) const;
    T* extracting_elements(int);
    T min();
    T max();

    void add_element(const T&);         
    int getStackLength() const; 
    int getNumElement() const;
    void add_more_elements(T*, int);
    void print_top_stack() const;
    void add_element_from_new_stack(Stack<T>&, int);
    void cls();

    typedef StackIter<T> iterator;
    typedef StackIter<const T> const_iterator;

    iterator begin() {
        return iterator(pStack + index - 1);
    };
    iterator end() {
        return iterator(pStack - 1);
    };

    iterator rbegin() {
        return iterator(pStack + index - 1);
    };
    iterator rend() {
        return iterator(pStack - 1);
    };

    const_iterator begin() const {
        return const_iterator(pStack + index - 1);
    };
    const_iterator end() const {
        return const_iterator(pStack - 1);
    };
};

template <typename T>
Stack<T>::Stack(int length) :
    num_elements(length) {
    pStack = new T[num_elements];
    index = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] pStack;
}

template <typename T>
void Stack<T>::add_element(const T& value) {
    // проверяем размер стека
    if (index == num_elements) {
        increased_length();
    }
    pStack[index++] = value;
}

//Вставка несколькиx значений
template <typename T>
void Stack<T>::add_more_elements(T* array, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        add_element(array[i]);
    }
}

template <typename T>
void Stack<T>::increased_length() {
    T* buffer = new T[this->getStackLength() * 2];
    index = this->getNumElement();

    for (int i = 0; i < index; i++)
        pStack[i] = this->getPtr()[i];
    delete[] pStack;
    pStack = buffer;
}

template <typename T>
T* Stack<T>::extracting_elements(int n) {
    assert(index > n);
    T* array = new T[n - 1];

    for (int i = 0; i < n - 1; i++) {
        array[i] = this->delete_element();
    }
    return array;
}

template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& newStack, int n) {
    int otherTop = newStack.getNumElement();
    assert(n < otherTop);

    for (int i = 0; i < n; i++) {
        this->add_element(newStack.delete_element());
    }
}

template <class T>
const T& Stack<T>::search_n_element(int num) const {
    // Проверка
    assert(num <= index);
    return pStack[index - num];
}

template <class T>
void Stack<T>::print_top_stack() const {
    cout << pStack[index];
}

template <typename T>
int Stack<T>::getStackLength() const {
    return num_elements;
}

template <typename T>
T* Stack<T>::getPtr() const {
    return pStack;
}

template <typename T>
int Stack<T>::getNumElement() const {
    return index;
}

template <typename T>
T Stack<T>::delete_element() {
    assert(index > 0); 
    index = index - 1;
    return pStack[index];
}

template <typename T>
void Stack<T>::cls() {
    this->index = 0;
}