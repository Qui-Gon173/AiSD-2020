#pragma once

typedef unsigned char long_t;


class Node
{
public:

    Node* pNext;
    long_t data;
    Node(long_t data = 0, Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};
