#pragma once

#include <iostream>
#include <cstring>
#include <clocale>

#include "ListIterator.h"
#include "Generator.h"
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
    List(ExponentialFunctionGenerator&);
    ~List();

    ///���������� � �����
    void push_back(byte_t data);

    ///c������
    int GetSize() { return Size; }

    ///���������� �������� �� ��������� �������
    void insert(byte_t data, int index);

    ///�������� �������� � ������ �� ���������� �������
    void removeAt(int index);

    ///�������� ������� �������� � ������
    void pop_front();

    ///�������� ������
    void clear();

    ///����� ������� �� ������������� ��������
    void poisk_index(byte_t value);
private:
    int Size = 0;   // ���������� ��-�� � ������
    Node* head = nullptr; // ��������� �� ������ ������
};

/// ����������� ��� �������� �������
List::List() {}
List::List(ExponentialFunctionGenerator& gen) {
    for (auto& item : gen) {
        this->push_back(item);
    }
}

/// ����������
List::~List() {
}


///���������� � �����
void List::push_back(byte_t data) {

    if (head == NULL) // ���� ������ ����
    {
        head = new Node(data); // ������� ������� � ����������� ������ ������ ��� ��������
    }
    else {
        Node* current = this->head; // ������� ��������� ��������� �� ������ � ����������� ��� ����� ������ ������

        while (current->pNext != NULL)  // ���� ����� ���������� �������� ������
        {
            current = current->pNext;
        }
        current->pNext = new Node(data); // � ����, �������� ����� ���������� �������, ����������� ����� ������ ��������

    }

    Size++; // ����������� ������ ������
}

///���������� �������� �� ��������� �������
void List::insert(byte_t data, int index) {
    /// ��������, ���� ������ ����
    if (index == 0) {
        head = new Node(data, head);
        Size++;
    }
    else {
        /// ������������ ������ ��������� ��������� head. 
        /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
        Node* previous = this->head;

        /// ����� �������
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        /// ������ ����� ����
        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        Size++;
    }
}

///�������� ������� �������� � ������
void List::pop_front() {

    Node* temp = this->head;

    head = head->pNext; //���������� ��������� �� ���� ������� ������

    delete temp; //������� �������

    Size--; //�������� ����� ��������� � ������

}

///�������� �������� � ������ �� ���������� �������
void List::removeAt(int index) {
    if (index == 0) {
        pop_front();
    }
    else {
        /// ������������ ������ ��������� ��������� head. 
        /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
        Node* previous = this->head;

        //����� ��������� �� ������� �������
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }


        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

/// ������� ������
void List::clear() {
    /// ���� ������ �� �������� ������� ������ ������
    while (Size) {
        pop_front();
    }
}

///����� ������� �� ������������� ��������
void List::poisk_index(byte_t value) {
    /// ������������ ������ ��������� ��������� head. 
    /// ������������ ����������� ��� ����, ����� �� �������� ��������� �� ������� ������
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