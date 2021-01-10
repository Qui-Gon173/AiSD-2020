#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Steck
{
private:
    T* St;                      
    const int size;                   
    int curr;         
public:
    Steck(int = 5);                  
    
    ~Steck();                         

    void push(const T&);     
    T pop();                 
    void clear();
    const T& Peek(int = 1) const; 

    int getSize() const;  
    T* getSt() const;     
    int getNum() const;        
    
    void pushEnum(T*, size_t);         
    void printCurr() const;            
    void printSteck();         
    void pushFromDifStack(Steck<T>&, int); 

    T* popEnum(int);
    T summa();
    T avg();
    T MaxElement();
    T MinElement();
   
};

template <typename T>
Steck<T>::Steck(int max) :
    size(max) 
{
    St = new T[size]; 
    curr = 0; 
}

template <typename T>
Steck<T>::~Steck()
{
    delete[] St; 
}

template <typename T>
void Steck<T>::push(const T& x)
{
    assert(curr < size);
    St[curr++] = x; 
}

template <typename T>
T Steck<T>::pop()
{
    assert(curr > 0);
    return St[--curr];
}

template <typename T>
void Steck<T>::clear() {
    this->curr = 0;
}

template <class T>
const T& Steck<T>::Peek(int x) const
{
    assert(x <= curr);
    return St[curr - x];
}

template <typename T>
int Steck<T>::getSize() const
{
    return size;
}

template <typename T>
T* Steck<T>::getSt() const
{
    return St;
}

template <typename T>
int Steck<T>::getNum() const
{
    return curr;
}

template <typename T>
void Steck<T>::pushEnum(T* arr, size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        push(arr[i]);
    }
}

template <typename T>
T* Steck<T>::popEnum(int n)
{
    assert(curr > n);
    T* array = new T[n - 1];

    for (size_t i = 0; i < n - 1; i++) {
        array[i] = this->pop();
    }
    return array;
}

template <class T>
void Steck<T>::printCurr() const
{
    cout << St[curr];
}

template <typename T>
void Steck<T>::printSteck()
{
    for (int i = curr - 1; i >= 0; i--) {
        cout << St[i] << " ";
    }
}

template <typename T>
void Steck<T>::pushFromDifStack(Steck<T>& other, int n)
{
    int otherTop = other.getNum();
    assert(n < otherTop);

    for (size_t i = 0; i < n; i++) {
        this->push(other.pop());
    }
}




template <typename T>
T Steck<T>::summa() {
    T s = 0;
    size_t i = 0;
    while (i < this->getNum()) {
        s = s + St[i];
        i++;
    }
    return s;
}

template <typename T>
T Steck<T>::avg() {
    int x = 0;
    if (this->getNum() > 0) {
        x = this->summa() / this->getNum();
    }
    return x;
}

template <typename T>
T Steck<T>::MaxElement() {
    assert(curr > 0);
    T max = St[0];
    size_t i = 0;
    while (i < this->getNum()) {
        if (max < St[i]) {
            max = St[i];
        }
        i++;
    }
    return max;
}

template <typename T>
T Steck<T>::MinElement() {
    assert(curr > 0);
    T min = St[0];
    size_t i = 0;
    while ( i < this->getNum()) {
        if (min > St[i]) {
            min = St[i];
        }
        i++;
    }
    return min;
}


