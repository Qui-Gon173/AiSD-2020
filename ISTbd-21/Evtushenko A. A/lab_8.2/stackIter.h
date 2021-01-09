#pragma once

#include <iterator>
#include "stack.h"
#include "generator.h"

template<typename T>
class StackIter : public std::iterator<std::input_iterator_tag, T> {
private:
    T* ptr;

public:
    StackIter(T* ptr) : ptr(ptr) {};
    StackIter(const StackIter& iter) : ptr(iter.ptr) {};

    bool operator!=(StackIter const& other) const;
    typename StackIter::reference operator*() const;
    bool operator==(StackIter const& other) const;
    StackIter& operator++();
};

template<typename T>
bool StackIter<T>::operator!=(StackIter const& other) const {
    return ptr != other.ptr;
}

template<typename T>
typename StackIter<T>::reference StackIter<T>::operator*() const {
    return *ptr;
}

template<typename T>
StackIter<T>& StackIter<T>::operator++() {
    --ptr;
    return *this;
}

template<typename T>
bool StackIter<T>::operator==(StackIter const& other) const {
    return ptr == other.ptr;
}