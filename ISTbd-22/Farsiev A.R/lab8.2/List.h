#include <iostream>
#include <cstring>
#include <clocale>
#include "ListIterator.h"
#include "RandomGenerator.h"
#include "Node.h"
#pragma once

typedef unsigned char long_t;

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

    void push_back(long_t data);

    int GetSize() { return Size; }

    void insert(long_t data, int index);

    void removeAt(int index);

    void pop_front();

    void clear();

    void poisk_index(long_t value);
private:
    int Size = 0;
    Node* head = nullptr;
};

List::List() {}
List::List(RandomGenerator& gen) {
    for (auto& item : gen) {
        this->push_back(item);
    }
}

List::~List() {
}

void List::push_back(long_t data) {

    if (head == NULL)
    {
        head = new Node(data);
    } else {
        Node* current = this->head;

        while (current->pNext != NULL)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);

    }

    Size++;
}

void List::insert(long_t data, int index) {
    if (index == 0) {
        head = new Node(data, head);
        Size++;
    } else {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

void List::pop_front() {

    Node* temp = this->head;

    head = head->pNext;

    delete temp;

    Size--;
}

void List::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

void List::clear() {
    while (Size) {
        pop_front();
    }
}

void List::poisk_index(long_t value) {
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
