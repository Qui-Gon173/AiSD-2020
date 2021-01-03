#pragma once
#include <iostream>
#include "Node.cpp"
#include "my_iterator.cpp"

using namespace std;

class List
{
 public:
    List();
    ~List();
    //добавление в конец
    void push_back(unsigned int data);
    //Счетчик
    int GetSize(){return size;}
    //Возврат значение по индексу
    unsigned int& operator[](const int index);
    //Добавление элемента в начало списка
    void push_front(unsigned int data);
    //Добавление элемента по заданному индексу
    void insert(unsigned int data, int index);
    //удаление элемента в списке по указанному индексу
	void removeAt(int index);
    //удаление первого элемента в списке
	void pop_front();
    //Очистить список
	void clear();
    //Вывод индекса по определенному значению
    void  findByIndex(unsigned int value);
    //Печать списка
    void printList();
    //Сумма всех значений
    unsigned int summ();
    //Среднее значение
    unsigned int average();
    //Минимальное значение
    unsigned int min();
    //Максимальное значение
    unsigned int max();
   

 private:
        int size;
        Node *head;
        Node *last;
 public:
    ////////////////////////////////////////Explosion ZONE
    //Опрпеделяем типы и методы begin и end
    typedef my_iterator const_iterator;
    const_iterator begin() const{
        return const_iterator(head);
    };
    const_iterator end() const{
        return const_iterator(nullptr);
    };
};

