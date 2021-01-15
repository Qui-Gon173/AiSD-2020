#pragma once

#include <iostream>
#include <cstring>
#include <clocale>

#include "ListIterator.h"
#include "RandomGenerator.h"
#include "Node.h"

typedef unsigned char byte_t;

using namespace std;

class List
{
public:
    using iterator = ListIterator;
    using const_iterator = ListIterator;

    iterator begin() {
        return iterator(0, this->head);
    }
    iterator end() {
        return iterator(Size, this->head);
    }

    const_iterator cbegin() const {
        return iterator(0, this->head);

    }
    const_iterator cend() const {
        return iterator(Size, this->head);
    }

    List();
    List(RandomGenerator&);
    ~List();

    ///добавление в конец
    void push_back(byte_t data);

    ///cчетчик
    int GetSize() { return Size; }

    ///Добавление элемента по заданному индексу
    void insert(byte_t data, int index);

    ///удаление элемента в списке по указанному индексу
    void removeAt(int index);

    ///удаление первого элемента в списке
    void pop_front();

    ///очистить список
    void clear();

    ///вывод индекса по определенному значению
    void poisk_index(byte_t value);
private:
    int Size = 0;   // количество эл-ов в списке
    Node* head = nullptr; // указатель на начало списка
};

/// конструктор для создания объекта
List::List() {}
List::List(RandomGenerator& gen) {
    for (auto& item : gen) {
        this->push_back(item);
    }
}

/// деструктор
List::~List() {
}


///добавление в конец
void List::push_back(byte_t data) {

    if (head == NULL) // если список пуст
    {
        head = new Node(data); // создаем элемент и присваиваем началу списка его значение
    } else {
        Node* current = this->head; // создаем временный указатель на объект и присваиваем ему адрес начала списка

        while (current->pNext != NULL)  // ищем адрес последнего элемента списка
        {
            current = current->pNext;
        }
        current->pNext = new Node(data); // в поле, хранящее адрес следующего объекта, присваиваем адрес нового элемента

    }

    Size++; // увеличиваем размер списка
}

///Добавление элемента по заданному индексу
void List::insert(byte_t data, int index) {
    /// проверка, если список пуст
    if (index == 0) {
        head = new Node(data, head);
        Size++;
    } else {
        /// присваивание новому указателю указателя head. 
        /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
        Node* previous = this->head;

        /// поиск позиции
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        /// создаём новый узел
        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

///удаление первого элемента в списке
void List::pop_front() {

    Node* temp = this->head;

    head = head->pNext; //перемещаем указатель на один элемент вперед

    delete temp; //удаляем элемент

    Size--; //изменяем число элементов в списке

}

///удаление элемента в списке по указанному индексу
void List::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        /// присваивание новому указателю указателя head. 
        /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
        Node* previous = this->head;

        //поиск указателя на искомый элемент
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }


        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

/// очистка списка
void List::clear() {
    /// пока список не кончится удаляем первый объект
    while (Size) {
        pop_front();
    }
}

///вывод индекса по определенному значению
void List::poisk_index(byte_t value) {
    /// присваивание новому указателю указателя head. 
    /// присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value) {
        cout << "\nIndex: " << i << endl;
    } else {
        while (((current->data) != value) && (i != Size - 1)) {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            cout << "\nIndex: " << i << endl;
    }

}
