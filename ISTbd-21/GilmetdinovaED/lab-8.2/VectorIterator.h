#ifndef VECTORITERATOR_H_INCLUDED
#define VECTORITERATOR_H_INCLUDED

#include <iterator>


template <typename T>
class VectorIterator : public std::iterator<std::input_iterator_tag, T>
 {
private:
    T* ptr;
public:
    VectorIterator(const VectorIterator& it) : ptr(it.ptr) {}
    VectorIterator(T* ptr) : ptr(ptr) {}



    bool operator==(VectorIterator const& other) const {
        return ptr == other.ptr;
    }


    bool operator!=(VectorIterator const& other) const {
        return ptr != other.ptr;
    }


    typename VectorIterator::reference operator*() const {
        return *ptr;
    }


    VectorIterator& operator++() {
        ++ptr;
        return *this;
    }
};


#endif // VECTORITERATOR_H_INCLUDED
