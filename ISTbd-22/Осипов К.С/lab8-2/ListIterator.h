#pragma once
#include "DoubleList.h"

template <typename T>
class ListIterator
{
public:

    friend class DoubleList<T>;

    ListIterator(DoubleList<T>::Node<T>* first) : cur(first)
    {

    }

    ListIterator operator++()
    {
        cur = cur->ptr_next;
        return *this;
    }
    ListIterator operator--()
    {
        cur = cur->ptr_prev;
        return *this;
    }

    bool operator!=(const ListIterator& it) { return cur != it.cur; }
    bool operator==(const ListIterator& it) { return cur == it.cur; }
    
    T& operator*(ListIterator<T>)
    {
        return cur->data;
    }

private:

    DoubleList<T>::Node<T>* cur;
};

