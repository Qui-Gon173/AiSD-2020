#pragma once

#include <iostream>
using namespace std;

class List
{
public:
    List();
    ~List();

    void add_element_from_back(unsigned int data);
    int getLength() { return length; }
    void add_element_by_index(unsigned int data, int index);
    void delete_element_by_index(int index);
    void delete_first_element();
    void cls();
    void search_index(unsigned int value);
    void print();
    unsigned int sum();
    unsigned int avarage();
    unsigned int min();
    unsigned int max();

private:
    class Node
    {
    public:

        Node* pNext;
        unsigned int data;

        Node(unsigned int data = NULL, Node* pNext = NULL)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int length;
    Node* head; 
};

List::List()
{
    this->length = 0;
    this->head = NULL;
}

List::~List()
{
}

void List::add_element_from_back(unsigned int data) {

    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node* current = this->head;

        while (current->pNext != NULL)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);

    }

    length++;
}

void List::add_element_by_index(unsigned int data, int index)
{
    if (index == 0)
    {
        head = new Node(data, head);
        length++;
    }
    else
    {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext);

        previous->pNext = newNode;

        length++;
    }
}

void List::delete_first_element()
{
    Node* temp = this->head;
    head = head->pNext;
    delete temp;
    length--;
}

void List::delete_element_by_index(int index)
{
    if (index == 0)
    {
        delete_first_element();
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        length--;
    }
}

void List::search_index(unsigned int value)
{
    Node* current = this->head;
    int i = 0;
    if ((current->data) == value)
    {
        cout << "\nИндекс элемента: " << i << endl;
    }
    else
    {
        while (((current->data) != value) && (i != length - 1))
        {
            current = current->pNext;
            i++;
        }
        if (i != 0)
            cout << i << endl;
    }

}

void List::cls()
{
    while (length)
    {
        delete_first_element();
    }
}

void List::print()
{
    Node* current = this->head;

    for (int i = 0; i < length; i++)
    {
        cout << (int)current->data << ' ';

        current = current->pNext;
    }
    cout << endl;
}

unsigned int List::sum()
{
    unsigned int sum = 0;
    Node* current = this->head;
    for (int i = 0; i < length; i++)
    {
        sum += current->data;
        current = current->pNext;
    }
    return sum;
}

unsigned int List::avarage()
{
    unsigned int avarage_value;
    avarage_value = sum() / getLength();
    return avarage_value;
}

unsigned int List::min()
{
    Node* current = this->head;
    unsigned int min = current->data;
    for (int i = 0; i < length; i++)
    {
        if (current->data < min)
            min = current->data;
        current = current->pNext;
    }
    return min;
}

unsigned int List::max()
{
    Node* current = this->head;
    unsigned int max = current->data;
    for (int i = 0; i < length; i++)
    {
        if (current->data > max)
            max = current->data;
        current = current->pNext;
    }
    return max;
}