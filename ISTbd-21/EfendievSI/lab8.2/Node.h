#pragma once

class Node
{
public:

    Node* pNext;
    unsigned int data; 

    /// ����������� ������
    Node(unsigned int data = 0, Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};