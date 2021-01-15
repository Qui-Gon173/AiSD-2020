#pragma once

#include <iterator>


template <typename T>
class FibIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    size_t n;
    size_t iter_count = 1;

public:
    FibIterator(
        size_t n,
        size_t iter_count
    ) : n(n), iter_count(iter_count) {}

    bool operator!=(FibIterator const& other) const {
        return this->iter_count != other.iter_count;
    }

    bool operator==(FibIterator const& other) const {
        return this->iter_count == other.iter_count;
    }

    typename FibIterator::reference operator*() const {
        T a = 1;
        T b = 1;

        for (size_t i = 3; i <= this->iter_count; i++) {
            T next_b = a + b;
            a = b;
            b = next_b;
        }

        T* pvalue = &b;
        return *pvalue;
    }

    FibIterator& operator++() {
        this->n++;
        this->iter_count++;
        return *this;
    }
};


template <typename T>
class FibGenerator {
private:
    size_t n;

public:
    using iterator = FibIterator<T>;
    using const_iterator = FibIterator<const T>;

    FibGenerator(size_t n) : n(n) {}

    size_t len() {
        return this->n;
    }

    iterator begin() {
        return iterator(this->n, 1);
    }

    iterator end() {
        return iterator(this->n, this->n + 1);
    }

    const_iterator begin() const {
        return iterator(this->n, 1);
    }

    const_iterator end() const {
        return iterator(this->n, this->n + 1);
    }
};