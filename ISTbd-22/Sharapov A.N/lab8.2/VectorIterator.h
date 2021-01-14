#pragma once

#include <iterator>

template <typename T>
class VectorIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T* ptr;
public:
    VectorIterator(const VectorIterator& it) : ptr(it.ptr) {}
    VectorIterator(T* ptr) : ptr(ptr) {}

    bool operator!=(VectorIterator const& other) const {
        return this->ptr != other.ptr;
    }

    bool operator==(VectorIterator const& other) const {
        return this->ptr == other.ptr;
    }

    typename VectorIterator::reference operator*() const {
        return *this->ptr;
    }

    VectorIterator& operator++() {
        ++this->ptr;
        return *this;
    }
};
 