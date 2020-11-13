#pragma once

#include <cassert>
#include <iostream>
#include "StackIterator.h"


template <typename T>
class Stack {
private:
    T* stackPtr;                      // указатель на стек
    int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
    void resize();
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    Stack(ArithmeticalGenerator<T>& gen) {
        size = gen.len() * 2;
        stackPtr = new T[size];
        for (T& item : gen) {
            push(item);
        }
    }
    ~Stack();                         // деструктор

    void push(const T&);     // поместить элемент в вершину стека
    T pop();                   // удалить элемент из вершины стека
    const T& Peek(int = 1) const; // n-й элемент от вершины стека
    int getStackSize() const;  // получить размер стека
    T* getPtr() const;         // получить указатель на стек
    int getTop() const;        // получить номер текущего элемента в стеке
    void pushSev(T*, size_t);         //Вставка нескольких значений
    void printTop() const;            // Вывод вершины
    void pushFromDifStack(Stack<T>&, int); // Функция вставки в новый экземпляр значений из другого стека
    T* popSev(int);
    T min();
    T max();
    void clear();

    typedef StackIterator<T> iterator;
    typedef StackIterator<const T> const_iterator;

    iterator begin() {
        return iterator(stackPtr + top - 1);
    };
    iterator end() {
        return iterator(stackPtr - 1);
    };

    iterator rbegin() {
        return iterator(stackPtr + top - 1);
    };
    iterator rend() {
        return iterator(stackPtr - 1);
    };

    const_iterator begin() const {
        return const_iterator(stackPtr + top - 1);
    };
    const_iterator end() const {
        return const_iterator(stackPtr - 1);
    };
};
// реализация методов шаблона класса Stack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) {
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack() {
    delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
void Stack<T>::push(const T& value) {
    // проверяем размер стека
    if (top == size) {
        resize();
    }
    stackPtr[top++] = value; // помещаем элемент в стек
}

//Вставка несколькиз значений
template <typename T>
void Stack<T>::pushSev(T* array, size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        push(array[i]);
    }
}

// Увеличение размера стека
template <typename T>
void Stack<T>::resize() {
    T* buffer = new T[this->getStackSize() * 2];
    top = this->getTop();

    for (int ix = 0; ix < top; ix++)
        stackPtr[ix] = this->getPtr()[ix];
    delete[] stackPtr;
    stackPtr = buffer;
}

// функция извлечения n элементов
template <typename T>
T* Stack<T>::popSev(int n) {
    assert(top > n);
    T* array = new T[n - 1];

    for (size_t i = 0; i < n - 1; i++) {
        array[i] = this->pop();
    }
    return array;
}

// Функция вставки в новый экземпляр значений из другого стека
template <typename T>
void Stack<T>::pushFromDifStack(Stack<T>& otherStack, int n) {
    int otherTop = otherStack.getTop();
    assert(n < otherTop);

    for (size_t i = 0; i < n; i++) {
        this->push(otherStack.pop());
    }
}

// функция возвращает n-й элемент от вершины стека
template <class T>
const T& Stack<T>::Peek(int nom) const {
    // Проверка
    assert(nom <= top);

    return stackPtr[top - nom]; // вернуть n-й элемент стека
}

//Вывод вершины
template <class T>
void Stack<T>::printTop() const {
    std::cout << stackPtr[top];
}



// вернуть размер стека
template <typename T>
int Stack<T>::getStackSize() const {
    return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
T* Stack<T>::getPtr() const {
    return stackPtr;
}

// вернуть размер стека
template <typename T>
int Stack<T>::getTop() const {
    return top;
}

// функция удаления элемента из стека
template <typename T>
T Stack<T>::pop() {
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0

    return stackPtr[--top]; // удаляем элемент из стека
}

template <typename T>
void Stack<T>::clear() {
    this->top = 0;
}