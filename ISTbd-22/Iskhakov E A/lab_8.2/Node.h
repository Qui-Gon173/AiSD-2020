#pragma once

typedef unsigned char byte_t;


class Node
{
public:

    Node* pNext; // ��������� �� ��������� �������
    byte_t data;  // ���� ������

    /// ����������� ������
    Node(byte_t data = 0, Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
    }
};