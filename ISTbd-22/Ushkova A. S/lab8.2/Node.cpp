#pragma once

class Node
    {
        friend class my_iterator;
    public:
        Node *pNext;
         unsigned int data;
         Node(unsigned int data = 133, Node *pNext = nullptr)
         {
             this->data=data;
             this->pNext=pNext;
         }
    };
