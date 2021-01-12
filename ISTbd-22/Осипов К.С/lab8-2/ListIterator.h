#pragma once
#include "DoubleList.h"

template <typename T>
class ListIterator : public iterator<input_iterator_tag, T>
{
public:

    friend class DoubleList<T>;

    ListIterator(const ListIterator& it);

    bool operator!=(ListIterator const& other) const;
    bool operator==(ListIterator const& other) const;

    typename ListIterator<T>::reference operator*() const;
    ListIterator& operator++();

private:

    Node<T>* cur;
    ListIterator(Node<T>* cur);
};

template <typename T>
ListIterator<T>::ListIterator(Node<T>* cur)
{
    this->cur = cur;
}


template <typename T>
ListIterator<T>::ListIterator(const ListIterator& it)
{
    this->cur = it.cur;
}

template <typename T>
bool ListIterator<T>::operator!=(ListIterator const& other) const
{
    return cur != other.cur;
}

template <typename T>
bool ListIterator<T>::operator==(ListIterator const& other) const
{
    return cur == other.cur;
}

template <typename T>
typename ListIterator<T>::reference ListIterator<T>::operator*() const
{
    return cur->data;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    cur = cur->ptr_next;
    return *this;
}

