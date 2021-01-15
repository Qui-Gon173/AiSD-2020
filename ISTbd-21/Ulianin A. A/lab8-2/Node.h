#pragma once

typedef unsigned char byte_t;


class Node
{
public:

    Node* pNext; // указатель на следующий элемент
    byte_t data;  // поле данных

    /// конструктор класса
    Node(byte_t data = 0, Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};
