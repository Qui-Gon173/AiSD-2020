#pragma once

#include <iterator>
#include "Stack.h"
#include "ArithmeticalGenerator.h"

template<typename T>
class StackIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T* ptr;

public:
    StackIterator(T* ptr) : ptr(ptr) {};
    StackIterator(const StackIterator& iter) : ptr(iter.ptr) {};

    bool operator!=(StackIterator const& other) const;
    typename StackIterator::reference operator*() const;
    bool operator==(StackIterator const& other) const;
    StackIterator& operator++();
};

template<typename T>
bool StackIterator<T>::operator!=(StackIterator const& other) const {
    return ptr != other.ptr;
}

template<typename T>
typename StackIterator<T>::reference StackIterator<T>::operator*() const {
    return *ptr;
}

template<typename T>
StackIterator<T>& StackIterator<T>::operator++() {
    --ptr;
    return *this;
}

template<typename T>
bool StackIterator<T>::operator==(StackIterator const& other) const {
    return ptr == other.ptr;
}