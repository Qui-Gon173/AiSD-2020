#include <cassert>
#include <iostream>


template <typename T>
class Stack
{
private:
    T* stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int index;                          // номер текущего элемента стека
    void increased_length();
public:
    Stack(int = 64);                  // по умолчанию размер стека равен 10 элементам
    ~Stack();                         // деструктор

    void add_element(const T&);     // поместить элемент в вершину стека
    T delete_element();                   // удалить элемент из вершины стека
    void print();         // вывод стека на экран
    const T& search_n_element(int = 1) const; // n-й элемент от вершины стека
    int getStackLength() const;  // получить размер стека
    T* getPtr() const;         // получить указатель на стек
    int getNumElement() const;        // получить номер текущего элемента в стеке
    void add_more_elements(T*, size_t);         //Вставка несколькиз значений
    void print_top_stack() const;            // Вывод вершины
    void add_element_from_new_stack(Stack<T>&, int); // Функция вставки в новый экземпляр значений из другого стека
    T* extracting_elements(int);
    T sum();
    T max();
    T min();
    T average();
    void cls();
};

// реализация методов шаблона класса Stack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    index = 0; // инициализируем текущий элемент нулем;
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
void Stack<T>::add_element(const T& value)
{
    // проверяем размер стека
    if (index == size) {
        increased_length();
    }
    stackPtr[index++] = value; // помещаем элемент в стек
}

//Вставка несколькиз значений
template <typename T>
void Stack<T>::add_more_elements(T* array, size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        add_element(array[i]);
    }
}

// Увеличение размера стека
template <typename T>
void Stack<T>::increased_length() {
    T* buffer = new T[this->getStackLength() * 2];
    index = this->getNumElement();

    for (int i = 0; i < index; i++)
        stackPtr[i] = this->getPtr()[i];
    delete[] stackPtr;
    stackPtr = buffer;
}

// функция извлечения n элементов
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

// Функция вставки в новый экземпляр значений из другого стека
template <typename T>
void Stack<T>::add_element_from_new_stack(Stack<T>& otherStack, int n)
{
    int otherTop = otherStack.getNumElement();
    assert(n < otherTop);

    for (size_t i = 0; i < n; i++) {
        this->add_element(otherStack.delete_element());
    }
}

// функция возвращает n-й элемент от вершины стека
template <class T>
const T& Stack<T>::search_n_element(int nom) const
{
    // Проверка
    assert(nom <= index);

    return stackPtr[index - nom]; // вернуть n-й элемент стека
}

//Вывод вершины
//template <class T>
//void Stack<T>::print_top_stack() const
//{
//    std::cout << stackPtr[index];
//}

// Вывод стека на экран
//template <typename T>
//void Stack<T>::print()
//{
//    for (int i = index - 1; i >= 0; i--)
//        std::cout << stackPtr[i] << " ";
//    std::cout << std::endl;
//}

// вернуть размер стека
template <typename T>
int Stack<T>::getStackLength() const
{
    return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
T* Stack<T>::getPtr() const
{
    return stackPtr;
}

// вернуть размер стека
template <typename T>
int Stack<T>::getNumElement() const
{
    return index;
}

// функция удаления элемента из стека
template <typename T>
T Stack<T>::delete_element()
{
    // проверяем размер стека
    assert(index > 0); // номер текущего элемента должен быть больше 0

    return stackPtr[--index]; // удаляем элемент из стека
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
