#pragma once

class Node
    {
        friend class my_iterator;
    public:
        Node *pNext;
        Node *pPrevious;
        unsigned int field_data;
        Node(unsigned int field_data = 123,Node *pPrevious = nullptr,Node *pNext = nullptr)
        {
            this->field_data = field_data;
            this->pPrevious = pPrevious;
            this->pNext = pNext;
        }
    };
