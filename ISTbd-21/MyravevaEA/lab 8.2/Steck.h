#pragma once

#include <cassert>
#include <iostream>
#include "Iterator.h"


template <typename T>
class Steck {
private:
    T* St;                     
    int size;                   
    int curr;                   
public:
    Steck(int = 5);                 
    Steck(Gen<T>& gen) {
        size = gen.len() * 2;
        St = new T[size];
        for (T& item : gen) {
            push(item);
        }
    }

    ~Steck();                         

    typedef Iterator<T> iterator;
    typedef Iterator<const T> const_iterator;

    iterator begin() {
        return iterator(St + curr - 1);
    };
    iterator end() {
        return iterator(St - 1);
    };

    iterator rbegin() {
        return iterator(St + curr - 1);
    };
    iterator rend() {
        return iterator(St - 1);
    };

    const_iterator begin() const {
        return const_iterator(St + curr - 1);
    };
    const_iterator end() const {
        return const_iterator(St - 1);
    };
    void push(const T&);     
    T pop();                 
    const T& Peek(int = 1) const; 
    void clear();
    
    int getSize() const;  
    T* getSt() const;     
    int getNum() const;   
    
    void pushEnum(T*, size_t);   
    void printCurr() const;      
    void pushFromDifStack(Steck<T>&, int); 

    T* popEnum(int);
    

  
};

template <typename T>
Steck<T>::Steck(int max) :
    size(max) 
{
    St = new T[size]; 
    curr = 0; 
}

template <typename T>
Steck<T>::~Steck() {
    delete[] St; 
}

template <typename T>
void Steck<T>::push(const T& x) {
    assert(curr < size);
    St[curr++] = x;
}

template <typename T>
T Steck<T>::pop() {
    assert(curr > 0);
    return St[--curr];
}

template <class T>
const T& Steck<T>::Peek(int x) const
{
    assert(x <= curr);
    return St[curr - x];
}


template <typename T>
void Steck<T>::clear() {
    this->curr = 0;
}

template <typename T>
int Steck<T>::getSize() const {
    return size;
}

template <typename T>
T* Steck<T>::getSt() const {
    return St;
}

template <typename T>
int Steck<T>::getNum() const {
    return curr;
}

template <typename T>
void Steck<T>::pushEnum(T* array, size_t arrSize) {
    size_t i = 0;
    while( i < arrSize) {
        push(array[i]);
        i++;
    }
}








template <class T>
void Steck<T>::printCurr() const {
    std::cout << St[curr] << " ";
}

template <typename T>
void Steck<T>::pushFromDifStack(Steck<T>& other, int n) {
    int otherTop = other.getNum();
    assert(n < otherTop);
    size_t i = 0;
    while (i < n) {
        this->push(other.pop());
        i++;
    }
}

template <typename T>
T* Steck<T>::popEnum(int n) {
    assert(curr > n);
    T* array = new T[n - 1];
    size_t i = 0;
    while (i < n - 1) {
        array[i] = this->pop();
        i++;
    }
    return array;
}




