#pragma once

#include <iostream>
#include <cstring>
#include <clocale>

#include "ListIter.h"
#include "Generator.h"
#include "Node.h"

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
    List(Generator&);
    ~List();

    void add_to_end(unsigned int data);

    int getSize() { return Size; }

    void add_by_index(unsigned int data, int index);

    void delete_by_index(int index);

    void delete_first_element();

    void cls();

    void search_index(unsigned int value);
private:
    int Size = 0; 
    Node* head = nullptr;
};

List::List() {}
List::List(Generator& gen) {
    for (auto& item : gen) {
        this->add_to_end(item);
    }
}

List::~List() {
}

void List::add_to_end(unsigned int data) {

    if (head == NULL)
    {
        head = new Node(data); 
    }
    else {
        Node* current = this->head;

        while (current->pNext != NULL) 
        {
            current = current->pNext;
        }
        current->pNext = new Node(data); 

    }

    Size++;
}

void List::add_by_index(unsigned int data, int index) {
    if (index == 0) {
        head = new Node(data, head);
        Size++;
    }
    else {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

void List::delete_first_element() {

    Node* temp = this->head;

    head = head->pNext; 

    delete temp;

    Size--; 

}

void List::delete_by_index(int index) {
    if (index == 0) {
        delete_first_element();
    }
    else {
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

void List::cls() {
    while (Size) {
        delete_first_element();
    }
}

void List::search_index(unsigned int value) {
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value) {
        cout << "\nIndex: " << i << endl;
    }
    else {
        while (((current->data) != value) && (i != Size - 1)) {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            cout << "\nIndex: " << i << endl;
    }

}