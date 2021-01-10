

#include <iterator>
#include "Gen.h"

template<typename T>
class Iterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T* st;

public:
    Iterator(T* st) : st(st) {};
    Iterator(const Iterator& iter) : st(iter.st) {};

    Iterator& operator++() {
        --st;
        return *this;

    }
    bool operator!=(Iterator const& other) const {
        return st != other.st;
    }
    typename Iterator::reference operator*() const {
        return *st;
    }
    bool operator==(Iterator const& other) const {
        return st == other.st;
    }
    
};

