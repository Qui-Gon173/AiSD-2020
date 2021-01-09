#include <cassert>
#include <iostream>


template <typename T>
class Stack
{
private:
    T* stackPtr;                 
    const int size;              
    int index;                         
    void increased_length();
public:
    Stack(int = 64);               
    ~Stack();                       

    void add_element(const T&);    
    T delete_element();                  
    void print();       
    const T& search_n_element(int = 1) const;
    int getStackLength() const; 
    T* getPtr() const;   
    int getNumElement() const;       
    void add_more_elements(T*, size_t);        
    void print_top_stack() const;            
    void add_element_from_new_stack(Stack<T>&, int); 
    T* extracting_elements(int);
    T sum();
    T max();
    T min();
    T average();
    void cls();
};


template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) 
{
    stackPtr = new T[size]; 
    index = 0; 
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; 
}

template <typename T>
void Stack<T>::add_element(const T& value)
{
    if (index == size) {
        increased_length();
    }
    stackPtr[index++] = value; 
}

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
T* Stack<T>::extracting_elements(int n)
{
    assert(index > n);
    T* array = new T[n - 1];

    for (size_t i = 0; i < n - 1; i++) {
        array[i] = this->delete_element();
    }
    return array;
}

template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& otherStack, int n)
{
    int otherTop = otherStack.getNumElement();
    assert(n < otherTop);

    for (size_t i = 0; i < n; i++) {
        this->add_element(otherStack.delete_element());
    }
}

template <class T>
const T& Stack<T>::search_n_element(int nom) const
{
    assert(nom <= index);

    return stackPtr[index - nom]; 
}

template <typename T>
int Stack<T>::getStackLength() const
{
    return size;
}

template <typename T>
T* Stack<T>::getPtr() const
{
    return stackPtr;
}

template <typename T>
int Stack<T>::getNumElement() const
{
    return index;
}

template <typename T>
T Stack<T>::delete_element()
{
    assert(index > 0);

    return stackPtr[--index]; 
}

template <typename T>
T Stack<T>::sum() {
    T result = 0;
    for (size_t i = 0; i < this->getNumElement(); i++) {
        result += stackPtr[i];
    }
    return result;
}

template <typename T>
T Stack<T>::average() {
    return this->getNumElement() ? this->sum() / this->getNumElement() : 0;
}

template <typename T>
T Stack<T>::min() {
    assert(index > 0);
    T min = stackPtr[0];
    for (size_t i = 0; i < this->getNumElement(); i++) {
        if (min > stackPtr[i]) min = stackPtr[i];
    }
    return min;
}

template <typename T>
T Stack<T>::max() {
    assert(index > 0);
    T max = stackPtr[0];
    for (size_t i = 0; i < this->getNumElement(); i++) {
        if (max < stackPtr[i]) max = stackPtr[i];
    }
    return max;
}

template <typename T>
void Stack<T>::cls() {
    this->index = 0;
}
#pragma once
