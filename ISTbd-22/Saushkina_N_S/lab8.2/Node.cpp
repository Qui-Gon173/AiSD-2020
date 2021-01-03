#pragma once

class Node//узел расширяемого списка
    {
        friend class my_iterator;
    public:
        Node *pNext;
        int data;
        Node(int data=0,Node *pNext=nullptr)
        {
            this->data=data;
            this->pNext=pNext;
        }
    };