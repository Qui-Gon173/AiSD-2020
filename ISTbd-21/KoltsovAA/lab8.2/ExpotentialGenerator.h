#pragma once

#include <iterator>
#include <cmath> 


template <typename T>
class ExpotentialIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T base;
    T exp;
    T step;
    size_t iter_count = 0;
    T* value;

public:
    ExpotentialIterator(
        T base,
        T exp,
        T step,
        size_t iter_count
    ) : base(base), exp(exp), step(step), iter_count(iter_count) {
        value = new T;
    }

    ~ExpotentialIterator() {
        delete value;
    }

    bool operator!=(ExpotentialIterator const& other) const {
        return this->iter_count != other.iter_count;
    }

    bool operator==(ExpotentialIterator const& other) const {
        return this->iter_count == other.iter_count;
    }

    typename ExpotentialIterator::reference operator*() const {
        // slow but... I don't care.
        *this->value = 1;
        for (size_t i = 0; i < this->exp; i++) {
            *this->value *= this->base;
        }

        return *this->value;
    }

    ExpotentialIterator& operator++() {
        this->exp += this->step;
        this->iter_count++;
        return *this;
    }
};


template <typename T>
class ExpotentialGenerator {
private:
    T base;
    T exp;
    T step;
    size_t max_steps;

public:
    using iterator = ExpotentialIterator<T>;
    using const_iterator = ExpotentialIterator<const T>;

    ExpotentialGenerator(
        T base,
        T exp,
        T step,
        size_t max_steps
    ) : base(base), exp(exp), step(step), max_steps(max_steps) {    
}

    size_t len() {
        return this->max_steps;
    }

    iterator begin() {
        return iterator(base, exp, step, 0);
    }

    iterator end() {
        return iterator(base, exp, step, max_steps);
    }

    const_iterator begin() const {
        return iterator(base, exp, step, 0);
    }

    const_iterator end() const {
        return iterator(base, exp, step, max_steps);
    }
};
