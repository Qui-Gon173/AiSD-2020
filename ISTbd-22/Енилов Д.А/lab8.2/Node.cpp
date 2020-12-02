#pragma once

class Node
    {
        friend class my_iterator;
    public:
        Node *pNext;
        Node *pPrev;
        unsigned long field_data;
        Node(unsigned long field_data=123,Node *pPrev=nullptr,Node *pNext=nullptr)
        {
            this->field_data=field_data;
            this->pPrev=pPrev;
            this->pNext=pNext;
        }
    };